__author__ = 'Tom'
'Hacking API project Thomas Easterbrook'
'To run program use python ball_tracking.py'
import cv2
import numpy as np
import argparse
import imutils
import collections

#handling parsing command line arguments
ap = argparse.ArgumentParser()
ap.add_argument("-v")
ap.add_argument("-b", "--buffer", type = int, default = 1)
args = vars(ap.parse_args())

#defining tracking colours
yellow_lower = (0, 50, 50)
yellow_upper = (10, 255, 255)
pts = collections.deque(maxlen=args["buffer"])
camera = cv2.VideoCapture(0)

#constant loop
while (1 < 2):
    (grabbed, frame) = camera.read()

    frame = imutils.resize(frame, width = 600)
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    mask = cv2.inRange(hsv, yellow_lower, yellow_upper)
    mask = cv2.erode(mask, None, iterations=2)
    mask = cv2.dilate(mask, None, iterations=2)

    cnts = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL,
                        cv2.CHAIN_APPROX_SIMPLE)[-2]
    center = None

    if len(cnts) > 0:
        c = max(cnts, key=cv2.contourArea)
        ((x,y), radius) = cv2.minEnclosingCircle(c)
        M= cv2.moments(c)
        center = (int(M["m10"] / M["m00"]), int(M["m01"] / M["m00"]))

        if radius > 10:
            cv2.circle(frame, (int(x), int(y)), int(radius), (0,0,255))
            cv2.circle(frame, center, 5, (0,0,255), -1)
            print x
            print y

    pts.appendleft(center)

    for i in xrange (1, len(pts)):
        i = 0
        if pts[i - 1] is None or pts[i] is None:
            continue

    i = 0
    thickness = int (np.sqrt(args["buffer"] / float (i + 1)) * 2.5)
    cv2.line(frame, pts [ i - 1], pts [i], (0,0,255), thickness)

    cv2.imshow ("Frame", frame)
    key = cv2.waitKey(1) & 0xFF
