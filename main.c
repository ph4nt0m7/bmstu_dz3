//
//  main.c
//  bmstu_dz3
//
//  Created by Kostya on 08.11.2019.
//  Copyright © 2019 ph4nt0m7. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>



/** Функция для вывода массива
    @param text_above Текст, который выводиться перед выводом массива
    @param arr массив
    @param arr_size длина массива
    @param t_start время начала сортировки
    @param t_end время конца сортировки
 */
void print_arr(char text_above[],int arr[],int arr_size, unsigned long t_start, unsigned long t_end){
    unsigned long time = t_end - t_start;
    printf("%s (%lums.) - ",text_above,time);
    for(int i=0;i<arr_size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

/** Что в мейне?
    Проверка на сортировку: Массив состоящий из 20 элементов расположенные в хаотичном порядке
    @Returns
    1: массив не правильно отсортирован.
    0: массив отсортирован правильно.
 */
int main(){
    int *arr;
    arr = calloc(20, sizeof(int));
    int arr_check[] = {0, 0, 2, 4, 4, 5, 7, 9, 25, 26, 26, 32, 33, 56, 74, 87, 233, 723, 1000, 3825};
    int array[20] = {2, 0, 723, 9, 4, 25, 74, 4, 233, 7, 0, 5, 33, 26, 87, 32, 26, 1000, 3825, 56};
    arr = array;
    unsigned long time_start,time_end;
    
    time_start = clock();
//    radix_sort(arr,20);
    time_end = clock();
    print_arr("Radix sort",arr,20,time_start,time_end);

    
    
    
    _Bool check = 0;
//    radix_sort(arr,20);
    for(int i=0;i<20;i++){
        if(arr[i]!=arr_check[i])
            check=-1;
    }
    printf("Program ended with exit code: %d\n",check);
    return check;
}

//0 0 2 4 4 5 7 9 25 26 26 32 33 56 74 87 233 723 1000 3825
