# -*- coding: utf-8 -*-
import face_recognition
import cv2
from day18 import api_jinwan
from day18 import insertData

# This is a demo of running face recognition on live video from your webcam. It's a little more complicated than the
# other example, but it includes some basic performance tweaks to make things run a lot faster:
#   1. Process each video frame at 1/4 resolution (though still display it at full resolution)
#   2. Only detect faces in every other frame of video.

# PLEASE NOTE: This example requires OpenCV (the `cv2` library) to be installed only to read from your webcam.
# OpenCV is *not* required to use the face_recognition library. It's only required if you want to run this
# specific demo. If you have trouble installing it, try any of the other demos that don't require it instead.

# Get a reference to webcam #0 (the default one)
video_capture = cv2.VideoCapture(0)

# Load a sample picture and learn how to recognize it.
wangjin_image = face_recognition.load_image_file("wangjin.jpg")
wangjin_face_encoding = face_recognition.face_encodings(wangjin_image)[0]
#print '1'
#print obama_face_encoding


# Load a second sample picture and learn how to recognize it.
miyanfeng_image = face_recognition.load_image_file("minyanfeng.jpg")
miyanfeng_face_encoding = face_recognition.face_encodings(miyanfeng_image)[0]
#print '2'
#print biden_face_encoding


# Load a third sample picture and learn how to recognize it.
chenjinwan_image = face_recognition.load_image_file("chenjinwan.jpg")
chenjinwan_face_encoding = face_recognition.face_encodings(chenjinwan_image)[0]
#print '3'
#print miyanfen_face_encoding


# Load a forth sample picture and learn how to recognize it.
miyanfen1_image = face_recognition.load_image_file("boy2_1.jpg")
miyanfen1_face_encoding = face_recognition.face_encodings(miyanfen1_image)[0]
#print '4'
#print miyanfen1_face_encoding

# Create arrays of known face encodings and their names
known_face_encodings = [
    wangjin_face_encoding,
    miyanfeng_face_encoding,
    chenjinwan_face_encoding,
    miyanfen1_face_encoding
]
known_face_names = [
    "wangjing",
    "minyanfeng",
    "chenjinwan",
    "minyanfeng1"
]

# Initialize some variables
#face_locations = []
#face_encodings = []
#face_names = []
process_this_frame = True
catch=0
face_names_catch=[]

while True:
    #print(len(face_names))
    # Grab a single frame of video
    ret, frame = video_capture.read()

    # Resize frame of video to 1/4 size for faster face recognition processing
    small_frame = cv2.resize(frame, (0, 0), fx=0.25, fy=0.25)

    # Convert the image from BGR color (which OpenCV uses) to RGB color (which face_recognition uses)
    rgb_small_frame = small_frame[:, :, ::-1]

    # Only process every other frame of video to save time
    if process_this_frame and catch != 300:
        # Find all the faces and face encodings in the current frame of video
        face_locations = face_recognition.face_locations(rgb_small_frame)
        face_encodings = face_recognition.face_encodings(rgb_small_frame, face_locations)

        # save the detected names
        face_names = []

        catch = catch + 1
        print(catch)

        for face_encoding in face_encodings:
            # See if the face is a match for the known face(s)
            matches = api_jinwan.compare_faces_jinwan(known_face_encodings, face_encoding)
            name = "Unknown"

            c_d = dict(zip(known_face_names, matches))
            cd_sorted = sorted(c_d.items(), key=lambda d: d[1])

            if cd_sorted[0][1] < 0.5:
                name = cd_sorted[0][0]
            else:
                name="Unknow"
            face_names.append(name)
            face_names_catch.append(name)

    elif process_this_frame and catch%300==0:
        catch = 0
        face_names_unique = list(set(face_names_catch))
        insertData.insertNameToMysql(face_names_unique)
        print(face_names_unique)
        face_names_catch = []

    process_this_frame = not process_this_frame

    # Display the results
    for (top, right, bottom, left), name in zip(face_locations, face_names):
        # Scale back up face locations since the frame we detected in was scaled to 1/4 size
        top *= 4
        right *= 4
        bottom *= 4
        left *= 4

        # Draw a box around the face
        cv2.rectangle(frame, (left, top), (right, bottom), (0, 0, 255), 2)

        # Draw a label with a name below the face
        cv2.rectangle(frame, (left, bottom - 35), (right, bottom), (0, 0, 255), -1)
        font = cv2.FONT_HERSHEY_DUPLEX
        cv2.putText(frame, name, (left + 6, bottom - 6), font, 1.0, (255, 255, 255), 1)

    # Display the resulting image
    cv2.imshow('Video', frame)

    # Hit 'q' on the keyboard to quit!
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release handle to the webcam
video_capture.release()
cv2.destroyAllWindows()