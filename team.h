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
	Schedule& getSchedule();  // 주 목표에게 접근
	int getMemberCnt() const;  // 팀의 멤버 수 반환

	void addMember(string name, string number, string role);
	int delMember(int idx);
	Goal getUrgentGoal(); // 가장 기한이 적게 남은 목표 반환

private:
	vector<teamMember> member;
	Schedule schedule;
};
