#pragma once
#include <string>

#define STR_LEN 256

using namespace std;

class Goal {
public:
	Goal();
	void set_Goal(string Detail_Goal);
	string get_Goal();
	void set_Clear(bool clear);
	bool get_Clear();
private:
	string Detail_Goal;
	bool clear;
};
