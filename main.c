// Задача: Найти и вывести количество групп уникальных элементов в заданном массиве. (Уникальная группа элементов - группа элементов, равных по значению)
#include <stdio.h>
#include <stdbool.h>
#define szz 10


int main()
{
    int array[szz] = { 5,5,7,3,3,2,2,1,1,10 };
    int max = array[0];
    for(int i=1;i < szz;i++)
        if(array[i] > max) max = array[i];
    int notExist = max+1;
    int countEl=0;
    if(notExist == -2147483647-1){
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
