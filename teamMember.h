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
	int today_GoalCount(); //������ ���ñ����� ��ǥ ���� ��ȯ
private:
	string Student_Name;
	string Student_Number;
	string Role;
	int clearCount; //�޼��� ��ǥ ����
	int goalCount; //��ǥ ����
	vector<Goal> GoalList;
};

