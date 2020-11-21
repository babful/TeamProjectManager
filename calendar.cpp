#include "calendar.h"

int month_day[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // 각 달의 끝 날짜


Calendar::Calendar() {
	this->year = 1900;
	this->month = 1;
	this->day = 1;
}

Calendar::Calendar(int year, int month, int day) {
	assert(isValidDate(year, month, day));
	this->year = year;
	this->month = month;
	this->day = day;
}

void Calendar::setCalendar(int year, int month, int day) {
	assert(isValidDate(year, month, day));
	this->year = year;
	this->month = month;
	this->day = day;
}

int* Calendar::getCalendar() const
{
	int* deadline = new int[3];
	deadline[0] = year;
	deadline[1] = month;
	deadline[2] = day;

	return deadline;
}

int Calendar::getYear() const {
	return year;
}

int Calendar::getMonth() const {
	return month;
}

int Calendar::getDay() const {
	return day;
}

int Calendar::getDDay() const
{
	int* now = getToday();
	if (now[0] * 10000 + now[1] * 100 + now[2] > year * 10000 + month * 100 + day) return -1;  // 이미 지났을 경우 -1 출력
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
	if (year < 1) return false;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
	return false;
}

bool isValidDate(int year, int month, int day) {
	if (year < 1) return false;
	if (month < 1 || month > 12) return false;

	if (month == 2) {
		int limit = 28;
		if (isLeapYear(year)) ++limit;

		if (day < 1 || day > limit) return false;
		else return true;
	}

	else {
		if (day < 1 || day > month_day[month]) return false;
		return true;
	}
}
