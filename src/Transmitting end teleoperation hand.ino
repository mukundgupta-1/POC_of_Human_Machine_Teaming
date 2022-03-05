#include <Servo.h>
#include <SPI.h>
#include <RF24.h>
#define numOfValsRec 5
#define digitsPerValRec 1

RF24 radio(5, 6);
const byte address[6] = "00001"; //either add radio address here or in pipe
int msg[5];

int valsRec[numOfValsRec];
int stringLength = numOfValsRec * digitsPerValRec +1;
int counter=0;
bool counterStart=false;
String receivedString;
//const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup() {
 Serial.begin(9600);
 radio.begin();
 radio.openWritingPipe(address);
 radio.stopListening();
}

void SendingData(){
  while(Serial.available())
  {
    char c = Serial.read();
    if(c=='$'){
      counterStart=true;
      }
      if (counterStart){
        if(counter<stringLength){
          receivedString = String(receivedString+c);
          counter++;
          }
          if(counter>=stringLength){
    
            for(int i=0;i<numOfValsRec;i++){
              int num = (i * digitsPerValRec)+1;
            
            valsRec[i]=receivedString.substring(num,num+digitsPerValRec).toInt();
            }
            receivedString = "";
            counter = 0;
            counterStart = false;
        }
    }
    
  }
}
void loop() {
            SendingData();
            for (int i = 0; i < 5; i = i + 1){
            radio.write(valsRec[i], sizeof(valsRec[i]));
            delay(5);}
} 
