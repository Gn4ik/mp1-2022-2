#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
void main()
{
    setlocale(LC_ALL, "Rus");
    char r;
    int n, n2, i = 0, k = 0;
    char answer;
    printf("������� ����� ������ ");
    scanf_s("%c", &r);
    if (r == '1')//����� 1
    {
        srand(time(NULL));//��� ��������� ��� ������ ������ rand() ������ �����
        n = 1 + rand() % (1000);
        while (k != n)
        {
            printf("������� ��� ������� ");
            scanf_s("%d", &k);
            if (k < n) printf("���������� ����� ������ ");
            else if (k > n) printf("���������� ����� ������ ");
            i++;
        }
        printf("�������! ���� ���������� �������: %d \n", i);
    }
    else if (r == '2')//����� 2
    {
        n = 0;//����� �������
        n2 = 1001;//������ �������
        k = 500;
        i = 1;
        scanf_s("%c", &answer);
        printf("%d ��� ����� ", k);
        while (answer != '=')
        {
            if ((answer != '>') && (answer != '<') && (answer != '='))
                scanf_s("%c", &answer);
            else
            {
                if (answer == '>')
                {
                    n = k;
                    k = (n + n2) / 2;
                }
                else if (answer == '<')
                {
                    n2 = k;
                    k = (n + n2) / 2;
                };
                printf("%d ��� ����� ", k);
                scanf_s("%c", &answer);
                i++;
            };
        }
        printf("���! ���������� �������: %d \n", i);
    }
    else printf("����������� ������ ����� ������ ");
    system("pause");
}