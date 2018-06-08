
#ifndef _AF_MYSQL_H
#define _AF_MYSQL_H

/* AfMysql
用于将MySQL的字段值转成相应的类型
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <string>
using std::string;

class AfMysql
{
public:
	// 日期时间类型
	struct Date
	{
		Date() :year(2000), month(1), day(1) {}
		int year, month, day;
	};
	struct Time
	{
		Time() :hour(0), minute(0), second(0) {}
		int hour, minute, second;
	};
	struct DateTime
	{
		DateTime() : year(2000), month(1), day(1), hour(0), minute(0), second(0) {}
		int year, month, day;
		int hour, minute, second;
	};

	// 字符串类型
	typedef string  String;
	typedef int Int;
	typedef long long BigInt;

public:
	static Int AsInt(const char* field, int length)
	{
		if (field == NULL) return 0;
		return atoi(field);
	}

	static BigInt AsBigInt(const char* field, int length)
	{
		if (field == NULL) return 0;

		long long val;
#ifdef _WIN32
		sscanf(field, "%I64d", &val);
#else
#endif
		return val;
	}

	// 时间类型
	static Date AsDate(const char* field, int length)
	{
		Date val;
		if (field == NULL) return val;

		sscanf(field, "%d-%d-%d", &val.year, &val.month, &val.day);
		return val;
	}
	static Time AsTime(const char* field, int length)
	{
		Time val;
		if (field == NULL) return val;

		sscanf(field, "%d:%d:%d", &val.hour, &val.minute, &val.second);
		return val;
	}

	static DateTime AsDateTime(const char* field, int length)
	{
		DateTime val;
		if (field == NULL) return val;

		sscanf(field, "%d-%d-%d %d:%d:%d",
			&val.year, &val.month, &val.day,
			&val.hour, &val.minute, &val.second);
		return val;
	}

	static String AsString(const char* field, int length)
	{
		if (field == NULL) return "";

		String val = field;
		return val;
	}

};





#endif
