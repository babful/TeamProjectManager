#include "team.h"
#include <iostream>

int main() {
	Team t1;

	// ��� �߰�
	t1.addMember("C���α׷���", "2019", "Programming");
	t1.addMember("���м���1", "2020", "Math");
	t1.addMember("ĸ����", "2022", "Team Based Learning");


	// ������ ����
	t1.getSchedule().setSchedule(2021, 1, 1);
	t1.getSchedule().setName("New Year");


	// ������ ���� ���
	cout << "Schedule Name : " << t1.getSchedule().getName() << endl;
	
	int* schedule = t1.getSchedule().getSchedule();  // ������ ��¥�� ��� �� ���� ���
	cout << "Schedule: " << t1.getSchedule().getYear() << " " << t1.getSchedule().getMonth() << " " << t1.getSchedule().getDay() << endl;
	cout << "Schedule: " << schedule[0] << " " << schedule[1] << " " << schedule[2] << endl;

	cout << "D-Day: " << t1.getSchedule().getDDay() << endl << endl;


	// ��� ���� ���
	cout << "��� �� : " << t1.getMemberCnt() << endl;
	for (int i = 0; i < t1.getMemberCnt(); ++i) {
		teamMember m = t1.getMember(i);
		cout << m.get_Name() << " " << m.get_Number() << " " << m.get_Role() << endl;
	}


	// ��� ���� �� �׽�Ʈ
	t1.delMember(2);
	cout << endl << "��� �� : " << t1.getMemberCnt() << endl;

	for (int i = 0; i < t1.getMemberCnt(); ++i) {
		teamMember m = t1.getMember(i);
		cout << m.get_Name() << " " << m.get_Number() << " " << m.get_Role() << endl;
	}


	// ��� �� ���θ�ǥ �߰�
	cout << endl << endl;
	t1.addMember("�ڷᱸ���ǽ�", "2021", "Team Based Learning");

	t1.getMember(0).add_Goal(Goal("���", 2025, 11, 31));
	t1.getMember(0).add_Goal(Goal("�������", 2020, 12, 25));
	t1.getMember(0).add_Goal(Goal("�ü����", 2023, 12, 25));
	t1.getMember(0).add_Goal(Goal("��ǻ�û��", 2020, 11, 21));
	t1.getMember(1).add_Goal(Goal("����", 2021, 1, 1));
	t1.getMember(1).add_Goal(Goal("��ٵ�", 2020, 11, 20, true));
	t1.getMember(2).add_Goal(Goal("����", 2021, 11, 20, true));
	

	// ���� ���� ��ǥ ���
	Goal urgent = t1.getUrgentGoal();
	cout << "���� ���� ��ǥ" << endl;
	cout << urgent.get_Context() << " " << urgent.get_Year() << " " << urgent.get_Month() << " " << urgent.get_Day() << endl << endl;


	t1.getMember(0).sort_Goal();
	for (int i = 0; i < t1.getMember(0).get_GoalCount(); ++i) {
		cout << t1.getMember(0).get_Goal_Context(i) << endl;
	}
	return 0;
}
