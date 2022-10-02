#define _CRT_SECURE_NO_WARNINGS //������������, ��� ������ ������������ �� ����� ���������� ������� scanf()
#include <locale.h> // �����������

#include <stdio.h> // ������������ ����� ������ ��������� � ������-�������
#include <math.h> // �������������� ��������
void main() {
	int whichGame, userTry, botNumber, tryCount, left, right, flag; // ����������: ����� ���� �������, ������� ������������, ����� ����, ���-�� �������, ������� ����� � ������ �������� (��� ��������� ������), ����(������� ����� while)
	char sign; // �������� char - �������� �� > < = 
	sign = '0'; 
	flag = 0;
	userTry = 0;
	tryCount = 0;
	left = 1;  // �������� ��������� ��� 2 ������
	right = 1000; // �������� ��������. � ����� ����������� � ����� ����������� ��� �������� ������

	setlocale(LC_ALL, "Rus"); // �����������

	printf("��� ����������? ��������� ��� ������������? ������� �������������� 1 ��� 2:\n ");
	scanf("%i", &whichGame);

	if (whichGame == 1) { // ������� ������� ���� 1
		botNumber = abs(srand() % 1000 + 1); // �������� ���������� ����� �� 1 �� 1000
		printf("�������, ��� ��������������� ����������� ������������ ���������� �����. ���� ��������!\n");

		while (1) { // ����������� ���� ���� 1. ����������� ��� ���������� ����������� ����� �����

			printf("������� �������������� ���� �����!\n");
			scanf("%i", &userTry);

			if (userTry > botNumber) {
				tryCount++;
				printf("���������� ����� ������ ������������� ����. ������� ������������: %i\n", tryCount);
			}
			else if (userTry < botNumber) {
				tryCount++; // +1 ���-�� �������
				printf("���������� ����� ������ ������������� ����. ������� ������������: %i\n", tryCount);
			}
			else {
				tryCount++;
				printf("����������! �� �������� ������! ��-��, ��� �����, � ��������! ������� ������������: %i\n", tryCount);
				break; // ��� � ���������
			}
		}


	}
	else if (whichGame == 2) { // ������� ������� ���� 2
		userTry = (left + right) / 2; /*��� ����, ����� �� ��������� ��� 2 ����� ����������, � ������� �� �������.
										� �������� �������� ����� ��� �� ������� ����� ��� ������� ��������� ���� ������� ������.
										����� �� ����� ��� ��������. ������ ��� �� ���������� ���, ������� userTry - ������� ����, �����, �������������� ��
										*/ 
		printf("������� �����, �������! � ����� ������� ��� �������� �� 10 �������!\n");
		scanf("%i", &botNumber);

		while (flag == 0) { // ������� ����������� 2 ����
			if (tryCount > 9) // �������� ���-�� �������. ���� ������ 9 - ����� 1000, ������ ��� ���� �� ������� ������ �������, �� ��� ����� �������� ������ ����� �� 1 �� 999. ������� �� 1000
			{
				printf("��� ����� 1000. ������\n");
				system("PAUSE");
			}
			printf("��� ����� %i? �� ������ ������ > < ��� =: \n", userTry);

			scanf(" %c", &sign);


			switch (sign){ // �������� switch, �������� � ��������� ����������

				case  '>' :
					left = userTry; // ������� ���������� ��������� �������� ����������� �����
					userTry = (left + right) / 2; // ����� ������� ���� - �������� ����� ����������� � ������������ ����������
					tryCount += 1; // +1 ���-�� �������
					break; // �������� ������, ���� �� ����� ��������� ��, ��� �����

				case '<' :
					right = userTry; // ������� ����������� ��������� �������� ����������� �����
					userTry = (left + right) / 2;
					tryCount += 1;
					break;

				case '=' :
					printf("��� ���� ������! � ������� ���� �������� �� %i �������\n", tryCount);
					flag = 1; // ���������� ������������� �������� �������, ���� ��������� ���� ������
					break;
				default:
					printf("�������, �����, ��� ����� ��� �� ������ ���� �� ������: > < =, � �� ��� ��� ��� �� \n"); // ��������� ������ ������������, ���� ������ �� ��� ������

			}

		}
	}
	else {
		printf("�������,�� �������� ��� �� ������ ����������. ����� ������������� �� ����, ����� ������� ��������� ������\n"); // ���� ���� ������� �� ������ �������� ������ ����
	}
	system("PAUSE");
}