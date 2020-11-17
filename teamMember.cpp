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
	vector<Goal>::iterator it;
	int i = 0;
	for (it = GoalList.begin(); it != GoalList.end(); it++) {
		if (i == index) break;
		i++;
	}
	GoalList.erase(it);
	goalCount--;

}

void teamMember::set_Goal_Clear(int index, bool clear) {
	GoalList[index].set_Clear(clear);
	if (clear == true)
		clearCount++;
}

void teamMember::sort_Goal() {
	Goal temp;
	for (int i = 0; i < GoalList.size() - 1; i++) {
		for (int j = 0; j < GoalList.size() - 1 - i; j++) {
			if (GoalList[j].get_DDay() > GoalList[j + 1].get_DDay())
			{
				temp = GoalList[j];
				GoalList[j] = GoalList[j + 1];
				GoalList[j + 1] = temp;
			}
		}
	}
}
int teamMember::today_GoalCount() {
	int today_goalCount = 0;
	for (int i = 0; i < GoalList.size(); i++) {
		if (GoalList[i].isEndToday() == true)
			today_goalCount++;
	}
	return today_goalCount;
}

string teamMember::get_Goal_Context(int index) {
	return this->GoalList[index].get_Context();
}

int teamMember::get_Goal_deadline_Year(int index) {
	return GoalList[index].get_Year();
}

int teamMember::get_Goal_deadline_Month(int index) {
	return GoalList[index].get_Month();
}

int teamMember::get_Goal_deadline_Day(int index) {
	return GoalList[index].get_Day();
}

int* teamMember::get_Goal_deadline(int index) {
	return GoalList[index].get_Deadline();
}

bool teamMember::get_Goal_Clear(int index) {
	return this->GoalList[index].get_Clear();
}
int teamMember::get_GoalCount(){ 
	return this->goalCount; 
}
int teamMember::get_ClearCount() { 
	return this->clearCount; 
}

string teamMember::get_Name() {
	return this->Student_Name;
}

string teamMember::get_Number() {
	return this->Student_Number;
}

string teamMember::get_Role() {
	return this->Role;
}



