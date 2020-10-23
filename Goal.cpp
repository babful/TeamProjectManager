#include "Goal.h"
#include <string>

Goal::Goal() {
	this->Detail_Goal = "";
}
void Goal::set_Goal(string Detail_Goal) {
	this->Detail_Goal = Detail_Goal;
}
string Goal::get_Goal() {
	return this->Detail_Goal;
}

void Goal::set_Clear(bool clear) {
	this->clear = clear;
}

bool Goal::get_Clear() {
	return this->clear;
}