#include "slrgstr.h"
int new = 1;
int main()
{
	int ch;
	int c,a = 0;
	setlocale(LC_ALL, "Rus");
	system("title ������-�����");
	ShowHelp(new);
	List(new);
	do {
		c = GetCode();
		if (c >= 37) {
			break;
		}
		GiveInfo(c);
		ch = getchar();
	} while (1);
	switch (c) {
	case 37:
		ShowHelp(1);
		List(1);
		new = 0;
		ch = getchar();
		main();
		break;
	case 38:
		printf("������� �� ����� ����� ���������! ����� �������!\n\n");
		system("pause");
		return 0;
		break;
	case 39:
		showCheque();
		system("cls");
		do {
			system("cls");
			printf("������ �� �� ������������ ����� ���?\n");
			printf("1- ��, 2 - ��������� ������, 3 - ������ � ������ �����: ");
			scanf_s("%d", &a);
		} while (a < 1 || a>3);
		switch (a) {
		case 1:
			Restart();
			ch = getchar();
			new = 0;
			main();
			break;
		case 2:
			printf("\n������� �� ����� ����� ���������! ����� �������!\n\n");
			system("pause");
			return 0;
			break;
		case 3:
			ch = getchar();
			new = 0;
			main();
			break;
		default:
			break;
		}
	}
}