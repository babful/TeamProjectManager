#pragma once
#include <time.h>
#include <cassert>

int* getToday();  // [����⵵, ���� ��, ���� ��]�� int�� �迭 ��ȯ
bool isLeapYear(int year);  // year�� �����̶�� true ��ȯ


class Calendar
{
public:
	Calendar();
	Calendar(int year, int month, int day);
	void setCalendar(int year, int month, int day);
	int* getCalendar() const;  // [year, month, day]�� int�� �迭 ��ȯ
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	int getDDay() const;  // ���� ��ȯ

private:
	int year, month, day;
};
