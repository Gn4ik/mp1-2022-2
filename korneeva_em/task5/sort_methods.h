#pragma once
#include "sort_algorithms.h"

struct SortMethod
{
    char name[16];
    SortAlgorithm func;
};
struct SortMethod sort_methods[] = {
    {"�����������", bubble_sort},
    {"�������", select_sort},
    {"���������", insert_sort},
    {"��������", merge_sort},
    {"�������", quick_sort},
    {"�����", increment_sort},
    {"���������", count_sort},
};
#define AVAILABLE_SORT_METHODS (int)(sizeof(sort_methods) / sizeof(struct SortMethod))