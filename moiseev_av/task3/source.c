#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <windows.h> //���������� ��� ������ � ��������//
#include <memory.h>

enum TColor {            //����� ������//
	BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY,
	DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED,
	LIGHTMAGENTA, YELLOW, WHITE
};

void textattr(int color) //�������, ���������� �� ���� ��������//
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Console, color);
}

void textcolor(int color)  //�������, ���������� �� ���� ������//
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console)
		return;

	CONSOLE_SCREEN_BUFFER_INFO buf;
	GetConsoleScreenBufferInfo(Console, &buf);

	WORD Attr;
	DWORD Count;
	COORD pos = buf.dwCursorPosition;
	ReadConsoleOutputAttribute(Console, &Attr, 1, pos, &Count);

	int bk_col = Attr / 16;
	int col = color % 16;
	col = col + bk_col * 16;

	SetConsoleTextAttribute(Console, col);
}

void setwindow(int width, int height)  //�������, ���������� �� ������ ����//
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!Console)
		return;

	SMALL_RECT rect;
	rect.Left = 0;
	rect.Right = width - 1;
	rect.Top = 0;
	rect.Bottom = height - 1;
	COORD size;
	size.X = width;
	size.Y = height;
	SetConsoleWindowInfo(Console, 1, &rect);
	SetConsoleScreenBufferSize(Console, size);
}

void main()
{
	setwindow(86, 30); //���������� ���������� ������� ����//

	setlocale(LC_ALL, "Rus");
	int res = TRUE;
	while (res == TRUE) //���� ��� ������� ����//
	{
		srand(time(0));

		int cnt = 0, len_for_user_num = 0, i = 1, hint = 1, number0 = 10, number1 = 10, number2 = 10, number3 = 10;
		int n = 0, detecter, user_num, user_num_clone, user_numberi = 11, bol = 0, cow = 0;
		const int COUNT = 9, COUNT_word = 8, COUNT_num = 8;

		char ch, yn, array[] = {'W', 'e', 'l', 'c', 'o', 'm', 'e', '!'}; //������ �������//
		int num[4], user_numbers[] = { 11, 12, 13, 14 }, rand_nums[4];

		printf("               ");
		for (int j = 0; j < COUNT_word; j++) //������� ������ ������� ������� �� ����������� ��� ����, ������ ���� ��������//
		{
			while (i < COUNT)
			{
				textcolor(i);
				printf("%c", array[j]);
				i++;
				break;
			}
		}
	
		textcolor(YELLOW); //����������//
		printf("\n\n����� ���������� � ���� '���� � ������'!\n");
		textcolor(YELLOW);
		printf("\n               �������:\n");
		textattr(LIGHTGRAY);
		printf("\n1. ������ ��� ������(������� � ���������)\n2. ����� �������� ����� ������������� ����� n � (�� 2 �� 5)\n3. ��������� '����������' n - ������� ����� � ���������������� �������\n4. ����� �������� �������� �����: ������ n - ������� ����� � ���������������� �������\n5. ��������� ��������, ������� ���� ������� -\n   ��� ���������� � �� ��������� � ���������� ����� (�� ���� ���������� �����)\n   � ������� ������� ������ �� ������� � ���������� ����� (�� ���� ���������� �����)\n6. ����� ������ �������, ���� �� �������� ��� ������������������ ��� �� �������\n");
		textcolor(LIGHTRED);
		printf("\n��� ������ ������� : '0'\n\n");

		while ((n < 2) || (n >= 5)) //�������� �����//
		{
			textcolor(LIGHTCYAN);
			printf("�������� ����� ����� (�� 2 �� 5): ");
			textattr(WHITE);
			scanf_s("%d", &n);

			if (n == 0) //����� �� ���������//
			{
				textcolor(YELLOW);
				printf("\n�� ��������!\n");
				textcolor(WHITE);
				return 0;
			}
			else if ((n < 2) || (n >= 5))
			{
				textcolor(LIGHTRED);
				printf("\n������!\n");
				textcolor(YELLOW);
				printf("������������ ����� �����!\n");
				textcolor(WHITE);
			}
			else
			{
				break;
			}
		}

		number0 = 1 + rand() % 9; //�������� ���������� ����� � �� �������������� �������, � ����������� ����������� � ������//
		if (n == 2)
		{
			while ((number1 = rand() % 9) == number0);
			num[0] = number1;
			num[1] = number0;
		}
		else if (n == 3)
		{
			while (number2 == number0 || number2 == number1 || number0 == number1)
			{
				number1 = rand() % 9;
				number2 = rand() % 9;
			}
			num[0] = number2;
			num[1] = number1;
			num[2] = number0;
		}
		else if (n == 4)
		{
			while (number2 == number0 || number2 == number1 || number0 == number1 || number3 == number0 || number3 == number1 || number3 == number2)
			{
				number1 = rand() % 9;
				number2 = rand() % 9;
				number3 = rand() % 9;
			}
			num[0] = number3;
			num[1] = number2;
			num[2] = number1;
			num[3] = number0;
		}

		textcolor(YELLOW);
		printf("\n� ������� �����\n������ ���� ������ ������� ���������� ������������������.\n");
		while (1)
		{
			detecter = 0;
			if (hint % 3 == 0) //������ 3 ��������� ������� ��������� ����� ���������� ��������//
			{
				textcolor(LIGHTRED);
				printf("\n���� ������ ������� �������: '0'\n");
			}
			textcolor(LIGHTCYAN);
			printf("\n������� ���� �������: ");
			textattr(WHITE);
			scanf_s("%d", &user_num);
			while (ch = getchar() != '\n'); //�������� ������//
			if (user_num == 0)
			{
				textcolor(YELLOW); //����� �� ���������//
				printf("\n�� ��������!\n");
				textcolor(WHITE);
				res = FALSE;
				break;
			}
			len_for_user_num = user_num;
			cnt = 0;
			while (len_for_user_num != 0) //������� ���������� ���� � ���������������� �����//
			{
				len_for_user_num /= 10;
				cnt++;
			}
			if (n != cnt)
			{
				textcolor(LIGHTRED);
				printf("\n������!\n");
				textcolor(YELLOW);
				printf("���� ����� �� ������������� ������ �����!\n");
				hint++;
			}
			else
			{
				for (int i = 0; i < 4; i++) //��������� ����������������� ����� �� ������//
				{
					if (user_num == 0)
						break;
					user_numberi = user_num % 10;
					user_num /= 10;
					user_numbers[i] = user_numberi;
				}
				for (int i = 0; i < 2; i++) //�������� �� ���������� ���� � ���������������� �����, � ������� 2� ������ for//
				{
					for (int j = i + 1; j < 3; j++)
					{
						if (user_numbers[i] == user_numbers[j])
						{
							textcolor(LIGHTRED);
							printf("\n������!\n");
							textcolor(YELLOW);
							printf("� ����� ����� �� ������ ����������� ������������� �����!\n������� ������� ������������!\n");
							detecter++;
							hint++;
							break;
						}
					}
					break;
				}
				if (detecter > 0)
				{
				}
				else
				{
					bol = 0;
					cow = 0;
					for (int i = 0; i < 4; i++) //������� "�����"//
					{
						if (num[i] == user_numbers[i])
							bol++;
					}

					for (int i = 3; i >= 0; i--) //������� "�����"//
					{
						for (int j = 3; j >= 0; j--)
						{
							if (i == j)
							{
								if (num[i] == user_numbers[j - 1])
									cow++;
								break;
							}
							if (num[i] == user_numbers[j])
								cow++;
						}
					}
					textcolor(YELLOW); //�����//
					printf("���������� �����: %d\n", cow);
					printf("���������� �����: %d\n", bol);
					hint++;
					if (n == bol) //�������� �� ������//
					{
						textcolor(YELLOW);
						printf("\n������!\n�� ������� ��� �����!\n������ ������� ��� ���? (Y/N)\n");
						textattr(WHITE);
						scanf_s("\n%c", &yn);
						if (yn == 'N' || yn == 'n')
						{
							textcolor(WHITE);
							res = FALSE;
							break;
						}
						else
						{
							break;
						}
					}
				}
			}
		}
	}
}
