#include <stdio.h>
int Func(int n) {
  if (n >= 0) return 5;
  return Func(n + 1) + Func(n + 2) + 1;
}
int main(int argc, char** argv) {
  int n = 0;
  scanf("%d", &n);
  printf("%d", Func(n));
  return 0;
}
