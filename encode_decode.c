#include "encode_decode.h"

int encode(int string[M_MAX], int res[N_MAX], int G[M_MAX][N_MAX], int G_M, int G_N) {

  for (int i = 0; i < G_N; i++) {
    int sum = 0;
    for (int j = 0; j < G_M; j++) {
      sum += string[j] * G[j][i];
    }
    res[i] = sum;
  }

  return 0;
}

int decode(int string[N_MAX], int H[M_MAX][N_MAX], int H_M, int H_N) {

  double R[H_M][H_N];
  double E[H_M][H_N];
  double r[H_N], L[H_N];

  for (int i = 0; i < H_N; i++) {
    if (string[i] == 1) {
      r[i] = log(p / (1 - p));
    } else if (string[i] == 0) {
      r[i] = log((1 - p) / p);
    }
  }

  for (int i = 0; i < H_M; i++) {
    for (int j = 0; j < H_N; j++) {
      R[i][j] = r[j] * H[i][j];
    }
  }

  int I = 1;
  while (1) {
    for (int i = 0; i < H_M; i++) {
      for (int j = 0; j < H_N; j++) {
        double p1 = 1;
        if (H[i][j] == 1) {
          for (int k = 1; k < H_N; k++) {
            if (H[i][(j + k) % H_N] == 1) {
              p1 *= tanh(R[i][(j + k) % H_N] / 2);
            }
          }
          E[i][j] = log((1 + p1) / (1 - p1));
        }
      }
    }

    for (int i = 0; i < H_N; i++) {
      double sum = 0;
      for (int j = 0; j < H_M; j++) {
        sum += E[j][i];
      }

      L[i] = r[i] + sum;
    }

    for (int i = 0; i < H_N; i++) {
      if (L[i] > 0) {
        string[i] = 0;
      } else if (L[i] <= 0) {
        string[i] = 1;
      }
    }

    if (check(string, H, H_M, H_N) == 0 || I == I_MAX) {
      break;
    } else {
      for (int i = 0; i < H_N; i++) {
        for (int j = 0; j < H_M; j++) {
          double sum = 0;
          if (H[j][i] == 1) {
            for (int k = 1; k < H_M; k++) {
              if (H[(j + k) % H_M][i] == 1) {
                sum += E[(j + k) % H_M][i];
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


int check(int string[N_MAX], int H[M_MAX][N_MAX], int H_M, int H_N) {

  int flag = 1;
  int sum = 0;
  for (int j = 0; j < H_M; j++) {
    for (int i = 0; i < H_N; i++) {
      sum += string[i] * H[j][i];
    }
    if (sum % 2 != 0) {
      flag = 0;
    }
  }

  if (flag == 1) {
    return 0;
  } else {
    return 1;
  }
}