#include "teamMember.h"
#include <string>
#include <algorithm>

teamMember::teamMember() {
	this->Student_Name = "";
	this->Student_Number = "";
	this->Role = "";
	this->clearCount = 0;
	this->goalCount = 0;
}

teamMember::teamMember(const string& Student_Name, const string& Student_Number, const string& Role) {
	this->Student_Name = Student_Name;
	this->Student_Number = Student_Number;
	this->Role = Role;
	this->clearCount = 0;
	this->goalCount = 0;
}

void teamMember::set_Name(const string& Student_Name) {
	this->Student_Name = Student_Name;
}

void teamMember::set_Number(const string& Student_Number) {
	this->Student_Number = Student_Number;
}

void teamMember::set_Role(const string& Role) {
	this->Role = Role;
}

void teamMember::add_Goal(const Goal& Goal) {
	GoalList.push_back(Goal);
	goalCount++;
}

void teamMember::delete_Goal(int index) {
	GoalList.erase(GoalList.begin() + index);
	goalCount--;
}

void teamMember::set_Goal_Clear(int index, bool clear) {
	GoalList[index].set_Clear(clear);
	if (clear == true)
		clearCount++;
	else
		clearCount--;
}

void teamMember::set_ClearCount(int index) {
	this->clearCount = index;
}

int teamMember::today_GoalCount() const {
	int today_goalCount = 0;
	int size = GoalList.size();

	for (int i = 0; i < size; i++) {
		if (GoalList[i].isEndToday())
			today_goalCount++;
	}
	return today_goalCount;
}

string teamMember::get_Goal_Context(int index) const {
	return GoalList[index].get_Context();
}

int* teamMember::get_Goal_deadline(int index) const {
	return GoalList[index].get_Deadline();
}

bool teamMember::get_Goal_Clear(int index) const {
	return this->GoalList[index].get_Clear();
}

int teamMember::get_GoalCount() const {
	return this->goalCount; 
}

int teamMember::get_ClearCount() const { 
	return this->clearCount; 
}

string teamMember::get_Name() const {
	return this->Student_Name;
}

string teamMember::get_Number() const {
	return this->Student_Number;
}

string teamMember::get_Role() const {
	return this->Role;
}

Goal& teamMember::get_Goal(int index) {
	return GoalList[index];
}

void teamMember::sort_Goal() {
	std::sort(GoalList.begin(), GoalList.end(), compare_Goal);
}

bool compare_Goal(Goal g1, Goal g2) {
	return g1.get_DDay() < g2.get_DDay();
}