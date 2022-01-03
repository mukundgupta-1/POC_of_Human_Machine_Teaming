import cv2
from cvzone.HandTrackingModule import HandDetector
from cvzone.SerialModule import SerialObject
import cvzone
cap = cv2.VideoCapture(0)
detector = HandDetector(mode=False,maxHands=1,detectionCon=1)
mySerial = cvzone.SerialObject("COM9",9600,1)
while True
  success,img = cap.read()
  img = detector.findHands(img)
  lmlist,bbox = detector.findPosition(img)
  if lmlist:
      fingers = detector.fingersUp()
      #print(fingers)
      mySerial.sendData(fingers)
  cv2.imshow("Image",img)
  cv2.waitKey(1)