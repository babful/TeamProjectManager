#include "team.h"
#include <cassert>


teamMember& Team::getMember(int idx) { return member.at(idx); }
Schedule& Team::getSchedule() { return schedule; }

int Team::getMemberCnt() const { return member.size(); }

void Team::addMember(string name, string number, string role) {
	member.push_back(teamMember(name, number, role));
}

int Team::delMember(int idx)
{
	assert(idx < member.size()); // Index Error
	member.erase(member.begin() + idx);
	return 0;  // 昏力 己傍
}

Goal Team::getUrgentGoal()
{
	if (member.size() == 0) return Goal(); // 抗寇贸府!

	vector<teamMember>::iterator it;
	Goal min = member.begin()->get_Urgent_Goal();
	int idx = 0;
	
	for (it = member.begin() + 1; it != member.end(); ++it) {
		if (it->get_Urgent_Goal().get_DDay() < min.get_DDay())
		{
			min = it->get_Urgent_Goal();
			idx = it - member.begin();
		}
	}

	return min;
}
