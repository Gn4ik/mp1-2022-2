#include <stdio.h>
#include <locale.h>
#include <stdlib.h> 
#include <time.h>
void main() {
	int rezim;
	int r1_chislo;
	int r1_ans = 0, r2_ans;
	int r1_counter = 0, r2_counter = 0;
	char us_ans;
	int left = 0, right = 1000;
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	printf("������� ����� 1 ��� 2 \n");
	scanf_s("%i", &rezim);
	if (rezim == 1) {
		r1_chislo = (rand() % 1000) + 1;
		printf("� ������� �����, �������� ��� �������� \n");
		while (1) {
			printf("������� ����� \n");
			scanf_s("%i", &r1_ans);
			r1_counter++;
			if (r1_ans == r1_chislo) {
				printf("�� �������. ���������� ����� = %i", r1_counter);
				break;
			}
			if (r1_ans > r1_chislo) {
				printf("���������� ����� ������ \n");
			}
			if (r1_ans < r1_chislo) {
				printf("���������� ����� ������ \n");
			}
		}
	}
	else {
		printf("������� ����� \n");
		while (1) {
			if ((right-left)%2==0){
				r2_ans = (right + left) / 2;
			}
			else {
				r2_ans = (right + 1 + left) / 2;
			}
			printf("������� 1, ���� ���������� ����� ������, 2, ���� ���������� ����� ������ � 3 ���� �� ����� ����� %i", r2_ans);
			scanf_s(" %c",&us_ans);
			r2_counter += 1;
			if (us_ans == '='  ) {
				printf("������, ���������� ����� = %i", r2_counter);
				break;
			}
			if (us_ans == '<') {
				right = r2_ans;
			}
			if (us_ans == '>') {
				left = r2_ans;
			}
		}
	}
system("pause");
}
