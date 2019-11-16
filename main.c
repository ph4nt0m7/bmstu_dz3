//
//  main.c
//  bmstu_dz3
//
//  Created by Kostya on 08.11.2019.
//  Copyright © 2019 ph4nt0m7. All rights reserved.
//
/// @version 1.0.0

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define TYPE_DATA int

/** Шейкерная сортировка
    @param arr массив на вход
    @param num кол-во элементов
    @author YCTAHOBKA
*/
void ShakerSort(TYPE_DATA *arr, int num){
    int left = 0, right = num - 1;
    int flag = 1;
    while((left < right) && flag > 0){
        for(int i = left; i < right; i++){
            if (arr[i] > arr[i+1]){
                int t = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = t;
                flag = 0;
            }
        }
        right--;
        for(int i = right; i>left; i--){
            if(arr[i] < arr[i-1]){
                int t = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = t;
                flag = 1;
            }
        }
        left++;
    }
}

/** Интроспективная сортировка
    @param arr массив на вход
    @param num кол-во элементов
    @author ph4nt0m7
*/
void IntroSort      (TYPE_DATA *arr, int num);
void _quicksort     (TYPE_DATA *arr, int low, int high, int num, TYPE_DATA pivot, int recursion_depth);
void _heapsort      (TYPE_DATA *arr, int left, int right);
void _swap          (TYPE_DATA *arr, int i, int j);
void _siftdown      (TYPE_DATA *arr, int root, int bottom);
void _insertionsort (TYPE_DATA *arr, int left, int right);

void IntroSort(TYPE_DATA *arr, int num){
    TYPE_DATA pivot = ( arr[0] + arr[num-1] + arr[ (num-1) / 2] ) / 3;
    _quicksort(arr, 0, num-1, num, pivot, 0);
}
/// Native HeapSort
void _heapsort(TYPE_DATA *arr, int left, int right){
    for (int i = (right-left+1 / 2) - 1; i >= left; i--)
        _siftdown(arr, i, right-left+1 - 1);
    
    for (int i = right-left+1 - 1; i >= 1; i--){
        _swap(arr, 0, i);
        _siftdown(arr, 0, i - 1);
    }
}
/// Modified QuickSort
void _quicksort(TYPE_DATA *arr, int low, int high, int num, TYPE_DATA pivot, int recursion_depth){
    if(high-low < 16){
        _insertionsort(arr, low, high);
    } else if(recursion_depth >= 2*log(num)){
        _heapsort(arr, low, high);
    } else {
        int i = low;
        int j = high;
        
        while (i <= j){
            while (arr[i] < pivot)
                i++;
            while (arr[j] > pivot)
                j--;
            if (i <= j){
                _swap(arr, i, j);
                i++;
                j--;
            }
        }
        if (j > low)
            _quicksort(arr, low, j, num, pivot, ++recursion_depth);
        if (i < high)
            _quicksort(arr, i, high, num, pivot, ++recursion_depth);
    }
}
/// Native InsertionSort
void _insertionsort(TYPE_DATA *arr, int left, int right){
    for (int i = left+1; i <= right; i++){
        TYPE_DATA key = arr[i];
        int j = i-1;
  
        while (j >= left && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
   }
}
/// Swap 'i' and 'j' position in array
void _swap(TYPE_DATA *arr, int i, int j) {
    TYPE_DATA temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
/// *For HeapSort*
void _siftdown(TYPE_DATA *arr, int root, int bottom){
    int maxChild;
    int done = 0;
    while ((root * 2 <= bottom) && (!done)){
        if (root * 2 == bottom)
            maxChild = root * 2;
        else if (arr[root * 2] > arr[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        if (arr[root] < arr[maxChild]){
            TYPE_DATA temp = arr[root];
            arr[root] = arr[maxChild];
            arr[maxChild] = temp;
            root = maxChild;
        }
        else
            done = 1;
    }
}



/** Функция для вывода массива
    @param text_above Текст, который выводиться перед выводом массива
    @param arr массив
    @param arr_size длина массива
    @param t_start время начала сортировки
    @param t_end время конца сортировки
 */
void print_arr(char text_above[], TYPE_DATA arr[], int arr_size, unsigned long t_start, unsigned long t_end){
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
    TYPE_DATA *arr;
    arr = calloc(20, sizeof(TYPE_DATA));
    TYPE_DATA arr_check[] = {0, 0, 2, 4, 4, 5, 7, 9, 25, 26, 26, 32, 33, 56, 74, 87, 233, 723, 1000, 3825};
    TYPE_DATA array[20] = {2, 0, 723, 9, 4, 25, 74, 4, 233, 7, 0, 5, 33, 26, 87, 32, 26, 1000, 3825, 56};
    arr = array;
    unsigned long time_start,time_end;
    
    time_start = clock();
    IntroSort(arr,20);
    time_end = clock();
    print_arr("Radix sort",arr,20,time_start,time_end);

    
    
    
    _Bool check = 0;
    for(int i=0;i<20;i++){
        if(arr[i]!=arr_check[i])
            check=-1;
    }
    printf("Program ended with exit code: %d\n",check);
    return check;
}

//0 0 2 4 4 5 7 9 25 26 26 32 33 56 74 87 233 723 1000 3825
