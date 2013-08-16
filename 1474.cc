#include <stdio.h>

void ScaleTrans(int value, int scale) {
  if (value < scale) {
    printf("%X", value);
    return;
  }
  ScaleTrans(value / scale, scale);
  printf("%X", value % scale);
  return;
}
int main(int argc, char** argv) {
  int value, scale;
  scanf("%d %d", &value, &scale);
  ScaleTrans(value, scale);
  return 0;
}
