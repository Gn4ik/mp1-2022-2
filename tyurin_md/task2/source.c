#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

void main() {
	setlocale(LC_ALL, "Russian");
	int robot_number, user_number, attempt, cnt = 1, left = 1, right = 1001;
	int program_mode;
	char op;
	printf("������� ����� ��������� 1 (����� ������������ ����������) ��� 2 (����� ������������ �������������)\n");
	scanf_s("%d", &program_mode);
	switch (program_mode) {
		case 1: 
			srand(time(NULL));
			robot_number = rand() % 1000 + 1;
			printf("�������� �����, ������� �������� ��������� (�� 1 �� 1000)\n");
			while (1) {
				scanf_s("%d", &attempt);
				if (robot_number > attempt) {
					printf("���������� ����� ������ ������\n");
				}
				else if (robot_number < attempt) {
					printf("���������� ����� ������ ������\n");
				}
				else {
					printf("�� ������� ���������� �����, �������!\n");
					break;
				}
				cnt ++;
			}
			printf("�� �������� �������: %d!\n", cnt);
			break;

		case 2: 
			printf("��������� ����� �� 1 �� 1000, ������� ������ �������� ���������\n");
			printf("���� ���� ����� ������ �������������, �� ������� ���� '>', ���� ���� ����� ������ �������������, �� ������� ���� '<', � ���� ���� ����� ����� �������������, �� ������� ���� '='\n");
			printf("���������� ������ ������!\n");
			scanf_s(" %d", &user_number);
			if ((user_number >= 1) && (user_number <= 1000)) {
				printf("� �����, ��� ����� 500\n");
				scanf_s(" %c", &op, 1);
				attempt = 500;
				while (op != '=') {
					if (op == '<') {
						right = attempt;
						attempt = (((attempt - left) / 2) + left);
					}
					else if (op == '>') {
						left = attempt;
						attempt = (((right - attempt) / 2) + attempt);
					}
					else {
						printf("�� ����� ������������ �������,���������� ������ ���� ��� ���!\n");
						cnt--;
					}
					cnt ++;
					printf("� ����� ��� ����� %d\n", attempt);
					scanf_s(" %c", &op, 1);
					
				}
				printf("��������� ������� ���� �����!\n");
				printf("��������� ��������� �������: %d!\n", cnt);
				break;
			}
			else {
				printf("�� �������� ����� �� �� ��������� ���������\n");
				break;
			}


		default:                                                           
			printf("������ ������ �� ����������, �������� 1 ��� 2 �����!\n");
			break;
	}
	system("PAUSE");
}