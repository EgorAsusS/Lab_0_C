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

    int max = array[0];
    for(int i=1;i < szz;i++) // В данной задаче случай, что все элементы одинаковые, отработает нормально, так как мы все равно получаем несуществющее значение
        if(array[i] > max) max = array[i];
    int notExist = max+1;
    int countEl=0;
    if(notExist == -2147483647-1){ // Обработка исключительного случая, если max=2147483647, так как overflow
        for(int i = 0; i < szz; i++){
            if (array[i] == notExist){
                countEl++;
                i = szz;
            }
        }
    }
    for(int i=0;i < szz;i++)
    {
        int jx = i+1;
        if(array[i]!= notExist)
        {
            while(jx < szz)
            {
                if(array[jx]!= notExist)
                {
                    if(array[i] == array[jx])
                    {
                        array[jx] = notExist;

                    }
                }
                jx++;
            }
            countEl++;
        }
        else
            array[i] = notExist;
    }
    printf("countEl = %d", countEl);
}
