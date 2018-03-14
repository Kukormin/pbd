#include "db.h"
#include "config.h"

using namespace std;

MYSQL DB::mysql;

int DB::connect()
{
	if (!mysql_init(&mysql))
		return 1;

	char* host = Config::getChar("host");
	char* user = Config::getChar("dbuser");
	char* pass = Config::getChar("dbpass");
	char* dbname = Config::getChar("dbname");
	int port = Config::getInt("port");
	if (!(mysql_real_connect(&mysql, host, user, pass, dbname, port, NULL, 0)))
		return 2;

	if (mysql_select_db(&mysql, dbname))
		return 3;

	mysql_query(&mysql, "SET NAMES 'utf8'");
	mysql_query(&mysql, "SET collation_connection = 'utf8_unicode_ci'");
	mysql_query(&mysql, "SET LOCAL time_zone='+04:00'");

	return 0;
}

void DB::close()
{
	mysql_close(&mysql);
}

MYSQL_RES* DB::query(const char* q)
{
	if (mysql_query(&mysql, q))
		return NULL;

	return mysql_store_result(&mysql);
}

MYSQL_ROW DB::fetch(MYSQL_RES* res)
{
	return mysql_fetch_row(res);
}
