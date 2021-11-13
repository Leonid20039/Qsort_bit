// 112-Чудновский-Леонид
// Сортировка массива с помощью алгоритма qsort в соответствии с порядком возрастания единичных битов числа
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#define N 25000

int main(void) {
	char filename[120];	
	int mass[N], mass_bit[N];
	clock_t  start, end;	
	int i, j, a, Low = -10000, High = 10000, k;		
	double time;
	int n = 25000;	
	FILE* fin;	
		
		printf("Enter file name:");
		scanf("%s", filename);
		fin = fopen(filename, "w");

		// провекрка на возможность открыть файл
		if(!fin){
			printf("Unable to open %s\n", filename);
			return 1;
		}

		// заполнение массива случайными числами
		for(int i = 0; i < n; i++){
			mass[i] = random(Low, High);
			fprintf(fin, "%d  ", mass[i]);

		}
		// сортировка
		start = clock();		
		q_sort(mass, 0, n - 1);		
		end = clock();					
		time = (double)(end - start) / CLOCKS_PER_SEC;	// время сортировки 
		check_sort(mass, n); // проверка на верность сортировки

		//Выводим
         fprintf(fin, "Sort mass:\n");
		 for(int i = 0; i < N; i++){
        a = count_bit(mass[i]);
        fprintf(fin, "%d   ", mass[i]);
         
        for(int j = 1; j < 32; j++){
            mass_bit[32-j] = mass[i]&1;
            fprintf(fin, "%d", mass_bit[32-j]);
            mass[i] >>= 1;
        }
        fprintf(fin, "    %d\n", a);
    }
		
		printf("Number of elements: %d\n", n);
		printf("Time sort: %f\n\n", time);
	return 0;
}