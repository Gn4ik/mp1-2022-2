#include <stdio.h>
#include <locale.h>
void main() {
	setlocale(LC_ALL, "Russian");
	int h, w, d;
	// ��������� ��������� � ��/��3
	float R_DSP = 0.5;
	float R_wood = 1.5;
	float R_DVP = 0.85;
	float ans = 0;
	// ��������� ������� ���
	float t_DSP = 1.6;
	int counter;
	printf("������� ������, ������, ������� � �� \n");
	scanf_s("%i%i%i", &h, &w, &d);
	if ((h>=180 && h<=220)&&(w>=80 && w<=120)&&(d>=50&&d<=90)) {
		// ������ ������
		ans = ans + h * w * 0.5 * R_DVP;
		// 2 ������� �����
		ans = ans + 2 * (h * d * 1.5 * R_DSP);
		// ������� � ������ ������
		ans = ans + 2 * (w * d * 1.5 * R_DSP);
		// �����
		ans = ans + R_wood * d * w;
		// ���������� �����
		if (h % 40 == 0) {
			counter = h / 40 - 1;
		}
		else {
			counter = h / 40;
		}
		// �����
		ans = ans + counter * R_DSP * w * d * t_DSP;
		// ��������� � ����������
		ans = ans * 0.001;
		printf("���=%f", ans);
		
	}
	else {
		printf("�������� ������");
		
		}







	
	
system("pause");
}