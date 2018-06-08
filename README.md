This project is a face detection and punching system.
***
The project consists of three modules: 1. Detecting face information from the video stream; 
2. Writing the detected face information and current time into the database; 
3. Retrieving someone's attendance record from the database.
***
There are three folders, which are: "face_attendance_system", "record_face_data", and "select_trip_records".
The folder named "record_face_data" is about writing the detected face information and current time into the database.
The folder named "select_trip_records" is about retrieving someone's attendance record from the database.
The folder named "face_attendance_system" is about detecting face information from the video stream and writing the detected face information and current time into the database.
***
## How to use?
Firstly there is a folder named "readme.txt" in the there folders.You can read them to understand how to use each model.
Secondly I mainly introduce the folder named "record_face_data".
***
You need some external dependencies:opencv/dlib/face_recognition and install them:
pip install opencv/pip install dlib/pip install face_recognition.
Then you can open the file named "face_detect_web_cam.py".Run this file and it will work.
