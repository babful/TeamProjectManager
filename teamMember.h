#pragma once
#include "Goal.h"
#include <string>
#include <vector>

#define SIZE 32

using namespace std;

class teamMember {
public:
	teamMember();
	teamMember(string Student_Name, string Student_Number, string Role);

	void set_Name(string Student_Name);
	void set_Number(string Student_Number);
	void set_Role(string Role);
	void add_Goal(Goal Goal);
	void delete_Goal(int index);
	void sort_Goal();
	void set_Goal_Clear(int index, bool clear);
	string get_Name();
	string get_Number();
	string get_Role();
	string get_Goal_Context(int index);
	int get_Goal_deadline_Year(int index);
	int get_Goal_deadline_Month(int index);
	int get_Goal_deadline_Day(int index);
	int* get_Goal_deadline(int index);
	bool get_Goal_Clear(int index);
	int get_GoalCount();
	int get_ClearCount();
	int today_GoalCount(); //기한이 오늘까지인 목표 개수 반환
private:
	string Student_Name;
	string Student_Number;
	string Role;
	int clearCount; //달성한 목표 개수
	int goalCount; //목표 개수
	vector<Goal> GoalList;
};

