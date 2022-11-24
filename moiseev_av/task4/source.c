#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h> //���������� ��� ������ �� ��������
#include <math.h>
#include <windows.h> //���������� ��� ������ � ��������

int i = 0, j = 0, cnt = 0, sale = 0, summ = 0, quantity[10]; //���������� ����������
double tmp, discounts[10] = { 0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5 };
double price_final[10];
float summ_with_discounts = 0;
const char escap[] = { "0" };
char ch, code[5], card[4];
char* receipt[10] = { " " , " " , " " , " " , " " , " " , " " , " " , " " , " " };
char* membr_card;

enum TColor {  //����� ������
	BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY,
	DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED,
	LIGHTMAGENTA, YELLOW, WHITE
};

void textattr(int color) //�������, ���������� �� ���� ��������
{
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Console, color);
}

void textcolor(int color)  //�������, ���������� �� ���� ������
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

void setwindow(int width, int height)  //�������, ���������� �� ������ ����
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

void shopping() //������� ��� ������������ �������
{
	int same;
	double prices[10] = { 89, 249, 50, 99, 99, 79, 69, 69, 30, 169 };
	const char* codes[10] = { "0001", "0002", "0003", "0004", "0005", "0006", "0007", "0008", "0009", "0010" };
	const char* description[10] = { "������ 3,5%        ", "���                ", "������ (���������) ", "���� (�������)     ",
		"����� (���������)  ", "��� (������������) ", "������� (�������)  ", "������� (��������) ", "���� (�����)       ", "������� (��������)" };

	while (1)
	{
		printf("������� �����-��� ������:\n");
		textattr(GREEN);
		gets(code); //gets() - �������, ��� ��������� ������ ��������� ������
		textcolor(WHITE);

		if (strcmp(escap, code) == 0) //strcmp() - ����� ����, ���� ������ �������� ���� �� ������
		{
			return 0;
		}
		
		for (i = 0; i < 10; i++)
		{
			same = 0;
			if (strcmp(codes[i], code) == 0)
			{
				summ += prices[i];
				summ_with_discounts += prices[i] - prices[i] * discounts[i];
				for (j = 0; j < 10; j++)
				{
					if (strcmp(receipt[j], description[i]) == 0)
					{
						quantity[j] += 1;
						same = 1;
						break;
					}
				}

				if (same == 0)
				{
					receipt[cnt] = description[i];
					quantity[cnt] += 1;
					price_final[cnt] = prices[i] * 1000 + (prices[i] - (prices[i] * discounts[i]));
					cnt++;
				}

				printf("\n������������ ������: %s", description[i]);
				printf("\n����: %g ���.", prices[i]);
				printf(" ���� �� �����: %g ���. ������ - %g%%", prices[i] - prices[i] * discounts[i], discounts[i] * 100);
				printf("\n\n�����: %d ���.\n", summ);
				break;
			}

			if (i == 9)
			{
				textcolor(LIGHTRED);
				printf("\n�� ������ �����-���\n");
				textcolor(WHITE);
			}
		}
		textcolor(LIGHTCYAN);
		printf("\n��� ����� ������������ ������� �������: '0'\n");
		textcolor(WHITE);
	}
}

char cards() //������� ��� ������������ ��������� �����
{
	const char* users_cards[7] = { "001", "010", "011", "100", "101", "110", "111" };

	printf("\n������� ����� ��������� �����:");

	while (1)
	{
		textcolor(LIGHTCYAN);
		printf("\n��� ���������� �����, �������: '0'\n");
		textattr(GREEN);
		gets(card);
		textcolor(WHITE);

		if (strcmp(escap, card) == 0)
		{
			membr_card = (char*)"�����������";
			return 0;
		}

		for (i = 0; i < 7; i++)
		{
			if (strcmp(users_cards[i], card) == 0)
			{
				membr_card = (char*)users_cards[i]; //����������� ������ �����
				sale = 1;
				printf("\n������ ������� ���������");
				return 0;
			}
		}
		textcolor(LIGHTRED);
		printf("\n���������������� ����� �����\n");
	}
}

void main()
{
	double user_discount = 0;

	setwindow(60, 37);
	setlocale(LC_ALL, "Rus");
	srand(time(0));

	for (i = 9; i >= 1; i--) //������������ ������, ����� ��� ������ ������� ������ �� ������ ����������� � ��������� �������
	{
		j = 1 + rand() % (i);
		tmp = discounts[j];
		discounts[j] = discounts[i];
		discounts[i] = tmp;
	}

	textcolor(YELLOW);
	printf("\n     **���������**\n�����-����: �� 0001 �� 0010 (� ����� + 1)\n��������� ����� ������������ ����� ����� �� 1 �� 7"
		"\n� �������� �������������: �� 001 �� 111\n\n");
	textcolor(WHITE);

	shopping(); //����� �������

	cards();

	if (sale == 1)
	{
		for (i = 0; i < cnt; i++)
		{
			price_final[i] = fmod(price_final[i], 1000); //��������� ������� �� ������� ����� ���� double� � ������� 'fmod'
		}
		user_discount = (double)summ - (double)summ_with_discounts;
		
	}
	else
	{
		for (i = 0; i < cnt; i++)
		{
			price_final[i] = (int)price_final[i] / 1000;
			user_discount = 0;
			summ_with_discounts = summ;
		}
	}

	printf("\n\n                   ��Ҩ�����");
	printf("\n                � �. ���������");
	printf("\n                ��� '��������'");
	printf("\n             ��� �� ������� �: %d", rand() % 1000);
	printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - -");

	for (i = 0; i < cnt; i++)
	{
		printf("\n%d. %s %g ���.  *  %d ��. = %g ���.", i + 1, receipt[i], price_final[i], quantity[i], quantity[i] * price_final[i]);
	}

	printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	printf("\n��������� ����� �: %s", membr_card);
	printf("\n���� ������: %g ���.", user_discount);
	printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - -");
	printf("\n           ���� ������� � ������ ������\n");
	printf("\n����: %g ���.\n\n", summ_with_discounts);
}
