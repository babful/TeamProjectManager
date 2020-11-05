#pragma once
#include "schedule.h"
#include <string>

#define STR_LEN 256

using namespace std;

class Goal {
public:
	Goal();
	Goal(string context, Schedule deadline, bool clear);
	void set_Context(string context);
	string get_Context();
	void set_Clear(bool clear);
	bool get_Clear();
	void set_Deadline(int* cal);
	int* get_Deadline();

private:
	string context;  // 技何格钎狼 郴侩
	Schedule deadline;  // 技何格钎狼 扁茄
	bool clear;  // 技何格钎狼 崔己 咯何
};
