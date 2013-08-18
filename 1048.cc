#include <stdio.h>

#define MaxInput 101
#define DEBUG
int Min(int a, int b) {
  return a < b ? a : b;
}
int main(int argc, char** argv) {
  int input_num = 0;
  int store_array[MaxInput] = {0};
  int sum_array[MaxInput] = {0};
  int dp_array[MaxInput][MaxInput] = {0};
  scanf("%d", &input_num);
  for (int i = 0; i < input_num; ++i) {
    scanf("%d", &store_array[i]);
    if (i == 0) {
      sum_array[i] = store_array[i];
    } else {
      sum_array[i] += sum_array[i - 1] + store_array[i];
    }
  }
  for (int step = 1; step < input_num; ++step) {
    for (int i = 0; i < input_num - step; i++) {
      int j = i + step;
      for (int k = i; k < j; ++k) {
        if (dp_array[i][j] == 0) {
          dp_array[i][j] = dp_array[i][k] + dp_array[k+1][j] + sum_array[j] - sum_array[i] + store_array[i];
        } else {
          dp_array[i][j] = Min(dp_array[i][j], dp_array[i][k] + dp_array[k+1][j]
                + sum_array[j] - sum_array[i] + store_array[i]);
        }
      }
    }
  }
#ifdef DEBUG
  for(int i = 0; i < input_num; ++i) {
    for (int j = 0; j < input_num; ++j) {
      printf("%2d ", dp_array[i][j]);
    }
    printf("\n");
  }
#endif
  printf("%d", dp_array[0][input_num - 1]);
  return 0;
}
