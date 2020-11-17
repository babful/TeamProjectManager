#pragma once
#include <time.h>
#include <cassert>

int* getToday();  // [����⵵, ���� ��, ���� ��]�� int�� �迭 ��ȯ
bool isLeapYear(int year);  // year�� �����̶�� true ��ȯ


class Calendar
{
private:
	int year, month, day;

public:
	Calendar();
	Calendar(int year, int month, int day);
	void setCalendar(int year, int month, int day);
	int* getCalendar();  // [year, month, day]�� int�� �迭 ��ȯ
	int getDDay();  // ���� ��ȯ
};
