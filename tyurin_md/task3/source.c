#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "Header.h"

void main(){
   int n, cows = 0, bulls = 0;
   int random_location, number = 0, entered_number, again, variable_x, variable_y, attempts = 0;
   int all_numbers[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 
   int robot_number[5] = { 0 }, user_number[5] = { 0 };
   char ch;
   setlocale(LC_ALL, "Russian");
   textbackground(BLACK);
   setwindow(100, 40);
   SMALL_RECT window;
   COORD buf;
   getwindow(&window, &buf);
   start:
   do {
      clrscr();
      variable_x = (window.Left + window.Right) / 30;
      textcolor(MAGENTA);
      gotoxy(variable_x + 30, wherey() + 3);
      printf("����� ���������� � ���� \"���� � ������\"");
      textcolor(YELLOW);
      gotoxy(variable_x, wherey() + 2);
      printf("��� ���������� ������� ����� ������������� �����,");
      gotoxy(variable_x, wherey() + 1);
      printf("����� ���� ��������� ���������� �����, ������� ��� ���������� ��������");
      gotoxy(variable_x, wherey() + 2);
      printf("��������� �������: ");
      gotoxy(variable_x + 2, wherey() + 1);
      printf("1) ������� ���� ������� ��� ���������� � �� ��������(�� ���� �����)");
      gotoxy(variable_x + 2, wherey() + 1);
      printf("2) ������� ������� ���� ������ �� �������(�� ���� �����)");
      gotoxy(variable_x, wherey() + 4);
      textcolor(LIGHTRED);
      printf("����� ��������� ���� ������� 0!\n");
      gotoxy(variable_x, wherey() + 1);
      gotoxy((window.Left + window.Right) / 4, (window.Top + window.Bottom) / 2 + 2);
      textcolor(GREEN);
      printf("�������� ����� ������������� �����(�� 2 �� 5): ");
      scanf_s("%d", &n);
      while (ch = getchar() != '\n');
      clrscr();
   } while ((n < 2) || (n > 5));

   for (int i = 0; i < n; i++) {
      srand(time(NULL));
      beginning:
      random_location = rand() % 10;
      if (all_numbers[random_location] < 10) {
         if ((random_location == 0) && (i == 0))
            goto beginning;
         else {
            robot_number[i] = all_numbers[random_location];
            all_numbers[random_location] = 1000;
         }
      }
      else
         goto beginning;
   }
   for (int j = 0; j < n; j++) {
      number += robot_number[j] * (int)pow(10, n - j - 1);
   }
   variable_x = (window.Left + window.Right) / 3;
   variable_y = (window.Top + window.Bottom) / 3;
   attempts = 0;
   do {
      attempts++;
      do {
         clrscr();
         if (attempts > 1) {
            gotoxy(variable_x + 4, variable_y + 7);
            printf("����� ����� = %d", cows);
            gotoxy(variable_x + 4, wherey() + 1);
            printf("����� ����� = %d", bulls);
            gotoxy(variable_x + 4, wherey() + 1);
            printf("��������� �������: %d", attempts - 1);
         }
         textcolor(YELLOW);
         gotoxy(variable_x, variable_y + 5);
         printf("������� ����� ������� %d: ", n);
         scanf_s("%d", &entered_number);
         while (ch = getchar() != '\n');
         if (entered_number == 0)
            goto finish;
      } while (entered_number < pow(10, n - 1) || entered_number >= pow(10, n));
      for (int m = 1; m < n + 1; m++) {
        user_number[n - m] = entered_number % 10;
        entered_number /= 10;
      }

      cows = 0;
      bulls = 0;
      for (int i = 0; i < n; i++) {
         for (int k = 0; k < n; k++) {
            if (robot_number[i] == user_number[k]) {
              if (i == k)
                bulls++;
              else
                cows++;
            }
         }
      }
   }  while (bulls != n);
   clrscr();
   gotoxy(variable_x + 6, variable_y + 4);
   printf("����������, �� ������� �����!\n");

   finish:
   if (bulls != n) {
      clrscr();
      gotoxy(variable_x + 12, variable_y + 4);
      printf("�����: %d\n", number);
   }

   gotoxy(variable_x - 12, variable_y + 6);
   printf("������ ������ ���� �������? ������� 1 - ���� �� � 0 - ���� ���");
   gotoxy(wherex() + 1, wherey());
   scanf_s("%d", &again);
   if (again == 1)
      goto start;
   else {
      clrscr();
   }
}
