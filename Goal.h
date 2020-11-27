#pragma once
#include "Schedule.h"
#include <string>

#define STR_LEN 256

using namespace std;

class Goal {
public:
	Goal();
	Goal(const string& context, int year, int month, int day);
	Goal(const string& context, int year, int month, int day, bool clear);
	void set_Context(const string& context);
	string get_Context() const;
	void set_Clear(bool clear);
	bool get_Clear() const;
	void set_Deadline(int year, int month, int day);
	int* get_Deadline() const;
	int get_DDay() const;
	bool isEndToday() const; // ���� �����ų�, �̹� ���� ��ǥ�� ��� true�� ��ȯ

private:
	string context;  // ���θ�ǥ�� ����
	Calendar deadline;  // ���θ�ǥ�� ����
	bool clear;  // ���θ�ǥ�� �޼� ����
};