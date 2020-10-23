#pragma once
#include <Windows.h>

enum Colors {
	BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHT_GRAY, DARK_GRAY,
	LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN, LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE,
};

void set_text_color(int text_color, int background_color);
void gotoxy(int x, int y);
void cursor_view(bool show);

void print_outline();
void print_title();
void print_graph();
void print_main_menu();