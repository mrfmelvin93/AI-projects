# Face Recognition

# Importing the libraries
import cv2
import serial

# Loading the cascades
face_cascade = cv2.CascadeClassifier('Haarcascades/haarcascade_frontalface_default.xml')
color = (0, 0, 255)
scale = 0.4
thickness = cv2.FILLED
margin = 2

#open serial terminal
ser = serial.Serial('COM10')  # open serial port

# Defining a function that will do the detections
def detect(gray, frame):
    faces = face_cascade.detectMultiScale(gray, 1.3, 5)
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (255, 0, 0), 4)
        cv2.putText(frame, "Melvin", (x, y-20), cv2.FONT_HERSHEY_SIMPLEX, scale, color, 1, cv2.LINE_AA)
        roi_gray = gray[y:y+h, x:x+w]
        roi_color = frame[y:y+h, x:x+w]
        print(x,y,w,h)
        ser.write(b'1')
        return frame
    ser.write(b'2')
    txta = "without loop"
    print(txta)
    return frame

# Doing some Face Recognition with the webcam
video_capture = cv2.VideoCapture(0)
while True:
    _, frame = video_capture.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    canvas = detect(gray, frame)
    cv2.imshow('Video', canvas)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
video_capture.release()
cv2.destroyAllWindows()
ser.close()