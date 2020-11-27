#include "ui.h"
#include <iostream>
#include <conio.h>
#include <sstream>

using namespace std;

void set_text_color(int text_color, int background_color) {
	int color = text_color + background_color * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void cursor_view(bool show) {
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void print_outline() {
	set_text_color(BLACK, WHITE);
	cursor_view(false);

	gotoxy(0, 0);
	cout << "��";
	for (int i = 0; i < 121; ++i)
		cout << "��";
	cout << "�� \n";

	for (int i = 0; i < 38; ++i) {
		cout << "��";
		for (int j = 0; j < 121; ++j)
			cout << " ";
		cout << "�� \n";
	}

	cout << "��";
	for (int i = 0; i < 121; ++i)
		cout << "��";
	cout << "�� ";

	gotoxy(3, 8);
	cout << "��";
	for (int i = 0; i < 115; ++i)
		cout << "��";
	cout << "��";

	for (int i = 9; i < 38; ++i) {
		gotoxy(3, i);
		cout << "��";
		gotoxy(119, i);
		cout << "��";
	}

	gotoxy(3, 37);
	cout << "��";
	for (int i = 0; i < 115; ++i)
		cout << "��";
	cout << "��";

	gotoxy(0, 0);
}
void print_title() {
	set_text_color(BLACK, BLACK);
	//print "T"
	gotoxy(4, 2);
	cout << "          ";
	for (int i = 3; i < 7; ++i) {
		gotoxy(8, i);
		cout << "  ";
	}
	//print "P"
	gotoxy(16, 2);
	cout << "          ";
	gotoxy(16, 3);
	cout << "  ";
	gotoxy(24, 3);
	cout << "  ";
	gotoxy(16, 4);
	cout << "          ";
	gotoxy(16, 5);
	cout << "  ";
	gotoxy(16, 6);
	cout << "  ";
	//print "M"
	for (int i = 2; i < 7; ++i) {
		gotoxy(28, i);
		cout << "  ";
	}
	for (int i = 2; i < 7; ++i) {
		gotoxy(36, i);
		cout << "  ";
	}
	gotoxy(30, 3);
	cout << "  ";
	gotoxy(34, 3);
	cout << "  ";
	gotoxy(32, 4);
	cout << "  ";
	//print "Team Project Manager"
	set_text_color(DARK_GRAY, WHITE);
	gotoxy(40, 6);
	cout << "Team Project Manager";

	//print today's date
	int* now = getToday();
	set_text_color(BLACK, WHITE);
	gotoxy(103, 6);
	cout << now[0] << "�� " << now[1] << "�� " << now[2] << "��";
}

void clear_box() {
	set_text_color(BLACK, WHITE);

	gotoxy(3, 8);
	cout << "��";
	for (int i = 0; i < 115; ++i)
		cout << "��";
	cout << "��";

	for (int i = 9; i < 37; ++i) {
		gotoxy(3, i);
		cout << "��";
		for (int j = 0; j < 115; ++j)
			cout << " ";
		cout << "��";
	}

	gotoxy(3, 37);
	cout << "��";
	for (int i = 0; i < 115; ++i)
		cout << "��";
	cout << "��";

	gotoxy(0, 0);
}

void print_graph(Team& t) {
	clear_box();

	set_text_color(BLACK, WHITE);
	gotoxy(3, 18);
	cout << "��";
	for (int i = 0; i < 115; ++i)
		cout << "��";
	cout << "�� ";

	gotoxy(85, 19);
	set_text_color(RED, RED);
	cout << "  ";
	set_text_color(BLACK, WHITE);
	cout << " �޼��� ��ǥġ";

	gotoxy(104, 19);
	set_text_color(BLUE, BLUE);
	cout << "  ";
	set_text_color(BLACK, WHITE);
	cout << " ���� �޼���";

	if (t.getMemberCnt() == 0) {
		set_text_color(DARK_GRAY, WHITE);
		gotoxy(48, 27);
		cout << "���� ��ϵ� ����� �����ϴ�." << endl;
	}
	else {
		int memberCnt = t.getMemberCnt();
		double target_percent, clear_percent;

		for (int i = 0; i < memberCnt; ++i) {
			set_text_color(BLACK, WHITE);
			gotoxy(9, 21 + 4 * i);
			teamMember member = t.getMember(i);
			cout << member.get_Name() << " (" << member.get_Number() << ") - " << member.get_Role();
			if (member.get_GoalCount() == 0) {
				target_percent = 0;
				clear_percent = 0;
			}
			else { // �޼��� ��ǥġ�� ���� �޼����� %�� ���
				target_percent = (double)member.today_GoalCount() / member.get_GoalCount() * 100;
				clear_percent = (double)member.get_ClearCount() / member.get_GoalCount() * 100;
			}

			gotoxy(9, 22 + 4 * i);
			set_text_color(RED, RED); 
			for (int j = 0; j < (int)target_percent; ++j) { // �޼��� ��ǥġ ���
				cout << " ";
			}
			gotoxy(9, 22 + 4 * i);
			set_text_color(BLUE, BLUE);
			for (int j = 0; j < (int)clear_percent; ++j) { // ���� �޼��� ���
				cout << " ";
			}

			string str;

			if (clear_percent < target_percent) {
				set_text_color(RED, WHITE);
				str = "�й��� �ʿ��ؿ� :(";
			}
			else {
				set_text_color(BLUE, WHITE);
				str = "���ϰ� �־�� :)";
			}
			gotoxy(9, 23 + 4 * i);
			cout << (int)clear_percent << "% �޼� (" << member.get_ClearCount() << "/" <<
				member.get_GoalCount() << ") - " << str;
		}
	}

	t.sortSchedule();
	if (t.getScheduleCnt() > 0) { // ���� ����� �ֿ������� D-Day ���
		Schedule urgent = t.getSchedule(0);
		gotoxy(90 - urgent.getName().length(), 35);
		set_text_color(BLUE, WHITE);
		cout << "<" << urgent.getName() << ">";
		set_text_color(BLACK, WHITE);
		cout << " �������� ";
		set_text_color(RED, WHITE);
		cout << urgent.getDDay() << "�� ";
		set_text_color(BLACK, WHITE);
		cout << "���ҽ��ϴ�.";
	}
}

void manage_schedule(Team& t) {
	while (true) {
		clear_box();

		set_text_color(BLACK, WHITE);
		gotoxy(3, 16);
		cout << "��";
		for (int i = 0; i < 115; ++i)
			cout << "��";
		cout << "�� ";

		if (t.getScheduleCnt() == 0) {
			set_text_color(DARK_GRAY, WHITE);
			gotoxy(48, 27);
			cout << "���� ��ϵ� ������ �����ϴ�." << endl;
		}
		else {
			t.sortSchedule();
			int scheduleCnt = t.getScheduleCnt();

			for (int i = 0; i < scheduleCnt; ++i) { // ���� ��� ���
				if (i == 9)
					break;

				gotoxy(9, 18 + 2 * i);
				Schedule schedule = t.getSchedule(i);
				int dday = schedule.getDDay();
				if (dday <= 3)
					set_text_color(RED, WHITE);
				else
					set_text_color(BLUE, WHITE);
				cout << "[D-" << dday << "] ";
				set_text_color(BLACK, WHITE);
				cout << schedule.getName() << " (" << schedule.getYear() << "/" <<
					schedule.getMonth() << "/" << schedule.getDay() << ")";
			}
		}

		int menu_num = select_schedule_menu();
		int schedule_num = 0;
		switch (menu_num) {
		case -1: // ���� ȭ������ �̵�
			return;
		case 0: // ���� �߰�
			add_schedule(t);
			break;
		case 1: // ���� ����
			schedule_num = select_schedule();
			if (0 <= schedule_num && schedule_num < t.getScheduleCnt())
				t.delSchedule(schedule_num);
			break;
		case 2: // ���� ����
			schedule_num = select_schedule();
			if (0 <= schedule_num && schedule_num < t.getScheduleCnt())
				modify_schedule(t, schedule_num);
			break;
		}
	}
}
void print_schedule_menu() {
	clear_box();

	set_text_color(DARK_GRAY, WHITE);

	gotoxy(7, 10);
	cout << "�� ���� �߰�";
	gotoxy(7, 12);
	cout << "�� ���� ����";
	gotoxy(7, 14);
	cout << "�� ���� ����";

	set_text_color(BLACK, WHITE);
	gotoxy(3, 16);
	cout << "��";
	for (int i = 0; i < 115; ++i)
		cout << "��";
	cout << "�� ";
}

void manage_member(Team& t) {
	while (true) {
		print_graph(t);

		int menu_num = select_member_menu();
		int member_num = 0;
		switch (menu_num) {
		case -1: // ���� ȭ������ �̵�
			return;
		case 0: // ��� �߰�
			add_member(t);
			break;
		case 1: // ��� ����
			member_num = select_member();
			if (0 <= member_num && member_num < t.getMemberCnt())
				t.delMember(member_num);
			break;
		case 2: // ��� ����
			member_num = select_member();
			if (0 <= member_num && member_num < t.getMemberCnt())
				modify_member(t, member_num);
			break;
		}
	}
}
void print_member_menu() {
	clear_box();

	set_text_color(DARK_GRAY, WHITE);

	gotoxy(7, 10);
	cout << "�� ��� �߰�";
	gotoxy(7, 13);
	cout << "�� ��� ����";
	gotoxy(7, 16);
	cout << "�� ��� ����";

	set_text_color(BLACK, WHITE);
	gotoxy(3, 18);
	cout << "��";
	for (int i = 0; i < 115; ++i)
		cout << "��";
	cout << "�� ";
}

void manage_goal(Team& t, int idx) {
	while (true) {
		clear_box();

		set_text_color(BLACK, WHITE);
		gotoxy(3, 18);
		cout << "��";
		for (int i = 0; i < 115; ++i)
			cout << "��";
		cout << "�� ";

		t.getMember(idx).sort_Goal();
		teamMember member = t.getMember(idx);

		if (member.get_GoalCount() == 0) {
			set_text_color(DARK_GRAY, WHITE);
			gotoxy(47, 27);
			cout << "���� ��ϵ� ���θ�ǥ�� �����ϴ�." << endl;
		}
		else {
			int goalCnt = member.get_GoalCount();
			for (int i = 0; i < goalCnt; ++i) { // ���θ�ǥ ��� ���
				if (i == 9)
					break;

				int dDay = member.get_Goal(i).get_DDay();

				if (member.get_Goal_Clear(i)) // �޼��� ��ǥ�� ��� �Ķ������� ���
					set_text_color(BLUE, WHITE);
				else if (dDay < 1) // �޼����� ���߰�, ������ ���� ��ǥ�� ��� ������
					set_text_color(RED, WHITE);
				else // �޼����� �������� ������ �����ִ� ��ǥ�� ������
					set_text_color(BLACK, WHITE);

				string dday = " ";
				if (dDay > 0)
					dday = "[D-" + to_string(dDay) + "] ";
				else
					dday = "[D+" + to_string(abs(dDay)) + "] ";

				gotoxy(9, 20 + 2 * i);
				int* deadline = member.get_Goal_deadline(i);
				cout << dday << member.get_Goal_Context(i) << " (~" << deadline[0] << "/" <<
					deadline[1] << "/" << deadline[2] << ")";
			}
		}

		int menu_num = select_goal_menu();
		int goal_num = 0;
		switch (menu_num) {
		case -1: // ���� ȭ������ �̵�
			return;
		case 0: // ���θ�ǥ �߰�
			add_goal(t, idx);
			break;
		case 1: // ���θ�ǥ ����
			goal_num = select_goal();
			if (0 <= goal_num && goal_num < t.getMember(idx).get_GoalCount())
				t.getMember(idx).delete_Goal(goal_num);
			break;
		case 2: // ���θ�ǥ ����
			goal_num = select_goal();
			if (0 <= goal_num && goal_num < t.getMember(idx).get_GoalCount())
				modify_goal(t, idx, goal_num);
			break;
		case 3: // �޼� ���� ����
			clear_goal(t, idx);
			break;
		}
	}
}
void print_goal_menu() {
	clear_box();

	set_text_color(DARK_GRAY, WHITE);

	gotoxy(7, 10);
	cout << "�� ���θ�ǥ �߰�";
	gotoxy(7, 12);
	cout << "�� ���θ�ǥ ����";
	gotoxy(7, 14);
	cout << "�� ���θ�ǥ ����";
	gotoxy(7, 16);
	cout << "�� �޼� ���� ����";

	set_text_color(BLACK, WHITE);
	gotoxy(3, 18);
	cout << "��";
	for (int i = 0; i < 115; ++i)
		cout << "��";
	cout << "�� ";
}

int select_main_menu() {
	int cursor = 0;

	while (true) {
		set_text_color(DARK_GRAY, WHITE);

		gotoxy(7, 10);
		cout << "�� ���� ����";
		gotoxy(7, 12);
		cout << "�� ��� ����";
		gotoxy(7, 14);
		cout << "�� ���θ�ǥ ����";
		gotoxy(7, 16);
		cout << "�� ���α׷� ����";

		set_text_color(BLACK, WHITE);
		gotoxy(7, 10 + 2 * cursor);
		switch (cursor) {
		case 0:
			cout << "�� ���� ����";
			break;
		case 1:
			cout << "�� ��� ����";
			break;
		case 2:
			cout << "�� ���θ�ǥ ����";
			break;
		case 3:
			cout << "�� ���α׷� ����";
			break;
		}

		int key_input = _getch();
		if (key_input == 224) {
			switch (_getch()) {
			case Key::UP:
				if (cursor > 0)
					--cursor;
				break;
			case Key::DOWN:
				if (cursor < 3)
					++cursor;
				break;
			}
		}
		else if (key_input == Key::ENTER)
			return cursor;
	}
}

int select_schedule_menu() {
	int cursor = 0;

	while (true) {
		set_text_color(DARK_GRAY, WHITE);

		gotoxy(7, 10);
		cout << "�� ���� �߰�";
		gotoxy(7, 12);
		cout << "�� ���� ����";
		gotoxy(7, 14);
		cout << "�� ���� ����";

		set_text_color(BLACK, WHITE);
		gotoxy(7, 10 + 2 * cursor);
		switch (cursor) {
		case 0:
			cout << "�� ���� �߰�";
			break;
		case 1:
			cout << "�� ���� ����";
			break;
		case 2:
			cout << "�� ���� ����";
			break;
		}

		int key_input = _getch();
		if (key_input == 224) {
			switch (_getch()) {
			case Key::UP:
				if (cursor > 0)
					--cursor;
				break;
			case Key::DOWN:
				if (cursor < 2)
					++cursor;
				break;
			}
		}
		else if (key_input == Key::ESC)
			return -1;
		else if (key_input == Key::ENTER)
			return cursor;
	}
}
int select_schedule() {
	int cursor = 0;

	set_text_color(BLACK, WHITE);

	while (true) {
		for (int i = 18; i < 35; i += 2) {
			gotoxy(6, i);
			cout << "  ";
		}

		gotoxy(6, 18 + 2 * cursor);
		cout << "��";

		int key_input = _getch();
		if (key_input == 224) {
			switch (_getch()) {
			case Key::UP:
				if (cursor > 0)
					--cursor;
				break;
			case Key::DOWN:
				if (cursor < 8)
					++cursor;
				break;
			}
		}
		else if (key_input == Key::ENTER)
			return cursor;
		else if (key_input == Key::ESC)
			return -1;
	}
}

int select_member_menu() {
	int cursor = 0;

	while (true) {
		set_text_color(DARK_GRAY, WHITE);

		gotoxy(7, 10);
		cout << "�� ��� �߰�";
		gotoxy(7, 12);
		cout << "               ";
		gotoxy(7, 13);
		cout << "�� ��� ����";
		gotoxy(7, 14);
		cout << "               ";
		gotoxy(7, 16);
		cout << "�� ��� ����   ";

		set_text_color(BLACK, WHITE);
		gotoxy(7, 10 + 3 * cursor);
		switch (cursor) {
		case 0:
			cout << "�� ��� �߰�";
			break;
		case 1:
			cout << "�� ��� ����";
			break;
		case 2:
			cout << "�� ��� ����";
			break;
		}

		int key_input = _getch();
		if (key_input == 224) {
			switch (_getch()) {
			case Key::UP:
				if (cursor > 0)
					--cursor;
				break;
			case Key::DOWN:
				if (cursor < 2)
					++cursor;
				break;
			}
		}
		else if (key_input == Key::ESC)
			return -1;
		else if (key_input == Key::ENTER)
			return cursor;
	}
}
int select_member() {
	int cursor = 0;
	
	set_text_color(BLACK, WHITE);

	while (true) {
		for (int i = 21; i < 34; i += 4) {
			gotoxy(6, i);
			cout << "  ";
		}

		gotoxy(6, 21 + 4 * cursor);
		cout << "��";

		int key_input = _getch();
		if (key_input == 224) {
			switch (_getch()) {
			case Key::UP:
				if (cursor > 0)
					--cursor;
				break;
			case Key::DOWN:
				if (cursor < 3)
					++cursor;
				break;
			}
		}
		else if (key_input == Key::ENTER)
			return cursor;
		else if (key_input == Key::ESC)
			return -1;
	}
}

int select_goal_menu() {
	int cursor = 0;

	while (true) {
		set_text_color(DARK_GRAY, WHITE);

		gotoxy(7, 10);
		cout << "�� ���θ�ǥ �߰�";
		gotoxy(7, 12);
		cout << "�� ���θ�ǥ ����";
		gotoxy(7, 14);
		cout << "�� ���θ�ǥ ����";
		gotoxy(7, 16);
		cout << "�� �޼� ���� ����";

		set_text_color(BLACK, WHITE);
		gotoxy(7, 10 + 2 * cursor);
		switch (cursor) {
		case 0:
			cout << "�� ���θ�ǥ �߰�";
			break;
		case 1:
			cout << "�� ���θ�ǥ ����";
			break;
		case 2:
			cout << "�� ���θ�ǥ ����";
			break;
		case 3:
			cout << "�� �޼� ���� ����";
			break;
		}

		int key_input = _getch();
		if (key_input == 224) {
			switch (_getch()) {
			case Key::UP:
				if (cursor > 0)
					--cursor;
				break;
			case Key::DOWN:
				if (cursor < 3)
					++cursor;
				break;
			}
		}
		else if (key_input == Key::ENTER)
			return cursor;
		else if (key_input == Key::ESC)
			return -1;
	}
}
int select_goal() {
	int cursor = 0;

	set_text_color(BLACK, WHITE);

	while (true) {
		for (int i = 20; i < 37; i += 2) {
			gotoxy(6, i);
			cout << "  ";
		}

		gotoxy(6, 20 + 2 * cursor);
		cout << "��";

		int key_input = _getch();
		if (key_input == 224) {
			switch (_getch()) {
			case Key::UP:
				if (cursor > 0)
					--cursor;
				break;
			case Key::DOWN:
				if (cursor < 8)
					++cursor;
				break;
			}
		}
		else if (key_input == Key::ENTER)
			return cursor;
		else if (key_input == Key::ESC)
			return -1;
	}
}

void add_schedule(Team& t) {
	while (true) {
		string name, date;
		int year = 0, month = 0, day = 0;
		char yn = 0;

		print_schedule_menu();
		set_text_color(BLACK, WHITE);
		gotoxy(7, 10);
		cout << "�� ���� �߰�";
		
		set_text_color(DARK_GRAY, WHITE);
		gotoxy(6, 21);
		cout << "�� �������� : ";
		gotoxy(7, 22);
		cout << "(�Է� ���� : 2020 11 21)";

		cursor_view(true);
		while (true) {
			set_text_color(BLACK, WHITE);
			gotoxy(6, 18);
			cout << "�� ���� :                                                                                                        ��  �� ";
			gotoxy(0, 19);
			cout << "��  ��                                                                                                           ";
			gotoxy(16, 18);
			getline(cin, name);

			if (name.length() < 1) {
				gotoxy(6, 24);
				cout << "                                                                    ";
				gotoxy(6, 24);
				set_text_color(RED, WHITE);
				cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else if (50 < name.length()) {
				gotoxy(6, 24);
				set_text_color(RED, WHITE);
				cout << "������ �ִ� 50�ڱ����� �Է��� �� �ֽ��ϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else break;
		}
		gotoxy(6, 18);
		cout << "�� ";
		
		while (true) {
			set_text_color(BLACK, WHITE);
			gotoxy(6, 21);
			cout << "�� �������� :                                                                  ";
			gotoxy(20, 21);
			getline(cin, date);

			if (!is_valid_date_input(date, &year, &month, &day)) {
				gotoxy(6, 24);
				set_text_color(RED, WHITE);
				cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else
				break;
		}
		set_text_color(BLACK, WHITE);
		gotoxy(6, 21);
		cout << "�� ";

		gotoxy(6, 24);
		cout << "                                                                    ";
		while (true) {
			gotoxy(6, 24);
			cout << "�� ������ �߰��Ͻðڽ��ϱ�? (Y/N) :          ";
			gotoxy(42, 24);
			cin >> yn;

			if (yn == 'Y' || yn == 'y') {
				t.addSchedule(name, year, month, day);
				cursor_view(false);
				getchar();
				return;
			}
			else if (yn == 'N' || yn == 'n') {
				cursor_view(false);
				getchar();
				return;
			}
			else
				continue;
		}
	}
}
void modify_schedule(Team& t, int idx) {
	while (true) {
		string name, date;
		int year = 0, month = 0, day = 0;
		char yn = 0;

		print_schedule_menu();
		set_text_color(BLACK, WHITE);
		gotoxy(7, 14);
		cout << "�� ���� ����";

		set_text_color(DARK_GRAY, WHITE);
		gotoxy(6, 21);
		cout << "�� �������� : ";
		gotoxy(7, 22);
		cout << "(�Է� ���� : 2020 11 21)";

		cursor_view(true);
		while (true) {
			set_text_color(BLACK, WHITE);
			gotoxy(6, 18);
			cout << "�� ���� :                                                                                                        ��  �� ";
			gotoxy(0, 19);
			cout << "��  ��                                                                                                           ";
			gotoxy(16, 18);
			getline(cin, name);

			if (name.length() < 1) {
				gotoxy(6, 24);
				cout << "                                                                    ";
				gotoxy(6, 24);
				set_text_color(RED, WHITE);
				cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else if (50 < name.length()) {
				gotoxy(6, 24);
				set_text_color(RED, WHITE);
				cout << "������ �ִ� 50�ڱ����� �Է��� �� �ֽ��ϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else break;
		}
		gotoxy(6, 18);
		cout << "�� ";

		while (true) {
			set_text_color(BLACK, WHITE);
			gotoxy(6, 21);
			cout << "�� �������� :                                                                  ";
			gotoxy(20, 21);
			getline(cin, date);

			if (!is_valid_date_input(date, &year, &month, &day)) {
				gotoxy(6, 24);
				set_text_color(RED, WHITE);
				cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else
				break;
		}
		set_text_color(BLACK, WHITE);
		gotoxy(6, 21);
		cout << "�� ";

		gotoxy(6, 24);
		cout << "                                                                    ";
		while (true) {
			gotoxy(6, 24);
			cout << "�� ������ �����Ͻðڽ��ϱ�? (Y/N) :          ";
			gotoxy(42, 24);
			cin >> yn;

			if (yn == 'Y' || yn == 'y') {
				t.getSchedule(idx).setName(name);
				t.getSchedule(idx).setSchedule(year, month, day);
				cursor_view(false);
				getchar();
				return;
			}
			else if (yn == 'N' || yn == 'n') {
				cursor_view(false);
				getchar();
				return;
			}
			else
				continue;
		}
	}
}

void add_member(Team& t) {
	while (true) {
		string name, number, role;
		char yn = 0;

		print_member_menu();
		set_text_color(BLACK, WHITE);
		gotoxy(7, 10);
		cout << "�� ��� �߰�";

		set_text_color(DARK_GRAY, WHITE);
		gotoxy(6, 22);
		cout << "�� �й� : ";
		gotoxy(6, 24);
		cout << "�� ���� : ";

		cursor_view(true);
		while (true) {
			set_text_color(BLACK, WHITE);
			gotoxy(6, 20);
			cout << "�� �̸� :                                                                                                        ��  �� ";
			gotoxy(0, 21);
			cout << "��  ��                                                                                                           ";
			gotoxy(16, 20);
			getline(cin, name);

			if (name.length() < 1) {
				gotoxy(6, 26);
				cout << "                                                                    ";
				gotoxy(6, 26);
				set_text_color(RED, WHITE);
				cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else if (20 < name.length()) {
				gotoxy(6, 26);
				set_text_color(RED, WHITE);
				cout << "�̸��� �ִ� 20�ڱ����� �Է��� �� �ֽ��ϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else break;
		}
		gotoxy(6, 20);
		cout << "�� ";

		while (true) {
			set_text_color(BLACK, WHITE);
			gotoxy(6, 22);
			cout << "�� �й� :                                                                                                        ��  �� ";
			gotoxy(0, 23);
			cout << "��  ��                                                                                                           ";
			gotoxy(16, 22);
			getline(cin, number);

			if (!is_number(number) || number.length() < 1) {
				gotoxy(6, 26);
				cout << "                                                                    ";
				gotoxy(6, 26);
				set_text_color(RED, WHITE);
				cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else if (20 < number.length()) {
				gotoxy(6, 26);
				set_text_color(RED, WHITE);
				cout << "�й��� �ִ� 20�ڱ����� �Է��� �� �ֽ��ϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else break;
		}
		gotoxy(6, 22);
		cout << "�� ";

		while (true) {
			set_text_color(BLACK, WHITE);
			gotoxy(6, 24);
			cout << "�� ���� :                                                                                                        ��  �� ";
			gotoxy(0, 25);
			cout << "��  ��                                                                                                           ";
			gotoxy(16, 24);
			getline(cin, role);

			if (role.length() < 1) {
				gotoxy(6, 26);
				cout << "                                                                    ";
				gotoxy(6, 26);
				set_text_color(RED, WHITE);
				cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else if (50 < role.length()) {
				gotoxy(6, 26);
				set_text_color(RED, WHITE);
				cout << "������ �ִ� 50�ڱ����� �Է��� �� �ֽ��ϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else break;
		}
		gotoxy(6, 24);
		cout << "�� ";

		gotoxy(6, 26);
		cout << "                                                                    ";
		while (true) {
			gotoxy(6, 26);
			cout << "�� ����� �߰��Ͻðڽ��ϱ�? (Y/N) :          ";
			gotoxy(42, 26);
			cin >> yn;

			if (yn == 'Y' || yn == 'y') {
				t.addMember(name, number, role);
				cursor_view(false);
				getchar();
				return;
			}
			else if (yn == 'N' || yn == 'n') {
				cursor_view(false);
				getchar();
				return;
			}
			else
				continue;
		}
	}
}
void modify_member(Team& t, int idx) {
	while (true) {
		string name, number, role;
		char yn = 0;

		print_member_menu();
		set_text_color(BLACK, WHITE);
		gotoxy(7, 16);
		cout << "�� ��� ����";

		set_text_color(DARK_GRAY, WHITE);
		gotoxy(6, 22);
		cout << "�� �й� : ";
		gotoxy(6, 24);
		cout << "�� ���� : ";

		cursor_view(true);
		while (true) {
			set_text_color(BLACK, WHITE);
			gotoxy(6, 20);
			cout << "�� �̸� :                                                                                                        ��  �� ";
			gotoxy(0, 21);
			cout << "��  ��                                                                                                           ";
			gotoxy(16, 20);
			getline(cin, name);

			if (name.length() < 1) {
				gotoxy(6, 26);
				cout << "                                                                    ";
				gotoxy(6, 26);
				set_text_color(RED, WHITE);
				cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else if (20 < name.length()) {
				gotoxy(6, 26);
				set_text_color(RED, WHITE);
				cout << "�̸��� �ִ� 20�ڱ����� �Է��� �� �ֽ��ϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else break;
		}
		gotoxy(6, 20);
		cout << "�� ";

		while (true) {
			set_text_color(BLACK, WHITE);
			gotoxy(6, 22);
			cout << "�� �й� :                                                                                                        ��  �� ";
			gotoxy(0, 23);
			cout << "��  ��                                                                                                           ";
			gotoxy(16, 22);
			getline(cin, number);

			if (!is_number(number) || number.length() < 1) {
				gotoxy(6, 26);
				cout << "                                                                    ";
				gotoxy(6, 26);
				set_text_color(RED, WHITE);
				cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else if (20 < number.length()) {
				gotoxy(6, 26);
				set_text_color(RED, WHITE);
				cout << "�й��� �ִ� 20�ڱ����� �Է��� �� �ֽ��ϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else break;
		}
		gotoxy(6, 22);
		cout << "�� ";

		while (true) {
			set_text_color(BLACK, WHITE);
			gotoxy(6, 24);
			cout << "�� ���� :                                                                                                        ��  �� ";
			gotoxy(0, 25);
			cout << "��  ��                                                                                                           ";
			gotoxy(16, 24);
			getline(cin, role);

			if (role.length() < 1) {
				gotoxy(6, 26);
				cout << "                                                                    ";
				gotoxy(6, 26);
				set_text_color(RED, WHITE);
				cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else if (50 < role.length()) {
				gotoxy(6, 26);
				set_text_color(RED, WHITE);
				cout << "������ �ִ� 50�ڱ����� �Է��� �� �ֽ��ϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else break;
		}
		gotoxy(6, 24);
		cout << "�� ";

		gotoxy(6, 26);
		cout << "                                                                    ";
		while (true) {
			gotoxy(6, 26);
			cout << "�� ����� �����Ͻðڽ��ϱ�? (Y/N) :          ";
			gotoxy(42, 26);
			cin >> yn;

			if (yn == 'Y' || yn == 'y') {
				t.getMember(idx).set_Name(name);
				t.getMember(idx).set_Number(number);
				t.getMember(idx).set_Role(role);
				cursor_view(false);
				getchar();
				return;
			}
			else if (yn == 'N' || yn == 'n') {
				cursor_view(false);
				getchar();
				return;
			}
			else
				continue;
		}
	}
}

void add_goal(Team& t, int member_idx) {
	while (true) {
		string name, date;
		int year = 0, month = 0, day = 0;
		char yn = 0;

		print_goal_menu();
		set_text_color(BLACK, WHITE);
		gotoxy(7, 10);
		cout << "�� ���θ�ǥ �߰�";

		set_text_color(DARK_GRAY, WHITE);
		gotoxy(6, 23);
		cout << "�� �������� : ";
		gotoxy(7, 24);
		cout << "(�Է� ���� : 2020 11 21)";

		cursor_view(true);
		while (true) {
			set_text_color(BLACK, WHITE);
			gotoxy(6, 20);
			cout << "�� ���� :                                                                                                        ��  �� ";
			gotoxy(0, 21);
			cout << "��  ��                                                                                                           ";
			gotoxy(16, 20);
			getline(cin, name);

			if (name.length() < 1) {
				gotoxy(6, 26);
				cout << "                                                                    ";
				gotoxy(6, 26);
				set_text_color(RED, WHITE);
				cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else if (50 < name.length()) {
				gotoxy(6, 26);
				set_text_color(RED, WHITE);
				cout << "������ �ִ� 50�ڱ����� �Է��� �� �ֽ��ϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else break;
		}
		gotoxy(6, 20);
		cout << "�� ";

		while (true) {
			set_text_color(BLACK, WHITE);
			gotoxy(6, 23);
			cout << "�� �������� :                                                                  ";
			gotoxy(20, 23);
			getline(cin, date);

			if (!is_valid_date_input(date, &year, &month, &day)) {
				gotoxy(6, 26);
				set_text_color(RED, WHITE);
				cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else
				break;
		}
		set_text_color(BLACK, WHITE);
		gotoxy(6, 23);
		cout << "�� ";

		gotoxy(6, 26);
		cout << "                                                                    ";
		while (true) {
			gotoxy(6, 26);
			cout << "�� ���θ�ǥ�� �߰��Ͻðڽ��ϱ�? (Y/N) :          ";
			gotoxy(46, 26);
			cin >> yn;

			if (yn == 'Y' || yn == 'y') {
				t.getMember(member_idx).add_Goal(Goal(name, year, month, day));
				cursor_view(false);
				getchar();
				return;
			}
			else if (yn == 'N' || yn == 'n') {
				cursor_view(false);
				getchar();
				return;
			}
			else
				continue;
		}
	}
}
void modify_goal(Team& t, int member_idx, int goal_idx) {
	while (true) {
		string name, date;
		int year = 0, month = 0, day = 0;
		char yn = 0;

		print_goal_menu();
		set_text_color(BLACK, WHITE);
		gotoxy(7, 14);
		cout << "�� ���θ�ǥ ����";

		set_text_color(DARK_GRAY, WHITE);
		gotoxy(6, 23);
		cout << "�� �������� : ";
		gotoxy(7, 24);
		cout << "(�Է� ���� : 2020 11 21)";

		cursor_view(true);
		while (true) {
			set_text_color(BLACK, WHITE);
			gotoxy(6, 20);
			cout << "�� ���� :                                                                                                        ��  �� ";
			gotoxy(0, 21);
			cout << "��  ��                                                                                                           ";
			gotoxy(16, 20);
			getline(cin, name);

			if (name.length() < 1) {
				gotoxy(6, 26);
				cout << "                                                                    ";
				gotoxy(6, 26);
				set_text_color(RED, WHITE);
				cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else if (50 < name.length()) {
				gotoxy(6, 26);
				set_text_color(RED, WHITE);
				cout << "������ �ִ� 50�ڱ����� �Է��� �� �ֽ��ϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else break;
		}
		gotoxy(6, 20);
		cout << "�� ";

		while (true) {
			set_text_color(BLACK, WHITE);
			gotoxy(6, 23);
			cout << "�� �������� :                                                                  ";
			gotoxy(20, 23);
			getline(cin, date);

			if (!is_valid_date_input(date, &year, &month, &day)) {
				gotoxy(6, 26);
				set_text_color(RED, WHITE);
				cout << "��ȿ���� ���� �Է��Դϴ�. �ٽ� �Է��� �ּ���.";
				continue;
			}
			else
				break;
		}
		set_text_color(BLACK, WHITE);
		gotoxy(6, 23);
		cout << "�� ";

		gotoxy(6, 26);
		cout << "                                                                    ";
		while (true) {
			gotoxy(6, 26);
			cout << "�� ���θ�ǥ�� �����Ͻðڽ��ϱ�? (Y/N) :          ";
			gotoxy(46, 26);
			cin >> yn;

			if (yn == 'Y' || yn == 'y') {
				t.getMember(member_idx).get_Goal(goal_idx).set_Context(name);
				t.getMember(member_idx).get_Goal(goal_idx).set_Deadline(year, month, day);
				cursor_view(false);
				getchar();
				return;
			}
			else if (yn == 'N' || yn == 'n') {
				cursor_view(false);
				getchar();
				return;
			}
			else
				continue;
		}
	}
}
void clear_goal(Team& t, int idx) {
	int cursor = 0;
	bool change[9];
	memset(change, false, 9);

	set_text_color(DARK_GRAY, WHITE);
	gotoxy(67, 10);
	cout << "S Ű �Է� �� �׸� ����, ENTER Ű �Է� �� �ϰ� ����";
	set_text_color(BLACK, WHITE);

	while (true) {
		for (int i = 0; i < 9; ++i) {
			gotoxy(6, 20 + 2 * i);
			if (change[i])
				cout << " *";
			else
				cout << "  ";
		}

		gotoxy(6, 20 + 2 * cursor);
		cout << "��";

		int key_input = _getch();
		if (key_input == 224) {
			switch (_getch()) {
			case Key::UP:
				if (cursor > 0)
					--cursor;
				break;
			case Key::DOWN:
				if (cursor < 8)
					++cursor;
				break;
			}
		}
		else if (key_input == 's' || key_input == 'S') {
			if (cursor < t.getMember(idx).get_GoalCount()) {
				t.getMember(idx).set_Goal_Clear(cursor, !t.getMember(idx).get_Goal_Clear(cursor));
				change[cursor] = !change[cursor];
			}
		}
		else if (key_input == Key::ESC || key_input == Key::ENTER)
			return;
	}
}

bool is_valid_date_input(const string& date, int* year, int* month, int* day) {
	vector<string> tokens;
	string token;
	stringstream ss(date);

	while (getline(ss, token, ' ')) {
		tokens.push_back(token);
	}

	if (tokens.size() != 3) return false;

	if (is_number(tokens[0]))
		*year = stoi(tokens[0]);
	else return false;

	if (is_number(tokens[1]))
		*month = stoi(tokens[1]);
	else return false;

	if (is_number(tokens[2]))
		*day = stoi(tokens[2]);
	else return false;

	return isValidDate(*year, *month, *day);
}
bool is_number(const string& str) {
	int len = str.length();
	for (int i = 0; i < len; ++i) {
		if (!('0' <= str[i] && str[i] <= '9'))
			return false;
	}

	return true;
}