#include "schedule.h"
#include <time.h>
#include <iostream>

Schedule::Schedule(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

void Schedule::setSchedule(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

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
	int mnth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int* now = getToday();
	int d_day = 0;

	int yy = now[0], mm = now[1];

	if (yy == year && mm == month) return day - now[2];

	while (1)
	{
		if (++mm > 12) ++yy, mm = 1;
		if (yy * 12 + mm >= year * 12 + month) break;

		d_day += mnth[mm];

		if (mm == 2)
		{
			if (yy % 400 == 0 || (yy % 100 != 0 && yy % 4 == 0)) // À±³â
				++d_day;
		}
	}

	d_day += mnth[now[1]] - now[2] + day;
	return d_day;
}

int* Schedule::getToday()
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