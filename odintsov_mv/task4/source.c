#include <stdio.h>
#include <locale.h>
#include <string.h>
void main() {
	char Code[4],k;
	int Scan_Code;
	int i,j,ans,tmp,flag_1;
	int flag;
	char check[10]={0,0,0,0,0,0,0,0,0,0};
	char *Base_name[10] = {"������","����","�����","������","��������","����","�������","�����","����","�����"};
	int Base_cost[10] = { 50,30,70,90,150,80,200,250,110,120 };
	char Base_code[10][4] = { {'1','2','1','2'},{'3','3','4','5'},{'0','3','2','1'},{'9','0','9','9'},{'8','7','5','3'},{'9','1','0','1'},{'7','7','2','1'},{'5','5','2','9'},{'4','8','0','8'},{'1','1','7','0'}};
	int Base_discount[10] = { 10,20,5,15,50,40,10,50,10,30 };
	int final_cost = 0;
	setlocale(LC_ALL, "Russian");
	// ���������� � ������� �� ����� � ����� ����� ���������� � exel ������� "������"
	while (1) {
		// ������������ ����
		printf("������� ���� ������ \n");
		for (i = 0; i < 4; i++) {
			scanf_s(" %c", &Code[i]);
		}
		// ����� ������ � ���� ������
		tmp = -1;
		for (i = 0; i < 10; i++) {
			flag_1 = 1;
			for (j = 0; j < 4; j++) {
				k = Base_code[i][j];
				if ( k != Code[j]) {
					flag_1 = 0;
			}
			if (flag_1 == 1) {
				tmp = i;
			}
			}
		}
		if (tmp == -1) {
			printf("������ � ����� ����� ����� ��� � �������\n");
		}
		else {
			//�������� ������
			printf("������� 1, ���� ������ ������ ���������� � ������, � ������ �����, ���� ��� ��� �� �����\n");
			scanf_s("%i", &ans);
			if (ans == 1) {
				printf("�������� ");
				puts(Base_name[tmp]);
				printf("���� = %i\n", Base_cost[tmp]);
				printf("������ = %i\n", Base_discount[tmp]);
			}
			//������� �������� ���������
			final_cost += (int)(Base_cost[tmp]-Base_cost[tmp] * Base_discount[tmp] * 0.01);
			// ���������� ������ � ���
			check[tmp]++;
			// ����� �� ��� �������?
			printf("���� �� ������ ��������� ������� 0, ���� ���, �� ������� ����� ����� \n");
			scanf_s("%i", &flag);
			if (flag == 0) {
				break;
			}
		}
	}
	// ������������ ����
	for (i = 0; i < 10; i++) {
		if (check[i] != 0) {
			puts(Base_name[i]);
			printf("���� = %i, ��������� = %i, ����� ���������=%i\n",Base_cost[i], check[i], (int)(Base_cost[i] * check[i] - Base_cost[i] * check[i] * Base_discount[i] * 0.01));
		}
	}
	printf("����� � ��� %i ������\n", final_cost);
	system("pause");
}