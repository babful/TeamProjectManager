#include "teamMember.h"
#include <string>
#include <vector>

teamMember::teamMember() {
	this->Student_Name = "";
	this->Student_Number = "";
	this->Role = "";
}
teamMember::teamMember(string Student_Name, string Student_Number, string Role) {
	this->Student_Name = Student_Name;
	this->Student_Number = Student_Number;
	this->Role = Role;
}
void teamMember::set_Name(string Student_Name) {
	this->Student_Name = Student_Name;
}
void teamMember::set_Number(string Student_Number) {
	this->Student_Number = Student_Number;
}
void teamMember::set_Role(string Role) {
	this->Role = Role;
}

string teamMember::get_Name() {
	return this->Student_Name;
}
string teamMember::get_Number() {
	return this->Student_Number;
}
string teamMember::get_Role() {
	return this->Role;
}