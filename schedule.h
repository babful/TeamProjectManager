#pragma once

class Schedule
{
private:
	int year, month, day;

public:
	Schedule(int year, int month, int day);
	void setSchedule(int year, int month, int day); // 스케줄의 날짜 설정
	int* getSchedule();  // [목표 년도, 목표 달, 목표 일]의 int형 배열 반환
	int getDDay();  // 스케줄까지의 디데이 반환
	int* getToday();  // [현재년도, 현재 월, 현재 일]의 int형 배열 반환
};

