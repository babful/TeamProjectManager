#include "ui.h"
#include <iostream>
#include <conio.h>

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

	cout << "┌";
	for (int i = 0; i < 121; ++i)
		cout << "─";
	cout << "┐ \n";

	for (int i = 0; i < 38; ++i) {
		cout << "│";
		for (int j = 0; j < 121; ++j)
			cout << " ";
		cout << "│ \n";
	}

	cout << "└";
	for (int i = 0; i < 121; ++i)
		cout << "─";
	cout << "┘ ";

	gotoxy(3, 8);
	cout << "┌";
	for (int i = 0; i < 115; ++i)
		cout << "─";
	cout << "┐";

	for (int i = 9; i < 38; ++i) {
		gotoxy(3, i);
		cout << "│";
		gotoxy(119, i);
		cout << "│";
	}

	gotoxy(3, 37);
	cout << "└";
	for (int i = 0; i < 115; ++i)
		cout << "─";
	cout << "┘";

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
}
void print_graph() {
	set_text_color(BLACK, WHITE);
	gotoxy(3, 18);
	cout << "├";
	for (int i = 0; i < 115; ++i)
		cout << "─";
	cout << "┤ ";

	gotoxy(98, 20);
	set_text_color(RED, RED);
	cout << "  ";
	set_text_color(BLACK, WHITE);
	cout << " 목표치";

	gotoxy(109, 20);
	set_text_color(BLUE, BLUE);
	cout << "  ";
	set_text_color(BLACK, WHITE);
	cout << " 달성률";

	// UI 구상을 위해 임의적으로 그래프를 그려넣었음.
	// 추후 자동으로 달성률을 계산하여 그래프를 나타내는 함수 구현 예정
	gotoxy(9, 23);
	cout << "멤버 1 : ";
	set_text_color(BLUE, BLUE);
	for (int i = 0; i < 100; ++i)
		cout << " ";
	set_text_color(BLUE, WHITE);
	gotoxy(18, 24);
	cout << "100% 달성 (10/10)";

	set_text_color(BLACK, WHITE);
	gotoxy(9, 26);
	cout << "멤버 2 : ";
	set_text_color(BLUE, BLUE);
	for (int i = 0; i < 100; ++i)
		cout << " ";
	set_text_color(BLUE, WHITE);
	gotoxy(18, 27);
	cout << "100% 달성 (10/10)";

	set_text_color(BLACK, WHITE);
	gotoxy(9, 29);
	cout << "멤버 3 : ";
	set_text_color(BLUE, BLUE);
	for (int i = 0; i < 100; ++i)
		cout << " ";
	set_text_color(BLUE, WHITE);
	gotoxy(18, 30);
	cout << "100% 달성 (10/10)";

	set_text_color(BLACK, WHITE);
	gotoxy(9, 32);
	cout << "멤버 4 : ";
	set_text_color(BLUE, BLUE);
	for (int i = 0; i < 100; ++i)
		cout << " ";
	set_text_color(BLUE, WHITE);
	gotoxy(18, 33);
	cout << "100% 달성 (10/10)";

	gotoxy(73, 35);
	set_text_color(BLUE, WHITE);
	cout << "<중간보고서 제출>";
	set_text_color(BLACK, WHITE);
	cout << " 일정까지 ";
	set_text_color(RED, WHITE);
	cout << "1일 ";
	set_text_color(BLACK, WHITE);
	cout << "남았습니다.";
}
void print_main_menu() {
	print_outline();
	print_title();
	set_text_color(DARK_GRAY, WHITE);

	gotoxy(7, 10);
	cout << "○ 일정 관리";
	gotoxy(7, 12);
	cout << "○ 멤버 관리";
	gotoxy(7, 14);
	cout << "○ 세부목표 관리";
	gotoxy(7, 16);
	cout << "○ 프로그램 종료";

	print_graph();
}

int select_main_menu() {
	int cursor = 0;
	int key_input;

	while (true) {
		set_text_color(DARK_GRAY, WHITE);
		gotoxy(7, 10);
		cout << "○ 일정 관리";
		gotoxy(7, 12);
		cout << "○ 멤버 관리";
		gotoxy(7, 14);
		cout << "○ 세부목표 관리";
		gotoxy(7, 16);
		cout << "○ 프로그램 종료";

		set_text_color(BLACK, WHITE);
		gotoxy(7, 10 + 2 * cursor);
		switch (cursor) {
		case 0:
			cout << "● 일정 관리";
			break;
		case 1:
			cout << "● 멤버 관리";
			break;
		case 2:
			cout << "● 세부목표 관리";
			break;
		case 3:
			cout << "● 프로그램 종료";
			break;
		}

		key_input = _getch();
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
int select_member() {
	int cursor = 0;
	int key_input;
	
	set_text_color(BLACK, WHITE);

	while (true) {
		for (int i = 23; i < 33; i += 3) {
			gotoxy(6, i);
			cout << "  ";
		}

		gotoxy(6, 23 + 3 * cursor);
		cout << "▶";

		key_input = _getch();
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