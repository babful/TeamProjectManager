#include "Goal.h"
#include <string>

Goal::Goal() {
	this->context = "";
	this->deadline = Schedule("", 1900, 1, 1);
	this->clear = false;
}

Goal::Goal(string context, Schedule deadline, bool clear) {
	this->context = context;
	this->deadline = deadline;
	this->clear = clear;
}

void Goal::set_Context(string context) {
	this->context = context;
}

string Goal::get_Context() {
	return this->context;
}

void Goal::set_Clear(bool clear) {
	this->clear = clear;
}

bool Goal::get_Clear() {
	return this->clear;
}

void Goal::set_Deadline(int *cal) {
	this->deadline.setSchedule(cal[0], cal[1], cal[2]);
}

int* Goal::get_Deadline() {
	return this->deadline.getSchedule();
}