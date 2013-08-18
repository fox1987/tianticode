#include <stdio.h>
#define MaxLineNum 1001
#define DEBUG
typedef struct Line {
  int start;
  int end;
  int val;
}Line;

int Max(int a, int b) {
  return a > b ? a : b;
}

template <typename T>
void Swap(T &x1, T &x2) {
  T tmp = x1;
  x1 = x2;
  x2 = tmp;
}

void ShowArray(Line* array, int len) {
  for (size_t i = 0; i < len; ++i) {
    printf("%d,%d,%d\n", array[i].start, array[i].end, array[i].val);
  }
}
// use end node 
// less:-1 eq: 0 large: 1
int CompareLine(const Line& line1, const Line& line2) {
  if (line1.end < line2.end) {
    return -1;
  } else if (line1.end > line2.end) {
    return 1;
  } else {
    if (line1.start < line2.start) {
      return -1;
    } else if (line2.start > line2.start) {
      return 1;
    } else {
      return 0;
    }
  }
}
void SortArray(Line* array, int len) {
  // maopao
  // large up
  for (int i = 0; i < len; i++) {
    for (int j = i+1; j < len; j++) {
      if (CompareLine(array[i], array[j]) == -1) {
        Swap(array[i], array[j]);
      }
    }
  }
}
int NoCoverLineValue(Line* line_array, int len) {
  Line value_array[MaxLineNum] = {0};
  value_array[0] = line_array[0];
  int result_count = len, last_line_pos = 0, max_value = value_array[0].val;
  for (int i = 1; i < len; ++i) {
    int max_sub_val = 0;
    for (int j = 0; j < i; ++j) {
      if (line_array[i].end <= value_array[j].start) {
        max_sub_val = Max(max_sub_val, value_array[j].val);
      }
    }
    value_array[i].val = max_sub_val + line_array[i].val;
    value_array[i].start = line_array[i].start;
    max_value = Max(max_value, value_array[i].val);
  }
#ifdef DEBUG
  ShowArray(value_array, len);
#endif
  return max_value;
}
int main(int argc, char** argv) {
  int input_count;
  int max_value = 0;
  scanf("%d", &input_count);
  Line line_array[MaxLineNum] = {0};
  for (int i = 0; i < input_count; ++i) {
    int x1, x2, x3;
    scanf("%d %d %d", &x1, &x2, &x3);
    line_array[i].start = x1;
    line_array[i].end = x2;
    line_array[i].val = x3;
  }
  SortArray(line_array, input_count);
#ifdef DEBUG
  ShowArray(line_array, input_count);
#endif
  max_value = NoCoverLineValue(line_array, input_count);
  printf("%d", max_value);
  return 0;
}
