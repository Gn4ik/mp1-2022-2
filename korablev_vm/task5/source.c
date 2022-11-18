#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h> 
#include <locale.h>
#include <string.h>
#include "omp.h"

char path[200];

void BubbleSort(struct _finddata_t* arr, long size);
void SelectSort(struct _finddata_t* arr, long size);
void InsertSort(struct _finddata_t* arr, long size);
void merge(struct _finddata_t* arr, long size);
void mergeSort(struct _finddata_t* arr, long size);
void QuickSort(struct _finddata_t* arr, long size);
long increment(long inc[], long size);
void ShellSort(struct _finddata_t* arr, long size);
void CountSort(struct _finddata_t* arr, long size);
char GetPath();
int GetMode();
void GetSorted(struct _finddata_t* arr, long size);
void GetResorted(struct _finddata_t* arr, long size);
enum ModeSort
{
    Bubble = 1, Select = 2, Insert = 3, Merge = 4, Quick = 5, Shell = 6, Count = 7, ChangeDir = 8, ExProg = 9
};

void main(void)
{
    setlocale(LC_ALL, "Rus");
    struct _finddata_t c_file;
    struct _finddata_t* directory;
    struct _finddata_t* time_arr;
    intptr_t hFile;
    double start, stop;
    char  mode;
    int next;
    system("title ����������� ������");
    printf("����� ���������� � ��������� ��� ���������� ������ ������� ���������!\n");
    while (1)
    {
        printf("������ ����� : c:/TestFolder/\n");
        long count = 0;
        long size = 0;
        char ch;
        while (1)
        {
            printf("������� ���� � �����: ");
            fgets(path, 200, stdin);
            path[strlen(path) - 1] = '\0';
            strcat_s(path,200, "*.*");
            if ((hFile = _findfirst(path, &c_file)) == -1L)
            {
                printf("� ����� ��� ������ ��� �� ������ ����\n");
                system("pause");
            }
            else
            {
                do
                {
                    if (c_file.size > 0)
                        size++;
                } while (_findnext(hFile, &c_file) == 0);

                directory = calloc(size, sizeof(struct _finddata_t));
                hFile = _findfirst(path, &c_file);
                do
                {
                    if (c_file.size > 0) 
                        directory[count++] = c_file;
                } while (_findnext(hFile, &c_file) == 0);
                _findclose(hFile);
                break;
            }
        }
        time_arr = calloc(size, sizeof(struct _finddata_t));
        for (long i = 0; i < size; i++)
            time_arr[i] = directory[i];
        system("cls");
        GetSorted(directory, size);
        system("pause");
 newsort:
        mode = GetMode();
        system("cls");
        start = omp_get_wtime();
        switch (mode) {
        case Bubble:
            BubbleSort(time_arr, size);
            break;
        case Select:
            SelectSort(time_arr, size);
            break;
        case Insert:
            InsertSort(time_arr, size);
            break;
        case Merge:
            mergeSort(time_arr,0, size-1);
            break;
        case Quick:
            QuickSort(time_arr, size);
            break;
        case Shell:
            ShellSort(time_arr, size);
            break;
        case Count:
            CountSort(time_arr, size);
            break;
        case ChangeDir:
            printf("�� ������ �������� ����������.\n");
            break;
        case ExProg:
            free(directory);
            free(time_arr);
            printf("������� �� ����� ���������! �������� ���!\n");
            system("pause");
            exit(0);
        default: 
            goto newsort;
        }
        stop = omp_get_wtime();
        if (mode != ChangeDir) {
            system("cls");
            printf("�� ������ ������������� ������ �� ����������� ��� ��������?\n");
            printf("1. ���������� �� �����������\n");
            printf("2. ���������� �� ��������\n");
            next = getch();
            switch (next)
            {
            case '1':
                system("cls");
                GetSorted(time_arr,size);
                break;
            case '2':
                system("cls");
                GetResorted(time_arr,size);
                break;
            default:
                system("cls");
                printf("������� �������� �����, ���������� ��� � ������ ����������.\n");
                goto newsort;
                break;
            }
            printf("����� ����������: %lf\n", stop - start);
            system("pause");
            system("cls");
            printf("�������� ���������� ��������\n\n");
            printf("1. ������� ������ ����������\n");
            printf("2. ������� ����������\n");
            printf("3. ����� �� ���������\n");
            next = getch();
            switch (next) 
            {
            case '1':
                system("cls");
                goto newsort;
                break;
            case '2':
                system("cls");
                printf("�� ������ ������� ����������.\n");
                system("pause");
                system("cls");
                break;
            case '3':
                free(directory);
                free(time_arr);
                system("cls");
                printf("������� �� ����� ���������! �������� ���!\n");
                system("pause");
                exit(0);
            default:
                system("cls");
                printf("������� �������� �����, ���������� ��� � ������ ����������.\n");
                goto newsort;
                break;
            }
        }
        free(time_arr);
    }
}
void GetSorted(struct _finddata_t* arr, long size) {
    printf("�������� �����\t\t    ������ �����\n\n");
    for (int i = 0; i < size; i++) {
        printf("%-25.10s   %-5lld\n", arr[i].name, arr[i].size);
    }
}
void GetResorted(struct _finddata_t* arr, long size) {
    printf("�������� �����\t\t    ������ �����\n\n");
    for (int i = size-1; i > -1; i--) {
        printf("%-25.10s   %-5lld\n", arr[i].name, arr[i].size);
    }
}
char GetPath() {
    char path[100],dop="\\*.*";
    int c = 100;
    printf("������� ���� � ����� ");
    fgets(path,c,stdin);
    strcat(path, dop);
    return path;
}

int GetMode() {
    int mode;
    char answ;
    system("cls");
    printf("�������� �������� �������\n");
    printf("1. ���������� \"���������\"\n");
    printf("2. ���������� \"�������\"\n");
    printf("3. ���������� \"���������\"\n");
    printf("4. ���������� \"��������\"\n");
    printf("5. ���������� \"�����\"\n");
    printf("6. ���������� \"�����\"\n");
    printf("7. ���������� \"���������\"\n");
    printf("8. ����� ����������\n");
    printf("9. ����� �� ���������\n");
    mode = getch();
    answ = mode - '0';
    return answ;
}
//���������� "���������"
void BubbleSort(struct _finddata_t* arr, long size)
{
    struct _finddata_t tmp;
    int Bool;
    for (int i = size - 1; i >= 0; i--)
    {
        Bool = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j].size > arr[j + 1].size)
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                Bool = 0;
            }
        }
    }
}
//���������� "�������"
void SelectSort(struct _finddata_t* arr, long size)
{
    int minPosition; 
    struct _finddata_t tmp;
    for (int i = 0; i < size; i++)
    {
        minPosition = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[minPosition].size > arr[j].size)
                minPosition = j;
                tmp = arr[minPosition];
                arr[minPosition] = arr[i];
                arr[i] = tmp;
        }
    }
}
//���������� "���������"
void InsertSort(struct _finddata_t* arr, long size)
{
    int newElement, location;
    for (int i = 1; i < size; i++)
    {
        newElement = arr[i].size;
        location = i - 1;
        while (location >= 0 && arr[location].size > newElement)
        {
            arr[location + 1] = arr[location];
            location = location - 1;
        }
        arr[location + 1].size = newElement;
    }
}
//�������� �������
void merge(struct _finddata_t* a, long lb, long split, long ub)
{
    long pos1 = lb;
    long pos2 = split + 1;
    long pos3 = 0;
    struct _finddata_t* temp = malloc(sizeof(struct _finddata_t) * (ub - lb + 1));
    while (pos1 <= split && pos2 <= ub)
    {
        if (a[pos1].size < a[pos2].size)
            temp[pos3++] = a[pos1++];
        else
            temp[pos3++] = a[pos2++];
    }
    while (pos2 <= ub)
        temp[pos3++] = a[pos2++];
    while (pos1 <= split)
        temp[pos3++] = a[pos1++];
    for (pos3 = 0; pos3 < ub - lb + 1; pos3++)
        a[lb + pos3] = temp[pos3];

    free(temp);
}
//���������� "��������"
void mergeSort(struct _finddata_t* a[], long lb, long ub)
{
    long split;

    if (lb < ub)
    {
        split = (lb + ub) / 2;
        mergeSort(a, lb, split);
        mergeSort(a, split + 1, ub);
        merge(a, lb, split, ub);
    }
}
void QuickSort(struct _finddata_t* arr, long size)
{
    long i = 0, j = size-1;
    struct _finddata_t* temp, p;
    p = arr[size >> 1];
    do {
        while (arr[i].size < p.size) i++;
        while (arr[j].size > p.size) j--;
        if (i <= j) {
            temp = arr[i].size;
            arr[i] = arr[j];
            arr[j].size = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) QuickSort(arr, j);
    if (size > i) QuickSort(arr + i, size - i);
}
//��������� ����������
int increment(long inc[], long size)
{
    int p1, p2, p3, s;
    p1 = p2 = p3 = 1;
    s = -1;
    do {
        if (++s % 2)
        {
            inc[s] = 8 * p1 - 6 * p2 + 1;
        }
        else
        {
            inc[s] = 9 * p1 - 9 * p3 + 1;
            p2 *= 2;
            p3 *= 2;
        }
        p1 *= 2;
    } while (3 * inc[s] < size);
    return s > 0 ? --s : 0;
}
//��������� �����
void ShellSort(struct _finddata_t* a, long size)
{
    long inc, i, j, seq[40];
    int s;
    s = increment(seq, size);
    while (s >= 0)
    {
        inc = seq[s--];

        for (i = inc; i < size; i++)
        {
            struct _finddata_t temp = a[i];
            for (j = i - inc; (j >= 0) && (a[j].size > temp.size); j -= inc)
                a[j + inc] = a[j];
            a[j + inc] = temp;
        }
    }
}
//���������� "���������"
_fsize_t max_file_size(struct _finddata_t* arr, size_t len)
{
    _fsize_t max = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i].size > max)
        {
            max = arr[i].size;
        }
    }
    return max;
}
void CountSort(struct _finddata_t* arr, size_t len)
{
    int i;
    _fsize_t k = max_file_size(arr, len);
    _fsize_t* cnt = malloc(sizeof(int) * (k + 1));
    memset(cnt, 0, sizeof(int) * (k + 1));
    for (i = 0; i < len; i++)
    {
        cnt[arr[i].size]++;
    }
    for (i = 1; i <= k; i++)
    {
        cnt[i] += cnt[i - 1];
    }
    struct _finddata_t* res = malloc(sizeof(arr[0]) * len);
    memset(res, 0, sizeof(sizeof(arr[0])) * len);
    for (i = len - 1; i >= 0; i--)
    {
        res[cnt[arr[i].size] - 1] = arr[i];
        cnt[arr[i].size]--;
    }
    for (i = 0; i < len; i++)
    {
        arr[i] = res[i];
    }
    free(cnt);
    free(res);
}