#include "team.h"
#include <cassert>


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
