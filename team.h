#pragma once
#include <string>
#include <vector>
#include "teamMember.h"
#include "schedule.h"

using namespace std;

class Team
{
public:
	teamMember& getMember(int idx);  // 팀 멤버에게 접근
	Schedule& getSchedule(int idx);  // 주 목표에게 접근
	int getMemberCnt() const;  // 팀의 멤버 수 반환
	int getScheduleCnt() const; 

	void addMember(string name, string number, string role);
	int delMember(int idx);
	void addSchedule(string name, int year, int month, int day);
	int delSchedule(int idx);
	int delOldSchedules();
	void sortSchedule(); // 주 목표들을 D-Day가 적은 순으로 정렬

private:
	vector<teamMember> member;
	vector<Schedule> schedules;
};
