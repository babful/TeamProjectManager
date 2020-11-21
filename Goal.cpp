#include "Goal.h"
#include <string>

Goal::Goal() {
	this->context = "NULL";
	this->deadline = Calendar(1900, 1, 1);
	this->clear = false;
}

Goal::Goal(string context, int year, int month, int day) {
	this->context = context;
	this->deadline = Calendar(year, month, day);
	this->clear = false;
}

Goal::Goal(string context, int year, int month, int day, bool clear) {
	this->context = context;
	this->deadline = Calendar(year, month, day);
	this->clear = clear;
}

void Goal::set_Context(string context) {
	this->context = context;
}

string Goal::get_Context() const {
	return this->context;
}

void Goal::set_Clear(bool clear) {
	this->clear = clear;
}

bool Goal::get_Clear() const {
	return this->clear;
}

void Goal::set_Deadline(int year, int month, int day) {
	deadline.setCalendar(year, month, day);
}

int* Goal::get_Deadline() const {
	return deadline.getCalendar();
}

int Goal::get_Year() const {
	return deadline.getYear();
}

int Goal::get_Month() const {
	return deadline.getMonth();
}

int Goal::get_Day() const {
	return deadline.getDay();
}

int Goal::get_DDay() const {
	return deadline.getDDay();
}

bool Goal::isEndToday() const {
	if (deadline.getDDay() <= 0) return true;
	return false;
}
