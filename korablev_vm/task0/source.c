#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <windows.h>
void main()
{
    //������ ���������� + �����������
    setlocale(LC_ALL, "Rus");
    int x1, y1, x2, y2, r1, r2;
    int distance, R, r; //���������� ����� ��������, ������� � ������� ������
    //
    //���� ������
    printf("������� �����");
    //printf("x1 and y1 are the coordinates of the center of the 1st circle, x2 and y2 are the coordinates of the center of the 2nd circle, r1 and r2 are the radii of the 1st and 2nd circles, respectively\n");
    printf("Enter x1,y1,x2,y2,r1,r2 in the appropriate order ");
    scanf("%d,%d,%d,%d,%d,%d", &x1, &y1, &x2, &y2, &r1, &r2);
    //
    //��������� ����������
    distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    if (r1 > r2)
    {
        R = r1;
        r = r2;
    }
    else
    {
        R = r2;
        r = r1;
    }
    //
    //���������� ��������������
    if (distance > (R + r))
        printf("The circles do not intersect, they lie separately from each other\n"); //���������� �� ������������, ����� �������� ���� �� �����
    else if ((distance == 0) && (R == r))
        printf("The circles lie on top of each other\n"); //���������� ��������� 
    else if ((distance == (R + r)) && (distance > 0))
        printf("The circles lie separately from each other, have 1 intersection point\n"); //���������� ����� �������� ���� �� �����, ����� 1 ����� �����������
    else if (distance < (R - r))
        printf("One circle lies inside the other, do not intersect\n"); //���� ���������� ����� ������ ������, �� ������������
    else if (distance == (R - r))
        printf("One circle lies inside the other, have 1 intersection point\n"); //���� ���������� ����� ������ ������, 1 �����������
    else if (((R - r) < distance) && (distance < (R + r)))
        printf("The circles intersect at two points\n"); //���������� ������������ � ���� ������
    else
        wprintf("Fail\n"); //������
    system("pause");
}