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

	void addMember(const string& name, const string& number, const string& role);
	void delMember(int idx);
	void addSchedule(const string& name, int year, int month, int day);
	void delSchedule(int idx);
	void delOldSchedules();
	void sortSchedule(); // 주 목표들을 D-Day가 적은 순으로 정렬

private:
	vector<teamMember> member;
	vector<Schedule> schedules;
};
