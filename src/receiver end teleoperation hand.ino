#include <Servo.h>
#include <SPI.h>
#include <RF24.h>
#define numOfValsRec 5
#define digitsPerValRec 1

Servo servoThumb;
Servo servoIndex;
Servo servoMiddle;
Servo servoRing;
Servo servoPinky;

RF24 radio(9, 8);
const byte address [6] = "00001"; //either add radio address here or in pipe

//const uint64_t pipe = 0xE8E8F0F0E1LL;

struct Data_Package {
byte servoThumb;
byte servoIndex;
byte servoMiddle;
byte servoRing;
byte servoPinky;
};

void setup() { 
Serial.begin(19200);
servoThumb.attach(1);
servoIndex.attach(2);
servoMiddle.attach(3);
servoRing.attach(4);
servoPinky.attach(5);

radio.begin();
radio.openReadingPipe(1, address);
radio.startListening();
}
void loop() {
  while(radio.available()){
    Serial.println("data come ");
    int valsRec[5];
    for (int i = 0; i < 5; i = i + 1){    
    radio.read(&valsRec[i], sizeof(valsRec[i]));
    Serial.print(valsRec[i]);}
    if (valsRec[0]==1){servoThumb.write(180);}else{servoThumb.write(0);}
    if (valsRec[1]==1){servoIndex.write(180);}else{servoIndex.write(0);}
    if (valsRec[2]==1){servoMiddle.write(180);}else{servoMiddle.write(0);}
    if (valsRec[3]==1){servoRing.write(180);}else{servoRing.write(0);}
    if (valsRec[4]==1){servoPinky.write(180);}else{servoPinky.write(0);}
    
      }
        } 
