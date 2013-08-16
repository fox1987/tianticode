#include <stdio.h>
void ShowTable(int *arr, int len) {
  for (int i = 0; i < len; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
int main(int argc, char** argv) {
  int n;
  int table[1000] = {0};
  scanf("%d", &n);
  table[1] = 1;
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= i/2; ++j) {
      // printf("table[%d] += table[%d] : %d\n", i, j, table[j]);
      table[i] += table[j];
    }
    table[i] += 1;
    // ShowTable(table, i);
  }
  // ShowTable(table, n+1);
  printf("%d", table[n]);
  return 0;
}
