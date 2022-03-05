import cv2
from cvzone.HandTrackingModule import HandDetector
from cvzone.SerialModule import SerialObject
arduino = SerialObject("COM9",9600)

cap = cv2.VideoCapture(0)
detector = HandDetector(detectionCon=0.8, maxHands=2)

while True:
    success, img = cap.read()
    hands, img = detector.findHands(img)

    if hands:
        hand1 = hands[0]
        lmList1 = hand1["lmList"]
        bbox1 = hand1["bbox"]
        centerPoint1 = hand1["center"]
        handType1 = hand1["type"]
        fingers1 = detector.fingersUp(hand1)
        if len(hands) == 2:
            hand2 = hands[1]
            lmList2 = hand2["lmList"]
            bbox2 = hand2["bbox"]
            centerPoint2 = hand2["center"]
            handType2 = hand2["type"]

            fingers2 = detector.fingersUp(hand2)
            print(fingers1, fingers2)
        else:
            # print(len(lmList1),lmList1)
            # print(bbox1)
            # print(centerPoint1)
            print(fingers1)
            arduino.sendData(fingers1)
    cv2.imshow("Image", img)
    cv2.waitKey(1)
