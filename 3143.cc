#include <stdio.h>
void PreOrder(int array[][2], int len, int i) {
  if (i >= len) return;
  printf("%d ", i);
  if (array[i][0]) PreOrder(array, len, array[i][0]);
  if (array[i][1]) PreOrder(array, len, array[i][1]);
}
void MidOrder(int array[][2], int len, int i) {
  if (i >= len) return;
  if (array[i][0]) MidOrder(array, len, array[i][0]);
  printf("%d ", i);
  if (array[i][1]) MidOrder(array, len, array[i][1]);
}
void PostOrder(int array[][2], int len, int i) {
  if (i >= len) return;
  if (array[i][0]) PostOrder(array, len, array[i][0]);
  if (array[i][1]) PostOrder(array, len, array[i][1]);
  printf("%d ", i);
}

int main(int argc, char** argv) {
  int n;
  scanf("%d", &n);
  int array[34][2] = {0};
  array[0][0] = 1;
  array[0][1] = 1;
  int array_len = 1;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &array[array_len][0], &array[array_len][1]);
    ++array_len;
  }
  PreOrder(array, array_len, 1);
  printf("\n");
  MidOrder(array, array_len, 1);
  printf("\n");
  PostOrder(array, array_len, 1);
  return 0;
}
