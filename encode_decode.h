#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M_MAX 4      //строки
#define N_MAX 6      //столбцы
#define p 0.3    //вероятность
#define I_MAX 10 //максимальное число итераций

int encode(int string[M_MAX], int res[N_MAX], int G[M_MAX][N_MAX], int G_M, int G_N);

int decode(int string[N_MAX], int H[M_MAX][N_MAX], int H_M, int H_N);

int check(int string[N_MAX], int H[M_MAX][N_MAX], int H_M, int H_N);