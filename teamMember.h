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
	Goal& get_Goal(int index);  // GoalList[index]의 참조값 반환
	string get_Goal_Context(int index) const;  // GoalList[index]의 context 반환
	int* get_Goal_deadline(int index) const;  // GoalList[index]의 기한 반환
	bool get_Goal_Clear(int index) const;  // GoalList[index]의 완료 여부 반환
	int get_GoalCount() const;  // 전체 세부목표 개수 반환
	int get_ClearCount() const;  // 완료한 세부목표 개수 반환
	int today_GoalCount() const; //기한이 오늘까지인 목표 개수 반환
	void sort_Goal(); // 세부목표를 D-Day가 작은 순으로 정렬

private:
	string Student_Name;
	string Student_Number;
	string Role;
	int clearCount; //달성한 목표 개수
	int goalCount; //목표 개수
	vector<Goal> GoalList;
};

bool compare_Goal(Goal g1, Goal g2); // sort_Goal 함수의 정렬 기준
