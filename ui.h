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
void print_graph(const Team& t);
//void print_main_menu(const Team& t);
void print_schedule(Team& t);
void print_schedule_menu();

int select_main_menu();
int select_schedule_menu();
int select_schedule();
int select_member();

void add_schedule(Team& t);
void modify_schedule(Team& t, int idx);