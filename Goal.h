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
	bool isEndToday() const; // 오늘 끝나거나, 이미 끝난 목표일 경우 true를 반환

private:
	string context;  // 세부목표의 내용
	Calendar deadline;  // 세부목표의 기한
	bool clear;  // 세부목표의 달성 여부
};