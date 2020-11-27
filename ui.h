#pragma once
#include <Windows.h>
#include "team.h"

enum Colors {
	BLACK=0, BLUE=1, RED=4, DARK_GRAY=8, WHITE=15,
};

enum Key {
	ENTER=13, ESC=27, UP=72, DOWN=80,
};

void set_text_color(int text_color, int background_color); // 텍스트 색 및 배경색 변경
void gotoxy(int x, int y); // 텍스트가 출력될 위치 조정
void cursor_view(bool show); // 커서 깜빡임 on/off

void print_outline(); // 프로그램 UI의 가장 바깥쪽 테두리
void print_title(); // 프로그램의 타이틀 출력

void clear_box(); // UI의 안쪽 상자를 깨끗하게 청소

void print_graph(Team& t); // 프로젝트 진행도를 그래프로 시각화

void manage_schedule(Team& t); // 일정 목록 출력 및 일정 관리 기능 시작
void print_schedule_menu(); // add_schedule, modify_schedule 함수 구현을 위한 부가적인 함수

void manage_member(Team& t); // 멤버 관리 기능 시작
void print_member_menu(); // add_member, modify_member 함수 구현을 위한 부가적인 함수

void manage_goal(Team& t, int idx); // 세부목표 목록 출력 및 세부목표 관리 기능 시작
void print_goal_menu(); // add_goal, modify_goal 함수 구현을 위한 부가적인 함수

int select_main_menu(); // 메인메뉴 항목 선택

int select_schedule_menu(); // 일정 관리 항목 선택
int select_schedule(); // 관리할 일정 선택

int select_member_menu(); // 멤버 관리 항목 선택
int select_member(); // 관리할 멤버 선택

int select_goal_menu(); // 세부목표 관리 항목 선택
int select_goal(); // 관리할 세부목표 선택

void add_schedule(Team& t); // 일정 추가
void modify_schedule(Team& t, int idx); // 일정 수정

void add_member(Team& t); // 멤버 추가
void modify_member(Team& t, int idx); // 멤버 수정

void add_goal(Team& t, int member_idx); // 세부목표 추가
void modify_goal(Team& t, int member_idx, int goal_idx); // 세부목표 수정
void clear_goal(Team& t, int idx); // 달성 여부 관리

bool is_valid_date_input(const string& date, int* year, int* month, int* day); // 마감기한 입력 유효성 검사
bool is_number(const string& str); // 입력한 문자열이 숫자로만 구성됐는지 검사