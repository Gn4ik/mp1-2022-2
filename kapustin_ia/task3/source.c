#include <iostream>
#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <windows.h> //����� ��� ������ sllep()
#include <stdlib.h> // ����� ��� ������ ������� rand(), srand()
#include <time.h> // ����� ��� ������ ������� time()
int GetRan(int min, int max)
{
	// ���������� ��������� ��������� �����
	srand((int)time(NULL));
	// �������� ��������� �����
	int num = min + rand() % (max - min + 1);
	return num;
}
int main()
{

	setlocale(LC_ALL, "RUS");
	int ar[5] = { -1,-3,-4,-5,-6 };
	int ar1[5] = { -2,-7,-8,-9,-20 };
	int n, rad, g, i, s, bulls, cows;
    c:
	printf("������� ����� n �� 2 - 5, � ����������� �� ����, ����� �� ��������� ����� ������ ���������\n");
	scanf_s("%i", &n);
    d:
	Sleep(1500);
	switch (n)
	{
	case 2:

		rad = GetRan(10, 99);
		/*printf("����� = %d\n", rad);*/
		break;
	case 3:
		rad = GetRan(100, 999);
		/*printf("����� = %d\n", rad);*/
		break;
	case 4:
		rad = GetRan(1000, 9999);
		/*printf("����� = %d\n", rad);*/
		break;
	case 5:
		rad = GetRan(10000, 99999);
		/*printf("����� = %d\n", rad);*/
		break;
	default:
		printf("�������� �������� n, ���������� �����\n");
		goto c;
	}
	i = 0;
	while (rad > 0)
	{
		ar[i] = rad % 10;
		rad /= 10;
		/*printf("=%d\n", ar[i]);*/
		i++;
	}
	i = 0;
	while (i < 5)
	{
		for (int j = i + 1; j < 5; j++)
			if (ar[i] == ar[j])
			{
				goto d;
			}
		i++;
	}
    h:
	printf("������� n-������� �����; n = %d\n", n);
	scanf_s("%d", &s);
	i = 0;
	while (s > 0)
	{
		ar1[i] = s % 10;
		s /= 10;
		/*printf("=%d\n", ar1[i]);*/
		i++;
	}
	i = 0;
	cows = 0;
	bulls = 0;
	while (i < 5)
	{
		for (int j = 0; j < 5; j++)
			if (ar[i] == ar1[j])
			{
				cows = cows + 1;
				if (i == j)
					bulls = bulls + 1;
			}
		i++;
	}
	printf("����� = %d\n", cows);
	printf("����� = %d\n", bulls);
	if (bulls != n)
	{
		printf("���� ������ ���������� ���������� ������� 1, ����� 2\n");
		scanf_s("%d", &g);
		switch (g)
		{
		case 1:
			goto h;
		case 2:
			break;
		}
	}
	else
	{
		printf("�� �������� �����!");
	}
	return 0;
}