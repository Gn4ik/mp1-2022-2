#include "slrgstr.h"
int new = 1;
int main()
{
	int ch;
	int c,a = 0;
	setlocale(LC_ALL, "Rus");
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
	if (c == 37) {
		ShowHelp(1);
		List(1);
		new = 0;
		ch = getchar();
		main();
	}
	if (c == 38) {
		printf("������� �� ����� ����� ���������! ����� �������!\n\n");
		system("pause");
		return 0;
	}
	if (c == 39) {
		showCheque();
		system("cls");
		do {
			system("cls");
			printf("������ �� �� ������������ ����� ���? 1- ��, 2 - ���: ");
			scanf_s("%d", &a);
		} while (a < 1 || a>2);
		if (a == 1) {
			Restart();
			ch = getchar();
			main();
			new = 0;
		}
		else
			return 0;

	}
	system("pause");
}











/*int c;
int h1, h2, h3, h4;
char barcode[4]="0000", restart[4];
setlocale(LC_ALL, "Rus");
ShowHelp(new);
if (new==1)
	List();
new = 0;
printf("������� ��� ����� �������: ");
scanf_s("%d %d %d %d",&h1,&h2,&h3,&h4);*/
//printf("������� \"cheq\" ��� ������������ ����� ������� ��� \"exit\" ��� ������: ");
//scanf_s("%�", &restart);
//if (restart == "cheq") {
//		Restart();
//		main();
//	}
	//else if (restart == "cheq") {
		//printf("\n\t\t�������� ���\n\t\t");
		//system("pause");
	//}