#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXNUM 100
#define ALG
void Swap(int& a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}
int JieCheng(int n) {
  if (n == 1) return 1;
  return n * JieCheng(n - 1);
}
void SortArray(int *array, int len) {
  for (int i = 0; i < len; ++i) {
    for (int j = i+1; j < len; ++j) {
      if (array[i] > array[j]) Swap(array[i], array[j]);
    }
  }
}
void ShowArray(int *array, int len) {
  for (int i = 0; i < len; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void Permutation(int* array, int len, int pos) {
  if (pos == len -1) {
    ShowArray(array + 1, len - 1);
    return;
  }
  int tmp_array[MAXNUM] = {0};
  for (int i = pos; i < len; ++i) {
    for (int j = 0; j < len; ++j) {
      tmp_array[j] = array[j];
    }
    Swap(array[pos], array[i]);
    SortArray(array + pos + 1, len - pos - 1);
    Permutation(array, len, pos+1);
    for (int j = 0; j < len; ++j) {
      array[j] = tmp_array[j];
    }
  }
}
int main(int argc, char** argv) {
  int n;
  int array[MAXNUM] = {0};
  scanf("%d", &n);
  for (int i = 1; i <=n; ++i) {
    array[i] = i;
  }
#ifdef  ALG
  ShowArray(array + 1, n);
  for (int i  = 1; i < JieCheng(n); ++i) {
    next_permutation(array+1, array+n+1);
    ShowArray(array + 1, n);
  }
#else
  Permutation(array, n+1, 1);
#endif
}
