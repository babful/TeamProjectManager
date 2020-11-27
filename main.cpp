#include "ui.h"

int main() {
	system("mode con cols=124 lines=40 | title Team Project Manager"); // �ܼ� â�� ũ�� ���� �� Ÿ��Ʋ ����

	Team t;

	t.load("TPM_Data.txt"); // TPM_Data.txt ���� �ҷ�����

	print_outline();
	print_title();
	while (true) {
		print_graph(t);

		int menu_num = select_main_menu();
		int member_num = 0;
		switch (menu_num) {
		case 0: // ���� ����
			manage_schedule(t);
			break;
		case 1: // ��� ����
			manage_member(t);
			break;
		case 2: // ���θ�ǥ ����
			member_num = select_member();
			if (0 <= member_num && member_num < t.getMemberCnt())
				manage_goal(t, member_num);
			break;
		case 3: // ���α׷� ����
			t.save("TPM_Data.txt"); // TPM_Data.txt ���Ͽ� ����
			return 0;
		}
	}
}