#include <stdio.h>

int Compute3NPlus1(int n) {
  if (n < 0) return 0;
  if (n == 1) return 0;
  if (n %2 ==1) { // odd
    return 1 + Compute3NPlus1(3 * n +1);
  } else { // even
    return 1 + Compute3NPlus1(n /2);
  }
}
int main(int argc, char** argv) {
  int n = 0;
  int array[10000] = {0};
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &array[i]);
  }
  for (int i = 0; i < n; ++i) {
    printf("%d\n", Compute3NPlus1(array[i]));
  }
  return 0;
}
