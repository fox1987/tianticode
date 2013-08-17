#include <stdio.h>
const int kMaxCellNum = 360;
const int kMaxCardNum = 41;
int score[kMaxCardNum][kMaxCardNum][kMaxCardNum][kMaxCardNum] = {0};
/*
 * start from 0
 * score[i][j][k][l] = Max(score[i-1][j][k][l], score[i][j-1][k][l],
 *                         score[i][j][k-1][l], score[i][j][k][l-1])
 *                         + cell_score_array[i + 2j + 3k + 4l];
 */
int Max(int a, int b, int c, int d) {
  if (a < b) a = b;
  if (a < c) a = c;
  if (a < d) a = d;
  return a;
}
int main(int argc, char** argv) {
  int cell_num, card_num;
  scanf("%d %d", &cell_num, &card_num);
  int cell_score_array[kMaxCellNum] = {0};
  int card[5] = {0};
  for (int i = 0; i < cell_num; ++i) {
    scanf("%d", &cell_score_array[i]);
  }

  int temp_step;
  for (int i = 0; i < card_num; ++i) {
    scanf("%d", &temp_step);
    ++card[temp_step];
  }
  score[0][0][0][0] = cell_score_array[0];
  for (int i = 0; i <= card[1]; ++i) {
    for (int j = 0; j <= card[2]; ++j) {
      for (int k = 0; k <= card[3]; ++k) {
        for (int l = 0; l <= card[4]; ++l) {
          if (i == j && j == k && k == l && l == 0) {
            continue;
          }
          int tmp1 = 0, tmp2 = 0, tmp3 = 0, tmp4 = 0;
          int inc_score = cell_score_array[i + 2 * j + 3 * k + 4 * l];
          if (i != 0) {
            tmp1 = score[i - 1][j][k][l] + inc_score;
          }
          if (j != 0) {
            tmp2 = score[i][j - 1][k][l] + inc_score;
          }
          if (k != 0) {
            tmp3 = score[i][j][k - 1][l] + inc_score;
          }
          if (l != 0) {
            tmp4 = score[i][j][k][l - 1] + inc_score;
          }
          score[i][j][k][l] = Max(tmp1, tmp2, tmp3, tmp4);
        }
      }
    }
  }
  printf("%d", score[card[1]][card[2]][card[3]][card[4]]);
  return 0;
}
