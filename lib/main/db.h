#ifndef DB_H
#define DB_H

//#include </usr/include/mysql/mysql.h>
#include <windows.h>
#include <mysql.h>
#include <typeinfo>

using namespace std;

class DB
{
	private:
		static MYSQL mysql;

	public:
		static int connect();
		static void close();
		static MYSQL_RES* query(const char* q);
		static MYSQL_ROW fetch(MYSQL_RES* res);
};

#endif // DB_H
