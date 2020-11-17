#pragma once
#include <time.h>
#include <cassert>

int* getToday();  // [현재년도, 현재 월, 현재 일]의 int형 배열 반환
bool isLeapYear(int year);  // year가 윤년이라면 true 반환


class Calendar
{
private:
	int year, month, day;

public:
	Calendar();
	Calendar(int year, int month, int day);
	void setCalendar(int year, int month, int day);
	int* getCalendar();  // [year, month, day]의 int형 배열 반환
	int getDDay();  // 디데이 반환
};
