#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define c_size 5
void main()
{
	int length, number_enter, check_number, c_digits, n, bulls, cows, match, computer[c_size], digit, i = 1, j = 0, c, end;
	setlocale(LC_ALL, "Rus");
	printf("������� ����� ������������� ����� (2<=n<=5): ");
	scanf_s("%d", &length);
	if ((length < 2) || (length > 5))
		printf("������� ������������ �����, ����� ������ ���� �� 2 �� 5");
	srand(time(NULL));
	digit = (1 + rand() % 9);
	computer[0] = digit;
	do {
		digit = -1;
		while (digit == -1) {
			digit = rand() % 10;
			if ((digit != computer[0]) && (digit != computer[1]) && (digit != computer[2]) && (digit != computer[3]) && (digit != computer[04]))
				computer[i] = digit;
			else
				digit = -1;
		}
		i ++;
	} while (i < length);
	//while (j < length)
		//printf("%d", computer[j++]);//����� ������������� �����
	while (1) {
		printf("\n���������� ������� ����� �������� ����� � ������� ��� (��� ����� ����� ��������): ");
		scanf_s("%d", &number_enter);
		check_number = number_enter;
		c_digits = 0;
		while (check_number > 0) {
			c_digits ++;
			check_number /= 10;
		}
		if (c_digits != length) {
			printf("������� ����� ���������������� �����, �������� �����: %d ", length);
			break;
		}
		//������� ���������� "�����" (������ ����������)
		n = number_enter;
		c = 0;
		bulls = 0;
		cows = 0;
		match = 0;
		while (n > 0) {
			c += 1;
			if ((n % 10) == computer[length - c]) {
				bulls += 1;
				n /= 10;
			}
			else
				n = n / 10;
		}
		if (bulls == length) {
			printf("�� ������� �����!\n");
			break;
		}
		else {
			//������� ����� ���������� ����������
			n = number_enter;
			while (n > 0) {
				if (((n % 10) == computer[0]) || ((n % 10) == computer[1]) || ((n % 10) == computer[2]) || ((n % 10) == computer[3]) || ((n % 10) == computer[4])) {
					match += 1;
					n /= 10;
				}
				else
					n /= 10;
			}
			//������� ���������� "�����" (�����, ��������� ��� ����������� �������)
			cows = match - bulls;
			printf("\n���������� '�����' (������ ����������) : % d", bulls);
			printf("\n���������� '�����' (���������� ��� ������������ �������) : % d", cows);
		}
		printf("\n����� ���������� ������� ������� 1, ���� �� ������ ������� � ��������� ����, ������� 0: ");
		scanf_s("%d", &end);
		if (end == 0)
			break;
	}
	system("pause");
}