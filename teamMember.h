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
	Goal& get_Goal(int index);  // GoalList[index]의 참조값 반환
	string get_Goal_Context(int index) const;  // GoalList[index]의 context 반환
	int get_Goal_deadline_Year(int index) const;
	int get_Goal_deadline_Month(int index) const;
	int get_Goal_deadline_Day(int index) const;
	int* get_Goal_deadline(int index) const;  // GoalList[index]의 기한 반환
	bool get_Goal_Clear(int index) const;  // GoalList[index]의 완료 여부 반환
	int get_GoalCount() const;  // 전체 세부목표 개수 반환
	int get_ClearCount() const;  // 완료한 세부목표 개수 반환
	int today_GoalCount() const; //기한이 오늘까지인 목표 개수 반환
	Goal get_Urgent_Goal();
	int findGoal(string context);  // context로 GoalList의 index 검색

private:
	string Student_Name;
	string Student_Number;
	string Role;
	int clearCount; //달성한 목표 개수
	int goalCount; //목표 개수
	vector<Goal> GoalList;
};
