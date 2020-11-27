#include "team.h"
#include <cassert>
#include <fstream>
#include <algorithm>

using namespace std;

teamMember& Team::getMember(int idx) { return members.at(idx); }
Schedule& Team::getSchedule(int idx) { return schedules.at(idx); }

int Team::getMemberCnt() const { return members.size(); }
int Team::getScheduleCnt() const { return schedules.size(); }

void Team::addMember(const teamMember& member) {
	this->members.push_back(member);
}

void Team::addMember(const string& name, const string& number, const string& role) {
	members.push_back(teamMember(name, number, role));
}

void Team::delMember(int idx)
{
	assert(idx < members.size()); // Index Error
	members.erase(members.begin() + idx);
}

void Team::addSchedule(const string& name, int year, int month, int day) {
	schedules.push_back(Schedule(name, year, month, day));
}

void Team::delSchedule(int idx) {
	assert(idx < schedules.size());
	schedules.erase(schedules.begin() + idx);
}

void Team::delOldSchedules() {
	int i = 0;
	while (i < schedules.size()) {
		if (schedules[i].getDDay() < 0) {
			schedules.erase(schedules.begin() + i);
			continue;
		}
		++i;
	}
}

bool Team::load(const string& filename) // 파일 읽어오기
{
	ifstream ifs(filename, ifstream::in);
	if (!ifs.good())
		return false;

	int membercount;
	ifs >> membercount;
	ifs.ignore(100, '\n');

	for (int i = 0; i < membercount; i++) {
		string Student_Name, Student_Number, Role;
		int clearCount, goalCount;

		getline(ifs, Student_Name);
		getline(ifs, Student_Number);
		getline(ifs, Role);

		teamMember member = teamMember(Student_Name, Student_Number, Role);
		ifs >> clearCount;
		ifs.ignore(100, '\n');
		ifs >> goalCount;
		ifs.ignore(100, '\n');
		for (int j = 0; j < goalCount; j++) {
			string context;
			int year, month, day, clear;

			getline(ifs, context);
			ifs >> year >> month >> day >> clear;
			ifs.ignore(100, '\n');

			member.add_Goal(Goal(context, year, month, day, clear));
		}
		member.set_ClearCount(clearCount);
		this->addMember(member);
	}

	int schedulecount;
	ifs >> schedulecount;
	ifs.ignore(100, '\n');

	for (int i = 0; i < schedulecount; i++) {
		string name;
		int year, month, day;
		getline(ifs, name);
		ifs >> year >> month >> day;
		ifs.ignore(100, '\n');
		this->addSchedule(name, year, month, day);
	}

	ifs.close();
	return true;
}

bool Team::save(const string& filename) // 파일 저장하기
{
	ofstream ofs;
	ofs.open(filename);

	if (!ofs.good())
		return false;

	int membercnt = this->getMemberCnt();
	ofs << membercnt << endl;

	for (int i = 0; i < membercnt; i++) {
		teamMember m = members[i];
		ofs << m.get_Name() << endl;
		ofs << m.get_Number() << endl;
		ofs << m.get_Role() << endl;
		ofs << m.get_ClearCount() << endl;
		ofs << m.get_GoalCount() << endl;

		for (int j = 0; j < m.get_GoalCount(); j++) {
			int* deadline = m.get_Goal_deadline(j);
			ofs << m.get_Goal(j).get_Context() << endl;
			ofs << deadline[0] << " " << deadline[1] << " " << deadline[2] << endl;
			ofs << (int)m.get_Goal(j).get_Clear() << endl;
		}
	}

	int schedulecnt = this->getScheduleCnt();
	ofs << schedulecnt << endl;
	for (int i = 0; i < schedulecnt; i++) {
		Schedule s = schedules[i];
		ofs << s.getName() << endl;
		ofs << s.getYear() << "  "  << s.getMonth() << "  " << s.getDay() << endl;
	}

	ofs.close();
	return true;
}

void Team::sortSchedule() {
	delOldSchedules();
	sort(schedules.begin(), schedules.end(), compare_Schedule);
}

bool compare_Schedule(Schedule s1, Schedule s2) {
	return s1.getDDay() < s2.getDDay();
}
