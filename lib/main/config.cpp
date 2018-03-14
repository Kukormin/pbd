#ifndef CONFIG_CPP
#define CONFIG_CPP

#include <fstream>
#include <cstring>
#include <cstdlib>
#include <map>
#include "config.h"

using namespace std;

map<string,string> Config::values;

void Config::load()
{
	string s;
	ifstream file("d:/Work/probet/pbd/config.ini");

	while (getline(file, s))
	{
		int pos = s.find('=');
		if (pos < 0)
			continue;

		string key = s.substr(0, pos);
		string val = s.substr(pos + 1);
		set(key, val);

		cout << key << "  " << val << "\n";
	}

	file.close();
}

void Config::set(string key, string val)
{
	values[key] = val;
}

string Config::get(string key)
{
	return values[key];
}

char* Config::getChar(string key)
{
	string val = values[key];
	char* ret = new char [val.length() + 1];
	strcpy(ret, val.c_str());
	return ret;
}

int Config::getInt(string key)
{
	string val = values[key];
	return atoi(val.c_str());
}

#endif // CONFIG_CPP
