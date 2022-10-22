#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#define PROD 40
	typedef struct {
	char * cods;
	char * name;
	float cost;
	short count;
	float price;
}product;
//������ ��������� (completed)
product P[] = {
	"0401","����� �������������� 500��   ", 449.90, 0, 0,
	"0402","����� ������������ 500��     ", 429.90, 0, 0,
	"0403","������� ������������ 1��     ",389.90, 0, 0,
	"0404","��� ����� � �������� 1��     ", 499.90, 0, 0,
	"0405","��� ������������ 1��         ", 105.10, 0, 0,
	"0406","��� ������������ 1��         ",114.50, 0,0,
	"0407","��� ����������� 1��          ",130.0,0,0,
	"0408","��������� \"�����������\" 1��",18.90,0,0,
	"0409","��������� ��������� 1��      ",45.90,0,0,
	"0501","��������� ��� ����� 1��      ",37.90,0,0,
	"0502","����� ������ ������� 1��     ",429.90,0,0,
	"0503","����� 3,2%% 1�.              ",135.90,0,0,
	"0504","����� ������������ 1�        ",153.10,0,0,
	"0504","���� � ������ 400��          ",245.90,0,0,
	"0505","���� ������� 600��           ",190.90,0,0,
	"0506","���� ��� ����� 500��         ",598.90,0,0,
	"0507","���� ��������� 1��           ",450.90,0,0,
	"0508","���� ��������� � ������ 1��  ",370.90,0,0,
	"0509","��� ������ 50 ���������      ",149.90,0,0,
	"0601","��� ������� 50 ���������     ",180.90,0,0,
	"0602","��������� ����� 200��        ",75.90,0,0,
	"0603","������ �������� 9%%           ",90.90,0,0,
	"0604","����� ������ 1��             ",89.90,0,0,
	"0605","����� ����� 1��              ",63.90,0,0,
	"0606","����� �������� 1��           ",76.90,0,0,
	"0607","�������� �������� 450��      ",75.90,0,0,
	"0608","�������� ���� 400��          ",68.50,0,0,
	"0609","�������� ����� 400��         ",68.90,0,0,
	"0702","�������� ��������� 400��     ",72.50,0,0,
	"0703","����� ����� ����� 1��        ",56.90,0,0,
	"0704","����� ������������ 500��     ",54.90,0,0,
	"0705","���� ������������� �/c 1��   ",54.90,0,0,
	"0706","���� ������� 1��             ",67.50,0,0,
	"0707","�������� ������� 300��       ",149.90,0,0,
	"0708","���������� ������ 400��      ",209.90,0,0,
	"0709","������ � ������� 250��       ",119.90,0,0,
	"0801","������ ���������� 250��      ",128.50,0,0,
	"info","����� ����",0,0,0,
	"exit","����� �� ���������",0,0,0,
	"cheq","����� ����",0,0,0,
};
//���������������� (completed)
void ShowHelp(new)
{
	if (new == 1) {
		system("cls");
		printf("\t\t\t����� ���������� � ������-�����!\n");
		printf("\t����� ������� ������, ����������, ������������ � �����������.\n");
		printf("\t� ������ ��������� �� ���������� ���, ����� 4 ���������� ���.\n");
		printf("\t����� ����� ��� ��� ��������� ������ � ��������� ���� ������.\n");
		printf("\t����� ����� �� ������� ��������� �����-��� ���������� ������.\n");
		printf("\t����� ��� ������ ����� ������� � ���, ������� � ������ \"stop\"\n");
		printf("\t\t������ �� ������ ��������� ��������� �������:\n");
		printf("\t\t������� �� 2 ��. �� ������ ����������� +5%% ������\n");
		printf("\n\t����� ��� ��� ��������� ��� ���������, ������� \"info\"\n\t");
		printf("\n\t����� �������� �������� ��� �������, ������� \"cheq\"\n\t");
		printf("\n\t����� ������������� ��������� ������, ������� \"exit\"\n\n\t");
		system("pause");
	}
}
//������������ ���� (completed)
void showCheque() {
	system("cls");
	int num = 1, discount;
	float SalePrice,Summ=0,SaleSumm=0;
	printf("\t\t�����\t\t\t����������\t����\t\t���������(��� ������)\t���������(�� �������)\n");
	for (int i = 0; i < PROD-3; i++) {
		if (P[i].count > 0) {
			P[i].price = P[i].count * P[i].cost;
			discount = 5 * (P[i].count - 1);
			if (P[i].count > 11)
				discount = 50;
			SalePrice = (P[i].price / 100) * (100 - discount);
			printf("%d)\t%s\t*%d ��.\t\t%.2f ���/��\t %.2f ���.\t\t%.2f ���.\n",num,P[i].name,P[i].count,P[i].cost,P[i].price,SalePrice);
			SaleSumm = SaleSumm + SalePrice;
			Summ = Summ + P[i].price;
			num++;
		}
	}
	printf("\n\t\t\t\t\t\t\t\t\t�����: %.2f ������\n", Summ);
	printf("\t\t\t\t\t\t\t\t\t������: %.2f ������\n", Summ-SaleSumm);
	printf("\t\t\t\t\t\t\t\t\t�����: %.2f ������\n\n", SaleSumm);
	system("pause");
}
//����� ������ ��������� (completed)
void List(int a){
	if (a == 1) {
		system("cls");
		printf("\t\t������ �������:\n");
		printf("�����\t\t��������\t\t����\n");
		for (int i = 0; i < PROD - 3; i++) {
			printf("%s\t%s\t%.2f ���/��\n", P[i].cods, P[i].name, P[i].cost);
		}
		system("pause");
	}
}
//���� � �������� (completed)
void GiveInfo(int numb) {
	int choose=0;
	do {
		system("cls");
		printf("\n\n\n��������� �����:\t\t%s\n", P[numb].name);
		printf("����:\t\t\t\t%.2f ���/��\n", P[numb].cost);
		printf("���������� � ���� (��� �����):\t\t%d\n", P[numb].count);
		printf("\n�������� ���� ����� � ���? 1- ��, 2 - ���: ");
		scanf_s("%d", &choose);
	} while (choose < 1 || choose>2);
	if (choose == 1) {
		P[numb].count = P[numb].count + 1;
		printf("\n����� ������� �������� � ���\n\n");
	}
	else {
		printf("\n�������. ����� �� ����� ������ � ���.\n\n");
	}
	system("pause");
}
//������������ ������ ���� (completed)
void Restart() {
	for (int i = 0; i < PROD; i++) {
		P[i].count = 0;
	}
}
//��������� ���� ������ ����� ���� (completed) 
int GetCode() {
	char c[]={0,0,0,0,0};
	char ch;
	int numb=-1;
	system("cls");
	printf("\n\n\n������� �����-��� ��������� ������: ");
	fgets(c,5,stdin);
	for (int i = 0; i < PROD; i++) {
		int check = 0;
		for (int j = 0; j < 4; j++) {
			if (c[j]==P[i].cods[j]) {
				check++;
			}
		}
		if (check == 4) {
			numb = i;
			i = PROD;
		}
	}
	if (numb < 0) {
		printf("������� ������������ ������\n");
		fflush(stdin);
		while ((ch = getchar()) != '\n');
		system("pause");
		GetCode();
	}
	else
		return numb;
}
