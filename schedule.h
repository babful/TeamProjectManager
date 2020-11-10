#pragma once
#include <string>
#include "calendar.h"

using namespace std;

class Schedule
{
private:
	string name;
	Calendar deadline;

public:
	Schedule();
	Schedule(string name, int year, int month, int day);
	void setSchedule(int year, int month, int day); // �������� ��¥ ����
	void setName(string name);  // �������� �̸� ����
	string getName();  // �������� �̸� ��ȯ
	int* getSchedule();  // [��ǥ �⵵, ��ǥ ��, ��ǥ ��]�� int�� �迭 ��ȯ
	int getDDay();  // �����ٱ����� ���� ��ȯ
};
