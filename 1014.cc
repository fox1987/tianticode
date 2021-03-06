#include <stdio.h>
/* 
 *  This is a 0 /1 bag problem
 */
// #define DEBUG
const int kMaxGoodsNum = 30;
const int kMaxCapacityNum = 20000;
int Min(int num1, int num2) {
  return num1 < num2 ? num1 : num2;
}

int Max(int num1, int num2) {
  return num1 < num2 ? num2 : num1;
}

int main(int argc, char** argv) {
  int box[kMaxGoodsNum+1][kMaxCapacityNum+1] = {0};
  int box_capacity[kMaxGoodsNum+1] = {0};
  int total_capacity = 0, box_num = 0;
  scanf("%d", &total_capacity);
  scanf("%d", &box_num);
  for (int i = 0; i < box_num; ++i) {
    scanf("%d", &box_capacity[i]);
  }
  for (int i = box_capacity[0]; i < total_capacity+1; ++i) {
    box[0][i] =  box_capacity[0];
  }
  for (int j = 1; j < box_num; ++j) {
    for (int i = 1; i < total_capacity+1; ++i) {
      if (i >= box_capacity[j]) {
        box[j][i] = Max(box[j - 1][i - box_capacity[j]] + box_capacity[j], box[j - 1][i]);
      } else {
        box[j][i] = box[j-1][i];
      }
    }
  }

#ifdef DEBUG
  printf("    ");
  for (int i = 1; i < total_capacity+1; ++i) {
    printf("%2d ", i);
  }
  printf("\n");

  for (int j = 0; j < box_num; ++j) {
    printf("%2d :", box_capacity[j]);
    for (int i = 1; i < total_capacity + 1; ++i) {
      printf("%2d ", box[j][i]);
    }
    printf("\n");
  }
  printf("box[%d][%d]:%d", box_num -1, total_capacity, box[box_num-1][total_capacity]);
#else
  printf("%d", total_capacity - box[box_num-1][total_capacity]);
#endif
  return 0;
}
