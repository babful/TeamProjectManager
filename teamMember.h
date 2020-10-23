#pragma once
#include <string>
#define SIZE 32

using namespace std;

class teamMember {
public:
	teamMember();
	teamMember(string Student_Name, string Student_Number, string Role);

	void set_Name(string Student_Name);
	void set_Number(string Student_Number);
	void set_Role(string Role);

	string get_Name();
	string get_Number();
	string get_Role();

private:
	string Student_Name;
	string Student_Number;
	string Role;
};

