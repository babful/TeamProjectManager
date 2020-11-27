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
	Schedule& getSchedule(int idx);  // 일정에게 접근
	int getMemberCnt() const;  // 팀의 멤버 수 반환
	int getScheduleCnt() const; 
	void addMember(const teamMember& member);
	void addMember(const string& name, const string& number, const string& role);
	void delMember(int idx);
	void addSchedule(const string& name, int year, int month, int day);
	void delSchedule(int idx);
	void delOldSchedules(); // 기한이 지난 일정들을 모두 삭제
	bool load(const string& filename); // 파일 불러오기
	bool save(const string& filename); // 파일 저장하기
	void sortSchedule(); // 일정들을 D-Day가 작은 순으로 정렬

private:
	vector<teamMember> members;
	vector<Schedule> schedules;
};

bool compare_Schedule(Schedule s1, Schedule s2); // sortSchedule 함수의 정렬 기준
