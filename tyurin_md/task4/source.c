#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Header.h"

#define MAX_LENGTH 128
#define MAX 3
#define CNT 15
#define PLUS_CNT 17
SMALL_RECT window;
COORD buf;

char* product_name[PLUS_CNT][MAX_LENGTH] = {
   "������ ��������������������� 1 ����",
   "������ 10%  0,5 ����",
   "������ 9% �������� 0,5 ��",
   "����� ��������� 0,25 �� ",
   "����� ������ 1 ��",
   "��� ������������ 1 ��",
   "�������� �������� 1 ��",
   "���� ������������� 1,5 ��",
   "������� ������������ 0,5 ��",
   "��� ������� 0,3 ��",
   "���� ������� 0,3 ��",
   "������� ������� ���������� 0,5 ��",
   "������� � �������� 0,5 ��",
   "������� 0,5 ��",
   "������� 25% 0,25 ��",
   "������ ���������",
   "������� ���"
};
int product_price[CNT][MAX] = {
   58,
   38,
   60,
   90,
   46,
   105,
   50,
   110,
   90,
   170,
   250,
   310,
   220,
   290,
   70
};
char* product_barcode[PLUS_CNT][5] = {
   "1657",
   "7689",
   "6549",
   "3465",
   "2894",
   "7403",
   "5278",
   "3240",
   "1064",
   "7889",
   "6487",
   "2591",
   "3089",
   "7291",
   "5665",
   "1111",
   "0000"
};
int product_discount[CNT][MAX] = {
   0,
   5,
   5,
   10,
   10,
   15,
   10,
   20,
   10,
   30,
   20,
   5,
   10,
   35,
   5
};
int product_count[CNT][MAX] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0
};

void list_of_products(void);
char* code_entry(void);
int search_ind(char* barcod);
void info(int ind);
void cheque();


void main(void) {
   setlocale(LC_ALL, "Russian");
   textbackground(BLACK);
   setwindow(170, 70);
   SMALL_RECT window;
   COORD buf;
   getwindow(&window, &buf);

   int variable_x;
   int ind, count = 0, a;
   char barcod[5];
   clrscr();
   variable_x = (window.Left + window.Right) / 30;
   textcolor(MAGENTA);
   gotoxy(variable_x + 30, wherey() + 1);
   printf("����� ���������� � \"����������� �����\"\n\n");
   list:
   list_of_products();
   system("PAUSE");
   while (1) {
      strcpy_s(barcod, 5, code_entry());
      ind = search_ind(barcod);
      if (ind == 15) {
         clrscr();
         goto list;
      }
      else if (ind == 16) {
         if (count == 0) {
            textcolor(LIGHTRED);
            gotoxy(variable_x + 32, wherey() + 1);
            printf("��� �� �������� �������.\n");
            textcolor(BLUE);
            gotoxy(variable_x + 32, wherey());
            printf("������ ���������� �������� ������? ������� 1 - ���� �� � 0 - ���� ���\n");
            gotoxy(variable_x + 32, wherey());
            scanf_s("%d", &a);
            clrscr();
            if (a == 1)
               goto list;
            else
               break;
         }

         system("cls");
         cheque();
         textcolor(WHITE);
         system("PAUSE");
         break;
      }

      else {
         info(ind);
         count++;
      }
   }
}


//������ �������
void list_of_products(void) {
   int variable_x;
   variable_x = (window.Left + window.Right) / 30;

   textcolor(MAGENTA);
   printf("���     ��������                                  ���������      ������\n");
   for (int i = 0; i < CNT; i++) {
      textcolor(YELLOW);
      printf("%s    %s  ", product_barcode[0][i], product_name[0][i]);
      gotoxy(variable_x + 50, wherey());
      printf("%d���", product_price[0][i]);
      gotoxy(variable_x + 65, wherey());
      printf("%d%%\n", product_discount[0][i]);
   }
}

//���� ����
char* code_entry(void) {
   int variable_x;
   variable_x = (window.Left + window.Right) / 30;
   int cnt;
   char cod[5] = {0};
   char ch;
   textcolor(BLUE);
   do {
      clrscr();
      gotoxy(variable_x + 35, wherey()+3);
      printf("������ ��� ������ (1111 - ������ �������, 0000 - ���): \n");
      cod[0] = 0;
      gotoxy(variable_x + 35, wherey());
      scanf_s("%s", &cod, 5);
      while (ch = getchar() != '\n');
      cnt = strlen(cod);
   } while ((cnt < 4) || (cnt > 4));
   return cod;
}
//����� �������
int search_ind(char* barcod) {
   for (int i = 0; i < PLUS_CNT; i++)
   {
      if (strcmp(barcod, product_barcode[0][i]) == 0)
         return i;
   }
   return -1;
}

//���������� � ������
void info(int ind) {
   int variable_x;
   variable_x = (window.Left + window.Right) / 30;
   int select = 0;
   do {
      clrscr();
      gotoxy(variable_x + 40, wherey()+10);
      textcolor(MAGENTA);
      printf("���������� � ������ \n");
      textcolor(BLUE);
      if (ind == -1) {
         gotoxy(variable_x + 20, wherey() + 1);
         printf("������ ������ ��� � ����� ��������, ������� ��� ��� ���\n");
         gotoxy(variable_x + 20, wherey() + 1);
         system("PAUSE");
      }

      else {
         gotoxy(variable_x + 20, wherey() + 1);
         printf("%s\t\t����: %d ������\t\t������:  %d %%\n", product_name[0][ind], product_price[0][ind], product_discount[0][ind]);
         gotoxy(variable_x + 20, wherey()+1);
         printf("������ �������� ����� � �������? ������� 1 - ���� �� � 0 - ���� ���\n");
         gotoxy(variable_x + 20, wherey());
         scanf_s("%d", &select);
         if (select == 1)
            product_count[0][ind] ++;
      }
   } while (select < 0 || select > 1);
}
//���
void cheque() {
   int variable_x;
   variable_x = (window.Left + window.Right) / 30;
   float itog_sum = 0, sale_sum, discount = 0, all_sum = 0, sum_product, all_discount = 0;
   textcolor(MAGENTA);
   printf("������������ ��������                             ����           ������         ���-��         �����\n\n");
   textcolor(BLUE);
   for (int i = 0; i < CNT; i++) {
      if (product_count[0][i] >= 1) {
         all_sum += (float)(product_price[0][i]) * product_count[0][i];
         sale_sum = (float)(product_price[0][i]) * ((float)(100 - product_discount[0][i]) / 100);
         discount = ((float)(product_price[0][i]) - sale_sum);
         all_discount += discount * product_count[0][i];;
         sum_product = sale_sum * product_count[0][i];
         itog_sum += sum_product;
         gotoxy(variable_x, wherey());
         printf("%s", product_name[0][i]);
         gotoxy(variable_x + 50, wherey());
         printf("%d���", product_price[0][i]);
         gotoxy(variable_x + 65, wherey());
         printf("%.1f���", discount);
         gotoxy(variable_x + 80, wherey());
         printf("%d��", product_count[0][i]);
         gotoxy(variable_x + 95, wherey());
         printf("%.1f���\n", sum_product);
      }
   }
   textcolor(MAGENTA);
   gotoxy(variable_x, wherey() + 1);
   printf("����� ����� = %.1f���\n������ = %.1f���\n����� � ������ = %.1f���\n", all_sum, all_discount, itog_sum);
}


       
   






