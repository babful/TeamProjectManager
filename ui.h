#pragma once
#include <Windows.h>
#include "team.h"

enum Colors {
	BLACK=0, BLUE=1, RED=4, DARK_GRAY=8, WHITE=15,
};

enum Key {
	ENTER=13, ESC=27, UP=72, DOWN=80,
};

void set_text_color(int text_color, int background_color); // �ؽ�Ʈ �� �� ���� ����
void gotoxy(int x, int y); // �ؽ�Ʈ�� ��µ� ��ġ ����
void cursor_view(bool show); // Ŀ�� ������ on/off

void print_outline(); // ���α׷� UI�� ���� �ٱ��� �׵θ�
void print_title(); // ���α׷��� Ÿ��Ʋ ���

void clear_box(); // UI�� ���� ���ڸ� �����ϰ� û��

void print_graph(Team& t); // ������Ʈ ���൵�� �׷����� �ð�ȭ

void manage_schedule(Team& t); // ���� ��� ��� �� ���� ���� ��� ����
void print_schedule_menu(); // add_schedule, modify_schedule �Լ� ������ ���� �ΰ����� �Լ�

void manage_member(Team& t); // ��� ���� ��� ����
void print_member_menu(); // add_member, modify_member �Լ� ������ ���� �ΰ����� �Լ�

void manage_goal(Team& t, int idx); // ���θ�ǥ ��� ��� �� ���θ�ǥ ���� ��� ����
void print_goal_menu(); // add_goal, modify_goal �Լ� ������ ���� �ΰ����� �Լ�

int select_main_menu(); // ���θ޴� �׸� ����

int select_schedule_menu(); // ���� ���� �׸� ����
int select_schedule(); // ������ ���� ����

int select_member_menu(); // ��� ���� �׸� ����
int select_member(); // ������ ��� ����

int select_goal_menu(); // ���θ�ǥ ���� �׸� ����
int select_goal(); // ������ ���θ�ǥ ����

void add_schedule(Team& t); // ���� �߰�
void modify_schedule(Team& t, int idx); // ���� ����

void add_member(Team& t); // ��� �߰�
void modify_member(Team& t, int idx); // ��� ����

void add_goal(Team& t, int member_idx); // ���θ�ǥ �߰�
void modify_goal(Team& t, int member_idx, int goal_idx); // ���θ�ǥ ����
void clear_goal(Team& t, int idx); // �޼� ���� ����

bool is_valid_date_input(const string& date, int* year, int* month, int* day); // �������� �Է� ��ȿ�� �˻�
bool is_number(const string& str); // �Է��� ���ڿ��� ���ڷθ� �����ƴ��� �˻�