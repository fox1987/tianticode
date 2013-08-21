#include <stdio.h>

int Partion(int n, int k, int start) {
  if (k == 1) return 1;
  int count = 0;
  for (int i = start; i <= n/k; ++i) {
    count += Partion(n - i, k - 1, i);
  }
  return count;
}
int main(int argc, char** argv) {
  int n ,k;
  scanf("%d %d", &n, &k);
  printf("%d", Partion(n, k, 1));
  return 0;
}
