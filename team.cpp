#include "team.h"
#include <cassert>
#include <iostream>   
#include <fstream>
using namespace std;

teamMember& Team::getMember(int idx) { return member.at(idx); }
Schedule& Team::getSchedule(int idx) { return schedules.at(idx); }

int Team::getMemberCnt() const { return member.size(); }
int Team::getScheduleCnt() const { return schedules.size(); }

void Team::addMember(const string& name, const string& number, const string& role) {
	member.push_back(teamMember(name, number, role));
}

void Team::delMember(int idx)
{
	assert(idx < member.size()); // Index Error
	member.erase(member.begin() + idx);
}

void Team::addSchedule(const string& name, int year, int month, int day) {
	schedules.push_back(Schedule(name, year, month, day));
}

void Team::delSchedule(int idx) {
	assert(idx < schedules.size());
	schedules.erase(schedules.begin() + idx);
}

void Team::delOldSchedules() {
	int size = schedules.size();
	for (int i = 0; i < size; ++i) {
		if (schedules[i].getDDay() < 0)
			schedules.erase(schedules.begin() + i);
	}
}

void Team::sortSchedule() {
	delOldSchedules();

	int size = schedules.size();
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (schedules[j].getDDay() > schedules[j + 1].getDDay()) {
				swap(schedules[j], schedules[j + 1]);
			}
		}
	}
}

bool Team::load(string filename) // 파일 읽어오기
{

	ifstream ifs(filename, ifstream::in);

	if (!ifs.good())
		return false;

	int membercount;
	ifs >> membercount;
	ifs.ignore(100, '\n');
	for (int m = 0; m < membercount; m++)
	{
		string Student_Name;
		string Student_Number;
		string Role;
		int clearCount; //달성한 목표 개수
		int goalCount; //목표 개수
		vector<Goal> GoalList;

		getline(ifs, Student_Name);
		getline(ifs, Student_Number);
		getline(ifs, Role);
		this->addMember(Student_Name, Student_Number, Role);
		ifs >> clearCount;

		ifs.ignore(100, '\n');
		ifs >> goalCount;
		ifs.ignore(100, '\n');
		for (int g = 0; g < goalCount; g++)
		{
			Goal goal;
			string context;	// 세부목표의 내용

			int year;
			int month;
			int day;
			int clear;  // 세부목표의 달성 여부
			getline(ifs, context);
			this->getMember(m).add_Goal(goal);
			this->getMember(m).get_Goal(g).set_Context(context);
			ifs >> year >> month >> day;
			this->getMember(m).get_Goal(g).set_Deadline(year, month, day);
			ifs >> clear;
			this->getMember(m).set_Goal_Clear(g, clear);
			ifs.ignore(100, '\n');
		}
	}

	int schedulecount;
	ifs >> schedulecount;
	ifs.ignore(100, '\n');

	for (int s = 0; s < schedulecount; s++)
	{
		string name;
		int year;
		int month;
		int day;
		getline(ifs, name);
		ifs >> year >> month >> day;
		ifs.ignore(100, '\n');
		this->addSchedule(name, year, month, day);
	}

	ifs.close();
	return true;

}

bool Team::save(string filename) // 파일 저장하기
{
	ofstream ofs;

	ofs.open(filename);

	if (!ofs.good())
		return false;

	ofs << this->getMemberCnt() << endl;
	for (int m = 0; m < this->getMemberCnt(); m++)
	{
		ofs << member[m].get_Name() << endl;
		ofs << member[m].get_Number() << endl;
		ofs << member[m].get_Role() << endl;
		ofs << member[m].get_ClearCount() << endl;
		ofs << member[m].get_GoalCount() << endl;

		for (int g = 0; g < member[m].get_GoalCount(); g++)
		{
			ofs << member[m].get_Goal(g).get_Context() << endl;
			ofs << member[m].get_Goal(g).get_Year() << " ";
			ofs << member[m].get_Goal(g).get_Month() << " ";
			ofs << member[m].get_Goal(g).get_Day() << endl;
			int clear = member[m].get_Goal(g).get_Clear();
			ofs << clear << endl;
		}
	}

	ofs << this->getScheduleCnt() << endl;
	for (int s = 0; s < this->getScheduleCnt(); s++)
	{
		ofs << schedules[s].getName() << endl;
		ofs << schedules[s].getYear() << "  ";
		ofs << schedules[s].getMonth() << "  ";
		ofs << schedules[s].getDay() << endl;

	}

	ofs.close();
	return true;
}