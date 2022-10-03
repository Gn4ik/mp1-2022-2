#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

void main() 
{
	setlocale(LC_ALL, "Rus");

	int botnumber, version, count_of_try = 1, usernumber = 0, count_of_computer = 1;
	int min = 1, max = 1000;
	char comp;
	printf("������� ����� ������ ����(1 - ���������� ��, 2 - ��������� ���������): ");
	scanf_s("%i", &version);
	const int RANDOM_MAX = 1000;
	const int RAND_MIN = 1;


	if (version == 1) {
		srand(time(0));
		botnumber = RAND_MIN + (rand() % RANDOM_MAX);
		//printf("%i", botnumber); �������� �����
		printf("���������� ������� �����)\n");
		while (usernumber != botnumber) {
			scanf_s("%i", &usernumber);
			if (usernumber < botnumber) {
				printf("���������� ����� ������\n");
				count_of_try++;
			}
			if (usernumber > botnumber) {
				printf("���������� ����� ������\n");
				count_of_try++;
			}
			else {
				if (usernumber == botnumber)
					printf("����������, �� �������. ���������� ����� ������� = %i", count_of_try);
			}
		}
	}


	if (version == 2) {
		printf("������� ����� � ��������� �� 1 �� 1000, � ��������� ��������� ������� ��� ");
		scanf_s("%i", &usernumber);
		srand(time(0));
		scanf_s("%c", &comp);
		while (comp != '=') {
			botnumber = (max + min) / 2;
			printf("����������, ��������� ����� ������ ��� ������ %i\n", botnumber);
			scanf_s(" %c", &comp);

			if (comp == '<') {
				max = botnumber;
			}

			else if (comp == '>') {
				min = botnumber;
			}

			else if (comp == '=') {
				printf("���� ����� % i. ��������� �������. ���-�� ������� = %i\n", usernumber, count_of_computer);
			}
			count_of_computer++;
		}
	}
	system("pause");
	return;
}