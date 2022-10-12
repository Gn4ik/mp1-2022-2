#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
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
	const int COUNT = 9, COUNT_word = 8;
	char ch, yn, word[] = { 'W', 'e', 'l', 'c', 'o', 'm', 'e', '!' };

	while (res == TRUE) //���� ��� ������� ����//
	{
		int n = 1, cnt = 0, bul = 0, cow = 0, betw = 0, j = 0, i = 1, hint = 1;
		int user_num, len_for_user_num = 0, user_numberi = 0, degree, detecter;
		int computer_num[4], user_numbers[4], numbers[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		srand(time(0));

		printf("\n               ");
		for (j = 0; j < COUNT_word; j++) //������� ������ ������� ������� �� ����������� ��� ����, ������ ���� ��������//
		{
			while (i < COUNT)
			{
				textcolor(i);
				printf("%c", word[j]);
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

			while (ch = getchar() != '\n'); //�������� ������//

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

		for (i = 9; i >= 1; i--)  //������������ ������, ��� ����� ������� ��������� ����� � ���������������� �������//
		{
			j = rand() % (i + 1);
			betw = numbers[j];
			numbers[j] = numbers[i];
			numbers[i] = betw;
		}

		computer_num[0] = numbers[0];
		computer_num[1] = numbers[1];

		if (computer_num[0] == 0) //�������� ��������� ������ ����� ����//
		{
			computer_num[0] = numbers[4];
		}

		switch (n)
		{
			case 3: computer_num[2] = numbers[2];
				break;
			case 4: computer_num[2] = numbers[2], computer_num[3] = numbers[3];
				break;
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
			}
			else
			{
				for (i = 0, degree = n - 1; i < n; i++, degree--) //��������� ����������������� ����� �� ������, //
				{												 //� ����������� ����������� ���� � ������ �� �������//
					int c = pow(10, degree);
					user_numberi = user_num  / c;
					user_num %= c;
					user_numbers[i] = user_numberi;
				}
				
				for (i = 0; i < n - 1; i++) //�������� �� ���������� ���� � ���������������� �����, � ������� 2� ������ for//
				{
					for (j = i + 1; j < n; j++)
					{
						if (user_numbers[i] == user_numbers[j])
						{
							textcolor(LIGHTRED);
							printf("\n������!\n");
							textcolor(YELLOW);
							printf("� ����� ����� �� ������ ����������� ������������� �����!\n������� ������� ������������!\n");
							detecter++;
							break;
						}
					}
				}
				if (detecter > 0)
				{
				}
				else
				{
					bul = 0;
					cow = 0;
					for (i = 0; i < n; i++) //������� "�����"//
					{
						if (computer_num[i] == user_numbers[i])
							bul++;
					}

					for (i = 0; i < n; i++) //������� "�����"//
					{
						for (j = 0; j < n; j++)
						{
							if (i != j)
							{
								if (computer_num[i] == user_numbers[j])
								{
									cow++;
								}
							}
						}
					}
					textcolor(YELLOW); //�����//
					printf("���������� �����: %d\n", cow);
					printf("���������� �����: %d\n", bul);
					hint++;
					if (n == bul) //�������� �� ������//
					{
						hint--;
						textcolor(YELLOW);
						printf("\n������!\n�� ������� ��� �����!\n���������� �������: %d\n������ ������� ��� ���? (Y/N) ", hint);
						textattr(WHITE);
						scanf_s("\n%c", &yn);
						if (yn == 'N' || yn == 'n')
						{
							textcolor(YELLOW);
							printf("\n�� ��������!\n");
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
