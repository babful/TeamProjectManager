#pragma once
#include <string>
#include <vector>
#include "teamMember.h"
#include "schedule.h"

using namespace std;

class Team
{
public:
	teamMember& getMember(int idx);  // �� ������� ����
	Schedule& getSchedule();  // �� ��ǥ���� ����
	int getMemberCnt() const;  // ���� ��� �� ��ȯ

	void addMember(string name, string number, string role);
	int delMember(int idx);
	Goal getUrgentGoal(); // ���� ������ ���� ���� ��ǥ ��ȯ

private:
	vector<teamMember> member;
	Schedule schedule;
};
