#include "schedule.h"
#include <cassert>

int month_day[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // 각 달의 끝 날짜


Schedule::Schedule()
{
	this->name = "";
	this->year = 1900;
	this->month = 1;
	this->day = 1;
}

Schedule::Schedule(string name, int year, int month, int day)
{
	assert(year > 0 && (1 <= month && month <= 12) && (1 <= day && day <= month_day[month]));
	this->name = name;
	this->year = year;
	this->month = month;
	this->day = day;
}

void Schedule::setSchedule(int year, int month, int day)
{
	assert(year > 0 && (1 <= month && month <= 12) && (1 <= day && day <= month_day[month]));
	this->year = year;
	this->month = month;
	this->day = day;
}

void Schedule::setName(string name) { this->name = name; }
string Schedule::getName() { return name; }

int* Schedule::getSchedule()
{
	int* deadline = new int[3];
	deadline[0] = this->year;
	deadline[1] = this->month;
	deadline[2] = this->day;

	return deadline;
}

int Schedule::getDDay()
{
	int* now = getToday();
	if (now[0] == year && now[1] == month) return day - now[2];

	int d_day = 0, yy = now[0], mm = now[1];

	while (true)
	{
		if (++mm > 12) ++yy, mm = 1;
		if (yy * 12 + mm >= year * 12 + month) break;

		d_day += month_day[mm];
		if (mm == 2 && isLeapYear(yy)) ++d_day;  // 윤년 
	}

	d_day += month_day[now[1]] - now[2] + day;
	return d_day;
}

int* getToday()
{
	time_t timer = time(NULL);
	struct tm t;
	localtime_s(&t, &timer);

	int* now = new int[3];
	now[0] = t.tm_year + 1900;
	now[1] = t.tm_mon + 1;
	now[2] = t.tm_mday;
	return now;
} 

bool isLeapYear(int year)
{
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) return true;
	return false;
}
