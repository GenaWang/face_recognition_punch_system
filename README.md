This project is a face detection and punching system.
***
The project consists of three modules: <br>
1. Detecting face information from the video stream;<br> 
2. Writing the detected face information and current time into the database; <br> 
3. Retrieving someone's attendance record from the database.<br> 
***
There are three folders, which are: "face_attendance_system", "record_face_data", and "select_trip_records".<br> 
The folder named "record_face_data" is about writing the detected face information and current time into the database.<br> 
The folder named "select_trip_records" is about retrieving someone's attendance record from the database.<br> 
The folder named "face_attendance_system" is about detecting face information from the video stream and writing the detected face  information and current time into the database.
***
## How to use?
Firstly there is a folder named "readme.txt" in the there folders.You can read them to understand how to use each model.<br> 
Secondly I mainly introduce the folder named "face_attendance_system".<br> 
***
You need some external dependencies:opencv/dlib/face_recognition and install them:<br> 
pip install opencv/pip install dlib/pip install face_recognition.<br> 
Then you can open the file named "face_detect_web_cam.py".Run this file and it will work.<br> 
