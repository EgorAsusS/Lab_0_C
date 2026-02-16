// Задача: Найти и вывести количество групп уникальных элементов в заданном массиве. (Уникальная группа элементов - группа элементов, равных по значению)
#include <stdio.h>
#include <stdbool.h>
#define szz 10
//#define szz 1


int main()
{
    int array[szz] = { 1,2,3,4,5,6,7,8,9,10 }; // countEl = 10
    //int array[szz] = { 2,2,2,2,2,2,2,2,2,2 }; // countEl = 1
    //int array[szz] = { 5,5,7,3,3,2,2,1,1,10 }; // countEl = 6
    //int array[szz] = { 5,7,2,3,4,2,5,1,4,10 }; // countEl = 7
    //int array[szz] = { 0 }; // countEl = 1
    //int array[szz] = { -2147483647 - 1,-2147483647 - 1,7,3,3,2,2,1,1,2147483647 }; // countEl = 6


    bool is_non_unique[szz]; // Изменение алгоритма связано с тем, что во-первых алгоритм портит исходный массив, а во-вторых notExist = max + 1 при max == 2147483647 - переполнение. Поэтому создаем характеристический массив
    for (int i = 0; i < szz; i++) {// 0 - если элемент пока не встречался (изначально все нули). 1 - если элемент уже присутствует в массиве
        is_non_unique[i] = 0;
    }
    int countEl = 0;
    for (int i = 0; i < szz; i++)
    {
        int jx = i + 1;
        if (is_non_unique[i] == 0)// Если элемент пока не встречался 
        {
            while (jx < szz)
            {
                if (is_non_unique[jx] == 0)// Если элемент пока не встречался
                {
                    if (array[i] == array[jx])//Если уже есть элемент равный текущему
                    {
                        is_non_unique[jx] = 1;
                    }
                }
                jx++;
            }
            countEl++;
        }
    }
    printf("countEl = %d", countEl);
    // Вывод элементов массива, для отладки
    printf("\n");
    for (int i = 0; i < szz; i++) {
        printf("%d ", array[i]);
    }
}
