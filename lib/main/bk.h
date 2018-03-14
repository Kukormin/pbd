#ifndef BK_H
#define BK_H

using namespace std;

class Bk
{
	public:
		// Поля, хранящиеся в БД
		int id;
		char* name;
		char* code;
		bool active;
		bool autoLoad;

		// Состояния из state.ini
		int lastLoad;
		int lastSuccess;
		int errorsChain;
		bool suspended;

};

extern int BKCnt;
extern Bk BK[10];

#endif // BK_H
