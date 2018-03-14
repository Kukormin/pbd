#include "bk.h"
#include "db.h"

using namespace std;

int BKCnt;
Bk BK[10];

void getAllBk()
{
	const char* q = "SELECT ID, UF_NAME, UF_ACTIVE, UF_CODE FROM bk";
	MYSQL_RES* rsItems = DB::query(q);
	if (rsItems)
	{
		MYSQL_ROW item;
		while((item = DB::fetch(rsItems)))
		{
			int id = atoi(item[0]);
			BK[id] = Bk();
			BK[id].id = id;
			BK[id].name = item[1];
			BK[id].active = strcmp(item[2], "1") == 0;
			BK[id].code = item[3];

			if (BKCnt < id)
				BKCnt = id;
		}
	}
}
