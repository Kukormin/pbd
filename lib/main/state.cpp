#include "state.h"
#include "bk.h"
#include <string>
#include <fstream>

using namespace std;

int State::checkTime;

void State::load()
{
	string key;
	ifstream file("/var/www/probet/pbd/state.ini");
	if (!file)
		return;

	while (!file.eof())
	{
		file >> key;
		if (key == "checkTime")
			file >> checkTime;
		if (key == "bk")
		{
			int i;
			file >> i;
			file >> BK[i].lastLoad >> BK[i].lastSuccess >> BK[i].errorsChain >> BK[i].suspended;
		}
	}

	file.close();
}

void State::save()
{
	ofstream file("/var/www/probet/pbd/state.ini", ofstream::out);

	file << "checkTime " << checkTime << endl;
	for (int i = 1; i <= BKCnt; ++i)
		file << "bk " << i << " " << BK[i].lastLoad << " " << BK[i].lastSuccess << " " << BK[i].errorsChain << " " << BK[i].suspended << endl;

	file.close();
}
