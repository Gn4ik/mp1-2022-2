#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include "console.h"

int povtor(int x, int y) // ����� �������, ������� ����� ��������� ������������ ����� ����� (����� �� ���� ������������� ����).
{
	int mass[5], temp;
	for (int h = 0; h < y; h++)
	{
		temp = x % 10;
		if (proverka_massiva(mass, temp) == 1)
		{
			mass[h] = temp;
			x /= 10;
		}
		else
			return 0;
	}
	return 1;
}

int proverka_massiva(int massive[], int num) // ������� ��� �������� ������� �� ������� ����������� �����.
{
	int k;
	for (k = 0; k < 5; k++)
	{
		if (num == massive[k])
			return 0;
	}
	return 1;
}



int main()
{
	setlocale(LC_ALL, "Russian");

	textcolor(GREEN);
	textbackground(BLACK);

	setwindow(120, 30);
	SMALL_RECT window;
	COORD buf;
	getwindow(&window, &buf);
	hidecursor();
	gotoxy((window.Left + window.Right) / 2, (window.Top + window.Bottom) / 2);
	gotoxy(buf.X / 2 - 20, (buf.Y / 2) + 0);
	printf("����� ���������� � ���� <<���� � ������>>");
	gotoxy(0, 0);
	system("PAUSE");
	clrscr();
	gotoxy(buf.X / 2 - 15, (buf.Y / 2) + 0);
	printf("������� ��� �� ������ �������?");
	gotoxy(buf.X / 2 - 0.5, (buf.Y / 2) + 1);
	
		
	
	int game = 1, kolichestvo, pravila;
	srand(time(NULL));

	scanf_s("%d", &kolichestvo);
	clrscr();

	gotoxy(buf.X / 2 - 50, (buf.Y / 2) + 0);
	printf("������� ����:");
	gotoxy(buf.X / 2 - 51, (buf.Y / 2) + 1);
	printf(" ������ ��� ������(������� � ���������).");
	gotoxy(buf.X / 2 - 50, (buf.Y / 2) + 2);
	printf("����� �������� ����� ������������� ����� � n (�� 2 �� 5).");
	gotoxy(buf.X / 2 - 50, (buf.Y / 2) + 3);
	printf("��������� ����������� n-������� ����� � ���������������� �������.");
	gotoxy(buf.X / 2 - 50, (buf.Y / 2) + 4);
	printf("����� ������ ������� �������� ����� � ������ n-������� ����� � ���������������� �������.");
	gotoxy(buf.X / 2 - 50, (buf.Y / 2) + 5);
	printf("��������� ��������, ������� ���� ������� ��� ���������� � �� ��������� � ���������� ����� (�����)");
	gotoxy(buf.X / 2 - 50, (buf.Y / 2) + 6);
	printf("��������� ��������,������� ������� ������ �� ������� � ���������� ����� (�����).");
	gotoxy(buf.X / 2 - 50, (buf.Y / 2) + 7);
	printf("����� ������ �������, ���� �� �������� ��� ������������������ ��� �� �������.");
	gotoxy(0, 0);
	system("PAUSE");
	clrscr();
	for (int r = 0; r < kolichestvo; r++) // � ������� ����� for ������� ���������� ���������� ����.
	{
		int len, i, min, max, number, win = 0, count = 0, arrI[5], arrN[5];
		gotoxy(buf.X / 2 - 16, (buf.Y / 2) + 0);
		printf("������� ����� ����� (2-5 ����)");
		gotoxy(buf.X / 2 - 0.5, (buf.Y / 2) + 1);
		scanf_s("%d", &len);
		clrscr();
		if ((len > 5) || (len < 2)) // �������� ������.
		{
			gotoxy(buf.X / 2 - 8, (buf.Y / 2) + 0);
			printf("�������� ������");
			gotoxy(0, 0);
			system("PAUSE");
			clrscr();
		}
		else
		{
			min = (int)pow(10, len - 1);
			max = (int)pow(10, len) - 1;
			i = rand() % (max - min + 1) + min; // �������� ��������� ����� � ���������, ��������� �� ���������� ���� � �����.
			while (povtor(i, len) == 0) // �������� ��������������� ����� �� ������������� �����.
			{
				i = rand() % (max - min + 1) + min; //���� ����� �� ��������, ������� �� ������ � �������� ��� ���.
			}
			gotoxy(buf.X / 2 - 14, (buf.Y / 2) + 0);
			printf("����������� ������� �����:");
			gotoxy(buf.X / 2 - 14, (buf.Y / 2) + 1);
			printf("(���� �������, ������� 9)"); //��� ��� ��������� ������.

			while (win != 1)
			{
				int bulls = 0, kows = 0, temp;
				count++;
				temp = i;
				
				gotoxy(buf.X / 2 - 2, (buf.Y / 2) + 2);
				scanf_s("%d", &number);
				clrscr();
				if (((number > ((int)pow(10, len) - 1)) || (number < ((int)pow(10, len - 1)))) && number != 9) // �������� �� ������������ ��������� �����.
				{

					gotoxy(buf.X / 2 - 8, (buf.Y / 2) + 0);
					printf("�������� ������");
					gotoxy(0, 0);
					system("PAUSE");
					clrscr();
					gotoxy(buf.X / 2 - 14, (buf.Y / 2) + 0);
					printf("����������� ������� �����:");
				}
				else if (number == i) //������ ������.
					win = 1;
				else if (number == 9)//������ �����.
				{
					gotoxy(buf.X / 2 - 11, (buf.Y / 2) + 0);
					printf("���������� ����� : %d", i);
					gotoxy(0, 0);
					system("PAUSE");
					clrscr();
					gotoxy(buf.X / 2 - 14, (buf.Y / 2) + 0);
					printf("����������� ������� �����:");
					gotoxy(buf.X / 2 - 2, (buf.Y / 2) + 0);
				}
				else
				{
					for (int k = 0; k < len; k++)//�������� ��� ������� ������� �� ����������� ����� � ��������� (������� ���� ����������, �� ������� ���������).
					{
						arrI[k] = temp % 10;
						arrN[k] = number % 10;
						temp /= 10;
						number /= 10;
					}
					for (int c = 0; c < len; c++)//����� ���������� ���������� ������� (����� �����).
					{
						if (arrN[c] == arrI[c])
							bulls++;
						else if (proverka_massiva(arrI, arrN[c]) == 0) //� ����� ���� �����.
							kows++;
					}
					clrscr();
					gotoxy(buf.X / 2 - 11, (buf.Y / 2) - 1);
					printf("���������� �����: %d", kows);
					gotoxy(buf.X / 2 - 11, (buf.Y / 2) + 0);
					printf("���������� �����: %d", bulls);
					gotoxy(buf.X / 2 - 14, (buf.Y / 2) + 1);
					printf("����������� ������� �����:");
				}
			}
		}
		textcolor(RED);
		textbackground(WHITE);
		clrscr();
		gotoxy(buf.X / 2 - 18, (buf.Y / 2) + 0);
		printf("�� ��������!!! ���������� �������: %d \n", count);
		gotoxy(0, 0);
		system("PAUSE");
		textcolor(GREEN);
		textbackground(BLACK);
		clrscr();
	}
	return 0;
}