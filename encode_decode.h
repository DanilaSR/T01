#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 6   //столбцы
#define M 4   //строки
#define p 0.3 //вероятность
#define I_max 10 //максимальное число итераций

int encode(int string[3], int res[6]);

int decode(int string[N]);

int multiply(int string[3], int matrix[3][6], int res[6]);

int check(int string[N]);