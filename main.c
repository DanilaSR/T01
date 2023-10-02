#include "encode_decode.h"

int main()
{
    int string[M] = {0, 0, 1};
    int res[N];

    encode(string, res);

    printf("Посланное сообщение:\n");
    for (int i = 0; i < N; i++){
        printf("%d ", res[i]);        
    }
    printf("\n");

    srand(time(NULL));
    for (int i = 0; i < N; i++){ 
        int rnd = rand() % 100;
        if (rnd < p * 100){
            res[i] = (res[i] + 1) % 2;
        }
    }

    printf("Полученное сообщение:\n");
    for (int i = 0; i < N; i++){
        printf("%d ", res[i]);        
    }
    printf("\n");


    decode(res);

    printf("Декодированное сообщение:\n");
    for (int i = 0; i < N; i++){
        printf("%d ", res[i]);        
    }
    printf("\n");

    return 0;
}