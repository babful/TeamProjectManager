#pragma once
#include "schedule.h"
#include <string>

#define STR_LEN 256

using namespace std;

class Goal {
public:
	Goal();
	Goal(string context, int year, int month, int day, bool clear);
	void set_Context(string context);
	string get_Context();
	void set_Clear(bool clear);
	bool get_Clear();
	void set_Deadline(int year, int month, int day);
	int* get_Deadline();
	bool isEndToday();

private:
	string context;  // ���θ�ǥ�� ����
	Calendar deadline;  // ���θ�ǥ�� ����
	bool clear;  // ���θ�ǥ�� �޼� ����
};
