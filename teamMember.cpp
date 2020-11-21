#include "teamMember.h"
#include <string>
#include <iostream>

teamMember::teamMember() {
	this->Student_Name = "";
	this->Student_Number = "";
	this->Role = "";
	this->clearCount = 0;
	this->goalCount = 0;
}

teamMember::teamMember(string Student_Name, string Student_Number, string Role) {
	this->Student_Name = Student_Name;
	this->Student_Number = Student_Number;
	this->Role = Role;
	this->clearCount = 0;
	this->goalCount = 0;
}

void teamMember::set_Name(string Student_Name) {
	this->Student_Name = Student_Name;
}

void teamMember::set_Number(string Student_Number) {
	this->Student_Number = Student_Number;
}

void teamMember::set_Role(string Role) {
	this->Role = Role;
}

void teamMember::add_Goal(Goal Goal) {
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
}

void teamMember::sort_Goal() {
	int size = GoalList.size();
	// 버블정렬, 후에 더 나은 알고리즘으로 변경 필요
	for (int i = 0; i < size - 1; i++) {  
		for (int j = 0; j < size - 1 - i; j++) {
			if (GoalList[j].get_DDay() > GoalList[j + 1].get_DDay()) {
				swap(GoalList[j], GoalList[j + 1]);
			}
		}
	}
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

int teamMember::get_Goal_deadline_Year(int index) const {
	return GoalList[index].get_Year();
}

int teamMember::get_Goal_deadline_Month(int index) const {
	return GoalList[index].get_Month();
}

int teamMember::get_Goal_deadline_Day(int index) const {
	return GoalList[index].get_Day();
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

Goal teamMember::get_Urgent_Goal() {
	if (GoalList.size() == 0) return Goal();  // 예외처리

	vector<Goal>::iterator it;
	int min = GoalList[0].get_DDay(), idx = 0;

	for (it = GoalList.begin() + 1; it != GoalList.end(); ++it) {
		if (it->get_Clear() == false) {
			int dday = it->get_DDay();

			if (dday != -1 && dday < min) {
				min = dday;
				idx = it - GoalList.begin();
			}
		}
	}
	return GoalList.at(idx);
}

int teamMember::findGoal(string context) {
	vector<Goal>::iterator it;
	for (it = GoalList.begin(); it != GoalList.end(); ++it) {
		if (it->get_Context() == context) {
			return it - GoalList.begin();
		}
	}
	return -1;  // Failed to find
}