#include "Header.h"

void merge(struct _finddata_t* data_set, long lb, long split, long rb) {
    // ������� ������������� ������ ������� � ����� temp
    // � ���������� ��������� ����������� temp � a[lb]...a[ub]

      // ������� ������� ������ �� ������ ������������������ a[lb]...a[split]
    long pos1 = lb;

    // ������� ������� ������ �� ������ ������������������ a[split+1]...a[ub]
    long pos2 = split + 1;

    // ������� ������� ������ � temp
    long pos3 = 0;

    struct _finddata_t* temp = (struct _finddata_t*)malloc((unsigned long long)(rb - lb + 1) * sizeof(struct _finddata_t));
    if (temp == NULL)
        return;
    // ���� �������, ���� ���� ���� ���� ������� � ������ ������������������
    while ((pos1 <= split) && (pos2 <= rb)) {
        if (data_set[pos1].size < data_set[pos2].size)
            temp[pos3++] = data_set[pos1++];
        else
            temp[pos3++] = data_set[pos2++];
    }

    // ���� ������������������ ����������� - 
    // ���������� ������� ������ � ����� ������ 
    while (pos2 <= rb)   // ���� ������ ������������������ ������� 
        temp[pos3++] = data_set[pos2++];
    while (pos1 <= split)  // ���� ������ ������������������ �������
        temp[pos3++] = data_set[pos1++];

    // ����������� ����� temp � a[lb]...a[ub]
    for (pos3 = 0; pos3 < rb - lb + 1; pos3++)
        data_set[lb + pos3] = temp[pos3];
    free(temp);
}

void mergeSort(struct _finddata_t* data_set, long lb, long rb) {
    long split;                   // ������, �� �������� ����� ������

    if (lb < rb) {                // ���� ���� ����� 1 ��������

        split = (lb + rb) / 2;

        mergeSort(data_set, lb, split);       // ����������� ����� �������� 
        mergeSort(data_set, split + 1, rb);// ����������� ������ �������� 
        merge(data_set, lb, split, rb);    // ����� ���������� � ����� ������
    }
}
