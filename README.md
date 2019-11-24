# bmstu_dz3

Defines
---
``` C
    #define TYPE_DATA int //какой тип данных в массиве
```

Шейкерная сортировка
---
    @param   arr         массив на вход
    @param   num         кол-во элементов
    @author  YCTAHOBKA
    
Прототипы функций:
``` c
void ShakerSort(TYPE_DATA *arr, int num);
```
Интроспективная сортировка
---
    @param   arr         массив на вход
    @param   num         кол-во элементов
    @author  ph4nt0m7

Прототипы функций
``` c
void IntroSort      (TYPE_DATA *arr, int num);
void _quicksort     (TYPE_DATA *arr, int low, int high, int num, TYPE_DATA pivot, int recursion_depth);
void _heapsort      (TYPE_DATA *arr, int left, int right);
void _swap          (TYPE_DATA *arr, int i, int j);
void _siftdown      (TYPE_DATA *arr, int root, int bottom);
void _insertionsort (TYPE_DATA *arr, int left, int right);
```
