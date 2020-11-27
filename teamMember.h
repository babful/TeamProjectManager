#pragma once
#include "Goal.h"
#include <string>
#include <vector>

#define SIZE 32

using namespace std;

class teamMember {
public:
	teamMember();
	teamMember(const string& Student_Name, const string& Student_Number, const string& Role);

	void set_Name(const string& Student_Name);
	void set_Number(const string& Student_Number);
	void set_Role(const string& Role);
	void add_Goal(const Goal& Goal);
	void delete_Goal(int index);
	void set_Goal_Clear(int index, bool clear);
	void set_ClearCount(int index);
	string get_Name() const;
	string get_Number() const;
	string get_Role() const;
	Goal& get_Goal(int index);  // GoalList[index]�� ������ ��ȯ
	string get_Goal_Context(int index) const;  // GoalList[index]�� context ��ȯ
	int* get_Goal_deadline(int index) const;  // GoalList[index]�� ���� ��ȯ
	bool get_Goal_Clear(int index) const;  // GoalList[index]�� �Ϸ� ���� ��ȯ
	int get_GoalCount() const;  // ��ü ���θ�ǥ ���� ��ȯ
	int get_ClearCount() const;  // �Ϸ��� ���θ�ǥ ���� ��ȯ
	int today_GoalCount() const; //������ ���ñ����� ��ǥ ���� ��ȯ
	void sort_Goal(); // ���θ�ǥ�� D-Day�� ���� ������ ����

private:
	string Student_Name;
	string Student_Number;
	string Role;
	int clearCount; //�޼��� ��ǥ ����
	int goalCount; //��ǥ ����
	vector<Goal> GoalList;
};

bool compare_Goal(Goal g1, Goal g2); // sort_Goal �Լ��� ���� ����
