#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "Russian");

    double x1, x2, y1, y2, r1, r2, d = 0;
    printf("������� ��������� ������ ���������� (x1, y1, r1)\n");
    if (scanf_s("%lf %lf %lf", &x1, &y1, &r1) != 3 || r1 <= 0)
    {
        printf("�������� ������\n");
        return 1;
    }
    printf("������� ��������� ������ ���������� (x2, y2, r2\n");
    if (scanf_s("%lf %lf %lf", &x2, &y2, &r2) != 3 || r2 <= 0)
    {
        printf("�������� ������\n");
        return 1;
    }
    d = sqrt(x2 * x2 - 2 * x2 * x1 + x1 * x1 + y2 * y2 - 2 * y1 * y2 + y1 * y1);

    if (r1 == r2 && d == 0)
        printf("���������� ���������\n");
    else if (d < fabs(r1 - r2) && d > 0)
        printf("������ ���������� ����� � ������\n");
    else if (d == fabs(r1 - r2))
        printf("���������� �������� ���������� ������� (���� ����� �����)\n");
    else if (d > fabs(r1 - r2) && d < (r1 + r2))
        printf("���������� ������������ (��� ����� �����)\n");
    else if (d == (r1 + r2))
        printf("���������� �������� ������� ������� (���� ����� �����)\n");
    else if (d > (r1 + r2))
        printf("���������� �� ��������\n");

    system("PAUSE");
    return 0;
}
