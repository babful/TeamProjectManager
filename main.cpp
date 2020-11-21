#include "ui.h"
#include <iostream>
#include <string>

using namespace std;

int main3() {
	string test;
	getline(cin, test);
	cout << test;
	getline(cin, test);
	cout << test;

	return 0;
}

int main() {
	system("mode con cols=124 lines=40 | title Team Project Manager");

	Team t;

	print_outline();
	print_title();
	while (true) {
		print_graph(t);

		int menu_num = select_main_menu();
		switch (menu_num) {
		case 0:
			print_schedule(t);
			break;
		case 1:
			select_member();
			break;
		case 2:
			break;
		case 3:
			return 0;
		}
	}
}