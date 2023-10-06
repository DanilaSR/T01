#include "encode_decode.h"

int main() {
  int G_M = 3, G_N = 6;
  int G[M_MAX][N_MAX] =  {{1, 0, 0, 1, 0, 1}, 
                          {0, 1, 0, 1, 1, 1}, 
                          {0, 0, 1, 0, 1, 1}};

  int H_M = 4, H_N = 6;
  int H[M_MAX][N_MAX] = {{1, 1, 0, 1, 0, 0},
                         {0, 1, 1, 0, 1, 0},
                         {1, 0, 0, 0, 1, 1},
                         {0, 0, 1, 1, 0, 1}};

  int string[M_MAX] = {0, 0, 1};
  int res[N_MAX];

  encode(string, res, G, G_M, G_N);

  printf("Посланное сообщение:\n");
  for (int i = 0; i < G_N; i++) {
    printf("%d ", res[i]);
  }
  printf("\n");

  srand(time(NULL));
  for (int i = 0; i < G_N; i++) {
    int rnd = rand() % 100;
    if (rnd < p * 100) {
      res[i] = (res[i] + 1) % 2;
    }
  }

  printf("Полученное сообщение:\n");
  for (int i = 0; i < G_N; i++) {
    printf("%d ", res[i]);
  }
  printf("\n");

  decode(res, H, H_M, H_N);

  printf("Декодированное сообщение:\n");
  for (int i = 0; i < H_N; i++) {
    printf("%d ", res[i]);
  }
  printf("\n");

  return 0;
}
