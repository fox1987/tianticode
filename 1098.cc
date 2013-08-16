#include <stdio.h>
int main(int argc, char** argv) {
  int n, sum = 0, avg = 0, mv_count = 0;
  int table[101] = {0};
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &table[i]);
    sum += table[i];
  }
  avg = sum / n;
  if (avg * n != sum) {
    printf("%d", -1);
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if (table[i] != avg) {
      int need = avg - table[i];
      table[i] += need;
      table[i+1] -= need;
      ++mv_count;
    }
  }
  printf("%d", mv_count);
  return 0;
}
