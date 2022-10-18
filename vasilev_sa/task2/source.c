#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <math.h>

void main()
{
    setlocale(LC_ALL, "Russian");
    int guess, mode, answer, guesses = 1, local_min = 1, local_max = 1000;
    char sign, block;
    printf("1 �����: \"��������� ���������� ��������� �����\"\n");
    printf("2 �����: \"��������� ��������� ���������� �����\"\n");
    printf("������� ����� ������ ���� (1 ��� 2): ");
    scanf_s("%d", &mode);
    switch (mode)
    {
    case 1:
        {
            printf("\n����������� ����� ���� \"��������� ���������� ��������� �����\"\n");
            printf("  ������� ����:\n��������� ���������� ����� �� 1 �� 1000, � �� ��������� ��� �������. \n��������� ����� ������������ ������ ����� ��� ������.\n\n");
            srand(time(0));
            answer = (rand() % local_max) + local_min;
            do {
                printf("���� %d �������������: ", guesses);
                scanf_s("%d", &guess);
                if (guess > answer)
                {
                    printf("���������� ����� ������\n\n");
                }
                else if (guess < answer)
                {
                    printf("���������� ����� ������\n\n");
                }
                else {
                    printf("\n\n�� �������\n");
                }
                guesses++;
            } while (guess != answer);
            guesses--;
            printf("**********************\n");
            printf("���������� �������: %d\n", guesses);
            printf("**********************\n\n");
        }
        break;
    case 2:
        {
            printf("\n����������� ����� ���� \"��������� ��������� ���������� �����\"\n");
            printf("  ������� ����:\n�� ���������� �����, � ��������� �������� ��� ������� �� ������������� ���������.\n�� ������ ������������ ������ \">\" ���� ���������� ����� ������, \"<\" ��� ������ � \"=\" ���� ��������� �������\n\n");
            printf("������� �����, ������� ����� ��������� ���������: ");
            scanf_s("%d", &answer);
            srand(time(0));
            do
            {
                guess = round((local_max - local_min) / 2) + local_min;
                printf("%d ������� ���������: %d\n",guesses ,guess);
                printf("������� \">\" ��� \"<\" ��� \"=\": ");
                scanf_s("%c", &block, 1);
                scanf_s("%c", &sign, 1);
                switch (sign)
                {
                case '<':
                    local_max = guess;
                    break;
                case '>':
                    local_min = guess;
                    break;
                case '=':
                    continue;
                default:
                    printf("��������� ������, ���������� �����\n");
                    guesses--;
                    break;
                }
                guesses++;
            } while (sign != '=');
            printf("\n\n��������� �������\n");
            printf("**********************\n");
            printf("���������� �������: %d\n", guesses);
            printf("**********************\n\n");
        }
        break;
    default:
        printf("������ �������� ����� ����\n");
        break;
    }
    system("pause");
}