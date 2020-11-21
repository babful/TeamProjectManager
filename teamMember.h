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
	string get_Name() const;
	string get_Number() const;
	string get_Role() const;
	Goal& get_Goal(int index);  // GoalList[index]�� ������ ��ȯ
	string get_Goal_Context(int index) const;  // GoalList[index]�� context ��ȯ
	int get_Goal_deadline_Year(int index) const;
	int get_Goal_deadline_Month(int index) const;
	int get_Goal_deadline_Day(int index) const;
	int* get_Goal_deadline(int index) const;  // GoalList[index]�� ���� ��ȯ
	bool get_Goal_Clear(int index) const;  // GoalList[index]�� �Ϸ� ���� ��ȯ
	int get_GoalCount() const;  // ��ü ���θ�ǥ ���� ��ȯ
	int get_ClearCount() const;  // �Ϸ��� ���θ�ǥ ���� ��ȯ
	int today_GoalCount() const; //������ ���ñ����� ��ǥ ���� ��ȯ
	Goal get_Urgent_Goal();
	int findGoal(string context);  // context�� GoalList�� index �˻�

private:
	string Student_Name;
	string Student_Number;
	string Role;
	int clearCount; //�޼��� ��ǥ ����
	int goalCount; //��ǥ ����
	vector<Goal> GoalList;
};
