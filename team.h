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
	Schedule& getSchedule(int idx);  // �� ��ǥ���� ����
	int getMemberCnt() const;  // ���� ��� �� ��ȯ
	int getScheduleCnt() const; 
	void addMember(const teamMember& member);
	void addMember(const string& name, const string& number, const string& role);
	void delMember(int idx);
	void addSchedule(const string& name, int year, int month, int day);
	void delSchedule(int idx);
	void delOldSchedules();
	void sortSchedule(); // �� ��ǥ���� D-Day�� ���� ������ ����
	bool load(const string& filename); // ���� �ҷ�����
	bool save(const string& filename); // ���� �����ϱ�

private:
	vector<teamMember> members;
	vector<Schedule> schedules;
};
