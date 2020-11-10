#include "schedule.h"
#include "calendar.h"
#include <cassert>


Schedule::Schedule()
{
	this->name = "";
	deadline.setCalendar(1900, 1, 1);
}

Schedule::Schedule(string name, int year, int month, int day)
{
	setName(name);
	deadline.setCalendar(year, month, day);
}

void Schedule::setSchedule(int year, int month, int day) { 
	deadline.setCalendar(year, month, day); 
}

void Schedule::setName(string name) { 
	this->name = name; 
}

string Schedule::getName() { 
	return name; 
}

int* Schedule::getSchedule() { 
	return deadline.getCalendar(); 
}

int Schedule::getDDay() { 
	return deadline.getDDay(); 
}
