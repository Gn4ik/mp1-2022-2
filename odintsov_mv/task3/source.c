#include <stdio.h>
#include <locale.h>
#include <stdlib.h> 
#include <time.h>
#include <math.h>
void main() {
	int n;
	int flag = 1;
	int number,tmp,us_ans;
	int A[10], i;
	int B[10];
	int cow, bull;
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	printf("������� ����:\n");
	printf("����� �������� ����� ������������� ����� � n (�� 2 �� 5).\n");
	printf("��������� ����������� n-������� ����� � ���������������� �������\n");
	printf("����� ������ ������� �������� ����� � ������ n-������� ����� � ���������������� �������.\n");
	printf("��������� ��������, ������� ���� ������� ��� ���������� � �� ��������� � ���������� ����� (�� ���� ���������� �����) � ������� ������� ������ �� ������� � ���������� ����� (�� ���� ���������� �����).\n");
	printf("������� ����� ����� �� 2 �� 5");
	scanf_s(" %i", &n);
	if ((n < 2) || (n > 5)) {
		printf("�������� ������");
	}
	// ��������� ���������� ����� � ���������������� �������
	else{
		while (flag){
			number = rand() % (int)pow(10, n);
			if ((number / (int)pow(10, n-1)) != 0) {
				tmp = number;
				flag = 0;
				for (i = 0; i < 10; i++) {
					A[i]=0;
				}
				for (i = 0; i < n; i++) {
					A[tmp % 10] += 1;
					tmp /= 10;
				}
				for (i = 0; i < 10; i++) {
					if (A[i] > 1) {
						flag = 1;
					}
				}
			}
		}
	}
	while (1) {
		printf("������� �����");
		scanf_s("%i", &us_ans);
		// �������� �� ��, ����� ������������ �� ���� ����� � ����������� ������� 
		tmp = us_ans;
		flag = 1;
		for (i = 0; i < 10; i++) {
			B[i] = 0;
		}
		for (i = 0; i < n; i++) {
			B[tmp % 10] += 1;
			tmp /= 10;
		}
		for (i = 0; i < 10; i++) {
			if (B[i] > 1) {
				flag = 0;
			}
		}
		//���� ����
		if (flag) {
			if (us_ans == number) {
				printf("�� ������ \n");
				break;
			}
			tmp = number;
			cow = 0;
			bull = 0;
			for (i = 0; i < n; i++) {
				if ((us_ans % 10) == (tmp % 10)) {
					bull++;
				}
				else if (A[us_ans % 10] == 1) {
					cow++;
				}
				tmp /= 10;
				us_ans /= 10;
			}
			printf("����� = %i\n", cow);
			printf("����� = %i\n", bull);
		}
		else{
			printf("����� �������� ������������� ����� \n");
		}
	}
system("pause");
}