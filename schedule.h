#pragma once
#include <string>
#include <time.h>

using namespace std;

int* getToday();  // [현재년도, 현재 월, 현재 일]의 int형 배열 반환
bool isLeapYear(int year);  // year가 윤년이라면 true 반환

class Schedule
{
private:
	string name;
	int year, month, day;

public:
	Schedule();
	Schedule(string name, int year, int month, int day);
	void setSchedule(int year, int month, int day); // 스케줄의 날짜 설정
	void setName(string name);  // 스케줄의 이름 설정
	string getName();  // 스케줄의 이름 반환
	int* getSchedule();  // [목표 년도, 목표 달, 목표 일]의 int형 배열 반환
	int getDDay();  // 스케줄까지의 디데이 반환
};
