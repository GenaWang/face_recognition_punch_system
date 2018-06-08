1、本文件下面的代码主要功能是：将传入的人脸检测信息即名字和此刻的时间写入到Mysql数据库中；
2、该模块是基于mysql5.5在windows下的API开发，在windows下使用VS2015运行测试该模块需要进行相关的mysql配置，
即头文件和库文件的配置(include和lib)；
3、该模块最终生成的文件是一个可执行文件，例如"record_face_data.exe"，可以在cmd命令行提示符下进行测试，例如：
record_face_data.exe "name_wang"，回车之后会将name_wang和此刻的时间存入mysql数据库，但是提前是需要保证数据库
的正常连接。