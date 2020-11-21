#include "team.h"
#include <iostream>

int main() {
	Team t1;

	// 멤버 추가
	t1.addMember("C프로그래밍", "2019", "Programming");
	t1.addMember("공학수학1", "2020", "Math");
	t1.addMember("캡스톤", "2022", "Team Based Learning");


	// 스케줄 설정
	t1.getSchedule().setSchedule(2021, 1, 1);
	t1.getSchedule().setName("New Year");


	// 스케줄 내용 출력
	cout << "Schedule Name : " << t1.getSchedule().getName() << endl;
	
	int* schedule = t1.getSchedule().getSchedule();  // 스케줄 날짜를 얻는 두 가지 방법
	cout << "Schedule: " << t1.getSchedule().getYear() << " " << t1.getSchedule().getMonth() << " " << t1.getSchedule().getDay() << endl;
	cout << "Schedule: " << schedule[0] << " " << schedule[1] << " " << schedule[2] << endl;

	cout << "D-Day: " << t1.getSchedule().getDDay() << endl << endl;


	// 멤버 내용 출력
	cout << "멤버 수 : " << t1.getMemberCnt() << endl;
	for (int i = 0; i < t1.getMemberCnt(); ++i) {
		teamMember m = t1.getMember(i);
		cout << m.get_Name() << " " << m.get_Number() << " " << m.get_Role() << endl;
	}


	// 멤버 삭제 및 테스트
	t1.delMember(2);
	cout << endl << "멤버 수 : " << t1.getMemberCnt() << endl;

	for (int i = 0; i < t1.getMemberCnt(); ++i) {
		teamMember m = t1.getMember(i);
		cout << m.get_Name() << " " << m.get_Number() << " " << m.get_Role() << endl;
	}


	// 멤버 별 세부목표 추가
	cout << endl << endl;
	t1.addMember("자료구조실습", "2021", "Team Based Learning");

	t1.getMember(0).add_Goal(Goal("행렬", 2025, 11, 31));
	t1.getMember(0).add_Goal(Goal("선형대수", 2020, 12, 25));
	t1.getMember(0).add_Goal(Goal("운영체제론", 2023, 12, 25));
	t1.getMember(0).add_Goal(Goal("컴퓨팅사고", 2020, 11, 21));
	t1.getMember(1).add_Goal(Goal("게임", 2021, 1, 1));
	t1.getMember(1).add_Goal(Goal("닮다디", 2020, 11, 20, true));
	t1.getMember(2).add_Goal(Goal("나니", 2021, 11, 20, true));
	

	// 가장 급한 목표 출력
	Goal urgent = t1.getUrgentGoal();
	cout << "가장 급한 목표" << endl;
	cout << urgent.get_Context() << " " << urgent.get_Year() << " " << urgent.get_Month() << " " << urgent.get_Day() << endl << endl;


	t1.getMember(0).sort_Goal();
	for (int i = 0; i < t1.getMember(0).get_GoalCount(); ++i) {
		cout << t1.getMember(0).get_Goal_Context(i) << endl;
	}
	return 0;
}
