#include <stdio.h>

#define MaxArraySize 21
#define DEBUG
int MaxStrictAscendSubSeq(int* array, int len) {
  int max_sub_seq_len = 0;
  int sub_seq_array[MaxArraySize] = {0};
  sub_seq_array[0] = 1;
  for (int i = 1; i < len; ++i) {
    int tmp_max = 0;
    for (int j = 0; j < i; ++j) {
      if (array[j] < array[i] && sub_seq_array[j] > tmp_max) {
        tmp_max = sub_seq_array[j];
      }
    }
    sub_seq_array[i] = tmp_max + 1;
    if (sub_seq_array[i] > max_sub_seq_len) {
      max_sub_seq_len = sub_seq_array[i];
    }
  }
#ifdef DEBUG
  for (int i = 0; i < len; ++i) {
    printf("%d : %d\n", array[i], sub_seq_array[i]);
  }
#endif
  return max_sub_seq_len;
}

int MaxStrictDecendSubSeq(int* array, int len) {
  int max_sub_seq_len = 0;
  int sub_seq_array[MaxArraySize] = {0};
  sub_seq_array[0] = 1;
  for (int i = 1; i < len; ++i) {
    int tmp_max = 0;
    for (int j = 0; j < i; ++j) {
      if (array[j] > array[i] && sub_seq_array[j] > tmp_max) {
        tmp_max = sub_seq_array[j];
      }
    }
    sub_seq_array[i] = tmp_max + 1;
    if (sub_seq_array[i] > max_sub_seq_len) {
      max_sub_seq_len = sub_seq_array[i];
    }
  }
#ifdef DEBUG
  for (int i = 0; i < len; ++i) {
    printf("%d : %d\n", array[i], sub_seq_array[i]);
  }
#endif
  return max_sub_seq_len;
}
int main(int argc, char** argv) {
  int height_array[MaxArraySize] = {0};
  int height_array_size = 0;
  scanf("%d", &height_array_size);
  for (int i = 0; i < height_array_size; ++i) {
    scanf("%d", &height_array[i]);
  }
  printf("%d",MaxStrictAscendSubSeq(height_array, height_array_size));
  return 0;
}
