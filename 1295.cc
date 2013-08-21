#include <stdio.h>
#include <string.h>
#define MAXNUM 14
int Abs(int a) {
  return a >0 ? a : -a;
}
int NQueue(int n, int row, int* result, int result_len, int& count) {
  if (row == n)  ++count;
  for (int i = 0; i < n; ++i) {
    int valid = 1;
    for (int j = 0; j < result_len; ++j) {
      if (i == result[j] || (Abs(row - j) == Abs(i - result[j]))) {
        valid = 0;
        break;
      }
    }
    if (valid) {
      int tmp_result[MAXNUM] = {0};
      memcpy(tmp_result, result, result_len * sizeof(int));
      tmp_result[result_len] = i;
      NQueue(n, row+1, tmp_result, result_len + 1, count);
    }
  }
  return count;
}
int main(int argc, char** argv) {
  int num = 0, result = 0;
  scanf("%d", &num);
  int array[MAXNUM] = {0};
  printf("%d", NQueue(num, 0, array, 0, result));
  return 0;
}
