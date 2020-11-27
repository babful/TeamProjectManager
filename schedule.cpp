#include "schedule.h"
#include "calendar.h"
#include <cassert>


Schedule::Schedule()
{
	this->name = "";
	deadline.setCalendar(1900, 1, 1);
}

Schedule::Schedule(const string& name, int year, int month, int day)
{
	this->name = name;
	deadline.setCalendar(year, month, day);
}

void Schedule::setSchedule(int year, int month, int day) {
	deadline.setCalendar(year, month, day);
}

void Schedule::setName(const string& name) {
	this->name = name;
}

string Schedule::getName() const {
	return name;
}

int Schedule::getYear() const { 
	return deadline.getYear(); 
}

int Schedule::getMonth() const { 
	return deadline.getMonth(); 
}

int Schedule::getDay() const { 
	return deadline.getDay(); 
}

int* Schedule::getSchedule() const {
	return deadline.getCalendar();
}

int Schedule::getDDay() const {
	return deadline.getDDay();
}