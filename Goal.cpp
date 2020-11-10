#include "Goal.h"
#include <string>

Goal::Goal() {
	set_Context("");
	this->deadline = Calendar(1900, 1, 1);
	set_Clear(false);
}

Goal::Goal(string context, int year, int month, int day, bool clear) {
	set_Context(context);
	this->deadline = Calendar(year, month, day);
	set_Clear(clear);
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

void Goal::set_Deadline(int year, int month, int day) {
	deadline.setCalendar(year, month, day);
}

int* Goal::get_Deadline() {
	return deadline.getCalendar();
}

bool Goal::isEndToday() {
	if (deadline.getDDay() <= 0) return true;
	return false;
}