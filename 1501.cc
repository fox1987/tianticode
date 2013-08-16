#include <stdio.h>
int MaxHeightAndWidth(int array[][2], int len, int i, int level, int* level_count) {
  if (array[i][0] == 0 && array[i][1] == 0) {
    ++level_count[level];
    return 1;
  }
  int left_height = 0, right_height = 0;
  ++level_count[level];
  if (array[i][0] != 0) {
    left_height = MaxHeightAndWidth(array, len, array[i][0], level + 1, level_count);
  }
  if (array[i][1] != 0) {
    right_height = MaxHeightAndWidth(array, len, array[i][1], level + 1, level_count);
  }
  int height = left_height > right_height ? 1 + left_height : 1 + right_height;
  return height;
}
int ShowArray(int* array, int len) {
  for (int i = 0; i < len; ++i) {
    printf("%d : %d\n", i, array[i]);
  }
  return 0;
}

int main(int argc, char** argv) {
  int n;
  scanf("%d", &n);
  int array[34][2] = {0};
  int level_count[17] = {0};
  array[0][0] = 1;
  array[0][1] = 1;
  int array_len = 1;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &array[array_len][0], &array[array_len][1]);
    ++array_len;
  }
  int max_height = MaxHeightAndWidth(array, array_len, 1, 0, level_count);
  int max_width = 1;
  for (int i = 0; i < 17; ++i) {
    if (level_count[i] > max_width) {
      max_width = level_count[i];
    }
  }
  printf("%d %d", max_width, max_height);
  return 0;
}
