#include "team.h"
#include <cassert>


teamMember& Team::getMember(int idx) { return member.at(idx); }
Schedule& Team::getSchedule(int idx) { return schedules.at(idx); }

int Team::getMemberCnt() const { return member.size(); }
int Team::getScheduleCnt() const { return schedules.size(); }

void Team::addMember(string name, string number, string role) {
	member.push_back(teamMember(name, number, role));
}

int Team::delMember(int idx)
{
	assert(idx < member.size()); // Index Error
	member.erase(member.begin() + idx);
	return 0;  // 삭제 성공
}

void Team::addSchedule(string name, int year, int month, int day) {
	schedules.push_back(Schedule(name, year, month, day));
}

int Team::delSchedule(int idx) {
	assert(idx < schedules.size());
	schedules.erase(schedules.begin() + idx);
	return 0;
}

int Team::delOldSchedules() {
	for (int i = 0; i < schedules.size(); ++i) {
		if (schedules[i].getDDay() < 0)
			schedules.erase(schedules.begin() + i);
	}
	return 0;
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
