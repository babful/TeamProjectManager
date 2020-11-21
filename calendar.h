#pragma once
#include <time.h>
#include <cassert>

int* getToday();  // [현재년도, 현재 월, 현재 일]의 int형 배열 반환
bool isLeapYear(int year);  // year가 윤년이라면 true 반환
bool isValidDate(int year, int month, int day);


class Calendar
{
public:
	Calendar();
	Calendar(int year, int month, int day);
	void setCalendar(int year, int month, int day);
	int* getCalendar() const;  // [year, month, day]의 int형 배열 반환
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	int getDDay() const;  // 디데이 반환

private:
	int year, month, day;
};
