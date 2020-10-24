#pragma once
#include <string>

using namespace std;

class Detail
{
private:
	string context; // 세부목표의 내용
	bool cleared;  // 세부목표의 달성 여부

public:
	Detail(string context, bool cleared);
	void setContext(string context);  // context를 설정
	void setCleared(bool cleared);  // cleared 설정
	string getContext();  // context를 반환
	bool is_Cleared();  // cleared를 반환
};