#pragma once
#include <Windows.h>
#include "team.h"

enum Colors {
	BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHT_GRAY, DARK_GRAY,
	LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN, LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE,
};

enum Key {
	ENTER=13, ESC=27, UP=72, DOWN=80,
};

void set_text_color(int text_color, int background_color);
void gotoxy(int x, int y);
void cursor_view(bool show);

void print_outline();
void print_title();
void clear_box();
void print_graph(Team& t);
void print_schedule(Team& t);
void print_schedule_menu();
void print_member_menu();
void manage_member(Team& t);
void print_goal(Team& t, int idx);
void print_goal_menu();

int select_main_menu();
int select_schedule_menu();
int select_schedule();
int select_member_menu();
int select_member();
int select_goal_menu();
int select_goal();

void add_schedule(Team& t);
void modify_schedule(Team& t, int idx);
void add_member(Team& t);
void modify_member(Team& t, int idx);
void add_goal(Team& t, int member_idx);
void modify_goal(Team& t, int member_idx, int goal_idx);
void clear_goal(Team& t, int idx);

bool is_valid_date_input(string date, int* year, int* month, int* day);
bool is_number(string str);
