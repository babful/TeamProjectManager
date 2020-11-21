#include "ui.h"

using namespace std;

int main() {
	system("mode con cols=124 lines=40 | title Team Project Manager");

	Team t;

	print_outline();
	print_title();
	while (true) {
		print_graph(t);

		int menu_num = select_main_menu();
		int member_num = 0;
		switch (menu_num) {
		case 0:
			print_schedule(t);
			break;
		case 1:
			manage_member(t);
			break;
		case 2:
			member_num = select_member();
			if (0 <= member_num && member_num < t.getMemberCnt())
				print_goal(t, member_num);
			break;
		case 3:
			return 0;
		}
	}
}