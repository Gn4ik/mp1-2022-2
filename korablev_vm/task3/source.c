#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "Header.h"
void main()
{
	setwindow(100, 40);
	SMALL_RECT window;
	COORD buf;
	getwindow(&window, &buf);
	setlocale(LC_ALL, "Rus");
	textbackground(BLACK);
	textcolor(GREEN);
	//���������� � ���������
	int LengthOfNumber,SelectedNumber,cows,bulls, animals; //����� �����, ���������� �����, ����� ������������
	int c, Guessed_Number; //������� ���������� � �������
	int robot[5], human[5];
	char x,ch;
	int newgame, gaveup;
	int cord_x,attempts;
	//
	//��� ���������
	cord_x = (window.Left + window.Right)/4-1;
	gotoxy(cord_x, wherey() + 1);
	printf("|-----------------------------------------------|");
	gotoxy(cord_x, wherey() + 1);
	printf("|    ����� ���������� � ���� \"���� � ������\"    |");
	gotoxy(cord_x, wherey() + 1);
	printf("|-----------------------------------------------|");
	gotoxy(cord_x, wherey() + 1);
	printf("������� ����: �� ��������� ���������� ���� � �����.");
	gotoxy(cord_x, wherey() + 1);
	printf("��������� ���������� �����, ������� �� ����������."); 
	gotoxy(cord_x, wherey() + 1);
	printf("���������: ����� �� ������ �����������.");
	gotoxy(cord_x, wherey() + 1);
	printf("��������� ��������, ������� ���� ������� ��� ������� (������)");
	gotoxy(cord_x, wherey() + 1);
	printf("� ������� ���� ������� ����� (����).");
	gotoxy(cord_x, wherey() + 1);
	printf("� ����� ������ �� ������ �������, ����� � ���� ����� 0.");
	gotoxy(cord_x, wherey() + 2);
start:
	newgame = 0;
	gaveup = 0;
	attempts = 1;
	cows = 0;
	bulls = 0;
	animals = 0;
	do{
		showcursor();
		cord_x = (window.Left + window.Right) / 4;
		gotoxy(28, wherey());
		printf("������� ����� ������������ ����� (�� 2 �� 5) ");
		scanf_s("%d", &LengthOfNumber);
	} while ((LengthOfNumber < 2) || (LengthOfNumber > 5));
	//������������ ���������� �����
	srand(time(NULL));
	c = (rand() % 9) + 1;
	robot[0] = c;
	for (int i = 1; i < LengthOfNumber; i++) {
		while (c == robot[0] || c == robot[1] || c == robot[2] || c == robot[3] || c == robot[4]) {
			c = rand() % 10;
		}
		robot[i] = c;
	}
	while (1)
	{
		do 
		{
			clrscr();
			cord_x = (window.Left + window.Right) / 3+3;
			if (attempts > 1) {
				gotoxy(cord_x, 11);
				printf("���������� ����� = %d", cows);
				gotoxy(cord_x, 12);
				printf("���������� ����� = %d", bulls);
			}
			cord_x = (window.Left + window.Right) / 3;
			gotoxy(cord_x, 8);
			printf("������� �������������� �����: ");
			scanf_s("%d", &Guessed_Number);
			if (Guessed_Number < 0)
				break;
		} while (((Guessed_Number != 0) & (Guessed_Number < pow(10,LengthOfNumber-1)) || (Guessed_Number > pow(10, LengthOfNumber)-1)));
		if (Guessed_Number == 0)
		{
			gaveup = 1;
			goto exit;
		}
		cows = 0;
		bulls = 0;
		animals = 0;
		for (int i = 1; i <= LengthOfNumber; i++)
		{
			human[LengthOfNumber - i] = Guessed_Number % 10;
			Guessed_Number /= 10;
		}
		for (int i = 0; i < LengthOfNumber; i++)
		{
			for (int j = 0;j < LengthOfNumber; j++)
			{
				if (robot[i] == human[i])
				{
					bulls++;
					animals++;
					break;
				}
				else if (robot[i] == human[j])
				{
					animals++;
				}
			}
		}
	if (bulls == LengthOfNumber)
		break;
	cows = animals - bulls;
	attempts++;
	}
	if (bulls == LengthOfNumber) {
		clrscr();
		cord_x = (window.Left + window.Right) / 3 + 2;
		gotoxy(cord_x, wherey() + 1);
		printf("�� �������! \n");
		gotoxy(cord_x, wherey() + 1);
		printf("���������� �������: %d \n",attempts);
	}
	exit:
	cord_x = (window.Left + window.Right) / 3-5;
	if (gaveup == 1) {
		clrscr();
		gotoxy(cord_x, wherey() + 1);
		printf("�� ������������! ������� � ��������� ���!");
	}
	cord_x = (window.Left + window.Right) / 3+2;
	gotoxy(cord_x, wherey() + 1);
	printf("���������� �����: ");
	for (int i = 0; i < LengthOfNumber; i++) {
		printf("%d", robot[i]);
	}
	cord_x = (window.Left + window.Right) / 3-5;
	gotoxy(cord_x, wherey() + 5);
	printf("������ �� ������ ����� ����? 1- ��, 2 - ���: ");
	scanf_s("%d", &newgame);
	if (newgame == 1){
		clrscr();
		goto start;
	}
	else {
		gotoxy(cord_x+8, wherey() + 1);
		printf("���� ���������. �������� ���!");
		gotoxy(cord_x, wherey() + 2);
		system("pause");
	}
}
