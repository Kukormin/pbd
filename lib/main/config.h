#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <map>

using namespace std;

class Config
{
	public:
		static map<string,string> values;

		static void load();
		static void set(string key, string val);
		static string get(string key);
		static char* getChar(string key);
		static int getInt(string key);
};

#endif // CONFIG_H
