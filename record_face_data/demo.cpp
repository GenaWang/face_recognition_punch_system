#include <vector>
#include <iostream>
#include <string>

#include <WinSock2.h>
#include <mysql.h>

#include <time.h>

using namespace std;

struct Student {
	char* name;
	char datetime[32];
};

int doInsert(Student* st);

int main(int argc, char* argv[]) {
	if (mysql_library_init(0, NULL, NULL))
	{
		printf("could not initialize MySQL library\n");
		return -1;
	}

	Student st1;
	// Input your name
	// printf("neme is:");
	// scanf("%s", st1.name);
	st1.name = argv[1];
	//printf("neme is:%s", st1.name);

	// Get the date and time at this moment
	tm* localTime;
	time_t t;
	t = time(NULL);
	localTime = localtime(&t);
	string tString;
	tString = to_string(localTime->tm_year+1900) + "-" + to_string(localTime->tm_mon) + "-" + to_string(localTime->tm_mday) + \
		"-" + to_string(localTime->tm_hour) + "-" + to_string(localTime->tm_min);
	//cout << tString << endl;
	strcpy(st1.datetime, tString.c_str());
	//cout << st1.datetime << endl;

	// Write the name and date to the table 'comeIn' in the database 'example'
	if (doInsert(&st1) == -1) {
		printf("can not insert data to the database\n");
		return -1;
	}

	mysql_library_end();
	return 0;
}

int doInsert(Student* st) {
	MYSQL conn;
	mysql_init(&conn);

	// Connnect to the database sercer MYSQL
	if (mysql_real_connect(&conn, "127.0.0.1", "root", "123456", "example", 0, NULL, 0) == NULL) {
		printf("Failed to connnect to the database:%s\n", mysql_error(&conn));
		return -1;
	}

	// Construct an insert statement
	char sql[256];
	sprintf(sql,"INSERT INTO `comeIn` (`name`, `dateTime`) VALUES ('%s', '%s')",st->name, st->datetime);
	//cout << sql << endl;

	// Execute the insert statement
	int ret = mysql_query(&conn, sql);
	if (ret != 0) {
		printf("insert error:%s\n", mysql_error(&conn));
		return -1;
	}
	else {
		my_ulonglong affected_rows = mysql_affected_rows(&conn); // a 64-bit large number
		printf("%d rows affected. \n", (int)affected_rows); // cast to int
	}

	// Close the connect 
	mysql_close(&conn);
}