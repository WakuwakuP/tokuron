#include <cstdio>

int main() {
  const int H = 5;
  const int W = 6;
  int tatami[H][W] = {0};

  for (int i = 0; i <= W / 2; ++i) {
    int tmp1 = 0, tmp2 = 0;
    for (int j = i; j < 6; j += 2) {
      if (0 == tatami[i][j] && 0 == tatami[i][j + 1]){
        tatami[i][j] = 1;
        tatami[i][j + 1] = 1;
      } else {
        tmp1 = j + 1;
      }
    }
    for (int j = i + 1; j < 5; j += 2) {
      if (0 == tatami[j][tmp1] && 0 == tatami[j + 1][tmp1]){
        tatami[j][tmp1] = 2;
        tatami[j + 1][tmp1] = 2;
      }
        tmp2 = j - 1;
    }
    for (int j = i; j >= 0; j -= 2) {
      if (0 == tatami[tmp2][j] && 0 == tatami[tmp2][j - 1]){
        tatami[tmp2][j] = 1;
        tatami[tmp2][j - 1] = 1;
      }
        tmp1 = j - 1;
    }
    for (int j = i + 1; j >= 0; j -= 2) {
      if (0 == tatami[j][tmp1] && 0 == tatami[j - 1][tmp1]){
        tatami[j][tmp1] = 2;
        tatami[j - 1][tmp1] = 2;
      }
    }
    for (int i = 0; i < H; ++i){
      for (int j = 0; j < W; ++j){
        if (1 == tatami[i][j]) {
          printf("-");
        } else if (2 == tatami[i][j]) {
          printf("|");
        } else {
          printf("*");
        }
      }
      printf("\n");
    }
    printf("\n");
  }

  for (int i = 0; i < H; ++i){
    for (int j = 0; j < W; ++j){
      if (1 == tatami[i][j]) {
        printf("-");
      } else if (2 == tatami[i][j]) {
        printf("|");
      } else {
        printf("*");
      }
    }
    printf("\n");
  }
  return 0;
}
