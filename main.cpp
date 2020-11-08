#include "ui.h"

using namespace std;

int main() {
	system("mode con cols=124 lines=40 | title Team Project Manager");
	print_main_menu();
	while (true) {
		int menu_num = select_main_menu();
		switch (menu_num) {
		case 0:
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