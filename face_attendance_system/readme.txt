1、该模块的功能是：对摄像头中的每一帧图像进行检测，并将检测到的人脸信息写入到数据库中（这里设定一分钟之内的
多帧图像中出现多个相同的人脸信息，我们只进行一次数据库存储）。
2、模块运行需要的软硬件支持
1）硬件支持：带摄像头的电脑或者带USB接口的摄像头；
2）软件支持：dlib/face_recognition/opencv。