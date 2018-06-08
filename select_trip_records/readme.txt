1、本文件下面的代码主要功能是：从mysql数据库中读取某人的考勤记录，并将其打印在命令行窗口。
2、该模块是基于mysql5.5在windows下的API开发，在windows下使用VS2015运行测试该模块需要进行相关的mysql配置，
即头文件和库文件的配置(include和lib)；
3、该模块最终生成的文件是一个可执行文件，例如"select_trip_records.exe"，可以在cmd命令行提示符下进行测试，例如：
select_trip_records.exe "name_wang"，回车之后会将从mysql数据库中读取某人的考勤记录，并在命令行窗口进行显示。