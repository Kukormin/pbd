//#include <QCoreApplication>

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <cerrno>
#include <cstring>

#include "lib/Main/config.cpp"
/*#include "lib/Main/db.cpp"
#include "lib/Main/bk.cpp"
#include "lib/Main/state.cpp"*/

int main(int argc, char *argv[])
{
	//int pid;

	Config::load();

	/*int res = DB::connect();
	printf("%d\n", res);
	//LogInt(res);

	getAllBk();
	State::load();

	// -------

	State::save();
	DB::close();*/

	cout << "End.\n";

	return 0;
}
