#pragma once
#include <string>
#include "calendar.h"

using namespace std;

class Schedule
{
public:
	Schedule();
	Schedule(string name, int year, int month, int day);
	void setSchedule(int year, int month, int day); // �������� ��¥ ����
	void setName(string name);  // �������� �̸� ����
	string getName() const;  // �������� �̸� ��ȯ
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	int* getSchedule() const;  // [��ǥ �⵵, ��ǥ ��, ��ǥ ��]�� int�� �迭 ��ȯ
	int getDDay() const;  // �����ٱ����� ���� ��ȯ

private:
	string name;
	Calendar deadline;
};
