#include "ui.h"

int main() {
	system("mode con cols=124 lines=40 | title Team Project Manager"); // 콘솔 창의 크기 조절 및 타이틀 설정

	Team t;

	t.load("TPM_Data.txt"); // TPM_Data.txt 파일 불러오기

	print_outline();
	print_title();
	while (true) {
		print_graph(t);

		int menu_num = select_main_menu();
		int member_num = 0;
		switch (menu_num) {
		case 0: // 일정 관리
			manage_schedule(t);
			break;
		case 1: // 멤버 관리
			manage_member(t);
			break;
		case 2: // 세부목표 관리
			member_num = select_member();
			if (0 <= member_num && member_num < t.getMemberCnt())
				manage_goal(t, member_num);
			break;
		case 3: // 프로그램 종료
			t.save("TPM_Data.txt"); // TPM_Data.txt 파일에 저장
			return 0;
		}
	}
}