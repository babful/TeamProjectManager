#pragma once
#include <string>
#include "calendar.h"

using namespace std;

class Schedule
{
public:
	Schedule();
	Schedule(const string& name, int year, int month, int day);
	void setSchedule(int year, int month, int day); // 스케줄의 날짜 설정
	void setName(const string& name);  // 스케줄의 이름 설정
	string getName() const;  // 스케줄의 이름 반환
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	int* getSchedule() const;  // [목표 년도, 목표 달, 목표 일]의 int형 배열 반환
	int getDDay() const;  // 스케줄까지의 디데이 반환

private:
	string name;
	Calendar deadline;
};