#include <stdio.h>
#include <stdlib.h>

#include "AfMysql.h"

// MySQL support on Windows
#include <WinSock2.h>
#include <mysql.h>


int my_select(MYSQL* conn, char* name)
{
	// Construct Mysql statement
	char* sql1 = "SELECT `dateTime` FROM comeIn WHERE NAME=";
	char* sql2 = name;
	//printf("name:%s\n", name);
	//const char* sql = "SELECT * FROM student";
	char sql[100];
	strcpy(sql, sql1);
	strcat(sql, sql2);
	//printf("sql:%s\n", sql);
	int ret = mysql_query(conn, sql);
	if (ret != 0)
	{
		printf("error: %s \n", mysql_error(conn));
		return -1;
	}

	MYSQL_RES * result = mysql_store_result(conn);
	if (result == NULL)
	{
		//printf("error(%d): %s \n", mysql_errno(conn), mysql_error(conn));
	}
	else
	{
		// how many rows
		my_ulonglong num_rows = mysql_num_rows(result);
		//printf("got %d rows: \n", (int)num_rows);

		// number of fields for each row
		unsigned int num_fields = mysql_num_fields(result);
		//printf("number of fields: %d \n", (int)num_fields);
		printf("the records of student name as %s is:\n", name);

		// fetch the rows
		MYSQL_ROW row;
		while ((row = mysql_fetch_row(result)))
		{
			unsigned long *lengths = mysql_fetch_lengths(result);
			for (int i = 0; i < num_fields; i++)
			{
				char* field = row[i]; // can be a NULL value
				unsigned int field_length = lengths[i]; // the data length
				
				/*
				if (i == 0)
				{
					AfMysql::Int val = AfMysql::AsInt(field, field_length);
					printf("id: %d \n", val);
				}
				if (i == 1)
				{
					AfMysql::String val = AfMysql::AsString(field, field_length);
					printf("name: %s \n", val.c_str());
				}
				if (i == 2)
				{
					AfMysql::Date val = AfMysql::AsDate(field, field_length);
					printf("date: %d-%d-%d\n", val.year, val.month, val.day);
				}
				if (i == 3)
				{
					AfMysql::String val = AfMysql::AsString(field, field_length);
					printf("cellphone: %s \n", val.c_str());
				}
				*/
				if (i == 0) {
					printf("%s\n", field ? field : NULL);
				}

			}
			//printf("\n");
		}

		// release the memory
		mysql_free_result(result);
	}

	return 0;
}

int main(int argc, char* argv[])
{
	long long val;
	sscanf("102388982430234", "%I64d", &val);

	if (mysql_library_init(0, NULL, NULL))
	{
		printf("could not initialize MySQL library\n");
		return -1;
	}

	// 连接服务器
	MYSQL conn;
	mysql_init(&conn);

	MYSQL* ret = mysql_real_connect(&conn,
		"127.0.0.1", "root", "123456", "example"
		, 0, NULL, 0);
	if (!ret)
	{
		printf("Failed to connect to database:  %s\n",
			mysql_error(&conn));
	}

	my_select(&conn, argv[1]);

	// 关闭连接
	mysql_close(&conn);

	mysql_library_end();
	return 0;
}