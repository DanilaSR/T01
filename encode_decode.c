#include "encode_decode.h"

int encode(int string[3], int res[6]){
    int G[3][6]   = {{1, 0, 0, 1, 0, 1},
                     {0, 1, 0, 1, 1, 1},
                     {0, 0, 1, 0, 1, 1}};

    multiply(string, G, res);
    return 0;
}

int decode(int string[N]){
    int H[M][N]   = {{1, 1, 0, 1, 0, 0},
                     {0, 1, 1, 0, 1, 0},
                     {1, 0, 0, 0, 1, 1},
                     {0, 0, 1, 1, 0, 1}};

    double R[M][N];
    double E[M][N];
    double r[N], L[N];

    for (int i = 0; i < N; i++){
        if (string[i] == 1){
            r[i] = log(p/(1-p));
        }
        else if (string[i] == 0){
            r[i] = log((1-p)/p);
        }
    }

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            R[i][j] = r[j] * H[i][j];
        }
    }

    int I = 1;
    while(1){
        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                double p1 = 1;
                if (H[i][j] == 1){
                    for (int k = 1; k < N; k++){
                        if (H[i][(j + k) % N] == 1){
                            p1 *= tanh(R[i][(j + k) % N]/2);
                        }
                    }
                    E[i][j] = log ((1 + p1) / (1 - p1));
                }
            }
        }

        for (int i = 0; i < N; i++){
            double sum = 0;
            for (int j = 0; j < M; j++){
                sum += E[j][i];
            }

            L[i] = r[i] + sum;
        }

        for (int i = 0; i < N; i++){
            if (L[i] > 0){
                string[i] = 0;
            } 
            else if (L[i] <= 0){
                string[i] = 1;
            }      
        }
        
        if (check(string) == 0 || I == I_max){
            break;
        }else{
            for (int i = 0; i < N; i++){
                for (int j = 0; j < M; j++){
                    double sum = 0;
                    if (H[j][i] == 1){
                        for (int k = 1; k < M; k++){
                            if (H[(j + k) % M][i] == 1){
                                sum += E[(j + k) % M][i];
                            }
                        }                   
                        R[j][i] = r[i] + sum; 
                    }
                }
            }

            I += 1;
            continue;
        }

    }    

    return 0;

}

int multiply(int string[3], int matrix[3][6], int res[6]){

    for (int i = 0; i < 6; i++){
        int sum = 0;
        for (int j = 0; j < 3; j++){
            sum += string[j]*matrix[j][i];
        }
        res[i] = sum;
    }
    
    return 0;
}

int check(int string[N]){
    int H[M][N]   = {{1, 1, 0, 1, 0, 0},
                     {0, 1, 1, 0, 1, 0},
                     {1, 0, 0, 0, 1, 1},
                     {0, 0, 1, 1, 0, 1}};
    int flag = 1;
    int sum = 0;
    for (int j = 0; j < M; j++){
        for (int i = 0; i < N; i++){
            sum += string[i] * H[j][i];
        }
        if (sum % 2 != 0){
            flag = 0;
        }
    }

    if (flag == 1){
        return 0;
    }
    else{
        return 1;
    }   
}