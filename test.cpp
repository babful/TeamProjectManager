#include "teamMember.h"
#include "Goal.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
	teamMember member;

	string name;
	string num;
	string role;

	vector<teamMember> Mem;

	int i = 0, n = 0;
	cout << "인원 입력:";
	cin >> n;
	
	for (i = 0; i < n; i++) {
		cout << "이름 입력: ";
		cin >> name;

		cout << "학번 입력: ";
		cin >> num;

		cout << "역할 입력: ";
		cin >> role;

		teamMember Member(name, num, role);
		Mem.push_back(Member);
		cout << "Success" << endl;
	}
	for (int i = 0; i < n; i++) {
		cout << Mem[i].get_Name() << " ";
		cout << Mem[i].get_Number() << " ";
		cout << Mem[i].get_Role() << endl;
	}
	
	return 0;
}