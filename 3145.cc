#include <stdio.h>
void hanno(char a, char b, char c, int n) {
  if (n == 1) {
    printf("1 from %c to %c\n", a, c);
    return ;
  }
  hanno(a, c, b, n-1);
  printf("%d from %c to %c\n", n, a, c);
  hanno(b, a, c, n-1);
}

int main(int argc, char** argv) {
  int n;
  scanf("%d", &n);
  printf("%d\n", (1<<n) - 1);
  hanno('A', 'B', 'C', n);
  return 0;
}
