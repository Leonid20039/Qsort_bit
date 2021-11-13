// 112-Чудновский-Леонид
// Проверка на правильность сортировки
#include <stdio.h>
#include "sort.h"
void check_sort(int *mass, int n){
    int a = 0, e, f;
    for (int i = 0; i < n-1; i++){
        e = count_bit(mass[i]);
        f = count_bit(mass[i + 1]);
        if(e > f){
            a = 1;
        }
    }
    if ( a == 0){
        printf("The mass is correctly sorted\n");
    }
    if (a == 1){
        printf("The mass is not correctly sorted\n");
    }
}
