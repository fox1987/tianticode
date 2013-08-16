#include <stdio.h>
// #define StartNodeMethod
typedef struct Line {
  int start;
  int end;
}Line;


template <typename T>
void Swap(T &x1, T &x2) {
  T tmp = x1;
  x1 = x2;
  x2 = tmp;
}

void ShowArray(Line* array, int len) {
  for (size_t i = 0; i < len; ++i) {
    printf("%d,%d\n", array[i].start, array[i].end);
  }
}

#ifdef StartNodeMethod
// less:-1 eq: 0 large: 1
int CompareLine(const Line& line1, const Line& line2) {
  if (line1.start < line2.start) {
    return -1;
  } else if (line1.start > line2.start) {
    return 1;
  } else {
    if (line1.end < line2.end) {
      return -1;
    } else if (line2.end > line2.end) {
      return 1;
    } else {
      return 0;
    }
  }
}
void SortArray(Line* array, int len) {
  // maopao
  // little up
  for (int i = 0; i < len; i++) {
    for (int j = i+1; j < len; j++) {
      if (CompareLine(array[i], array[j]) == 1) {
        Swap(array[i], array[j]);
      }
    }
  }
}
int NoCoverLineCount(Line* line_array, int len) {
  int result_count = len, last_line_pos = 0;
  for (int i = 1; i < len; ++i) {
    if (line_array[i].start < line_array[last_line_pos].end) {
      --result_count;
      if (line_array[i].end < line_array[last_line_pos].end) {
        last_line_pos = i;
      }
    } else {
      last_line_pos = i;
    }
  }
  return result_count;
}
#else
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
int NoCoverLineCount(Line* line_array, int len) {
  int result_count = len, last_line_pos = 0;
  for (int i = 1; i < len; ++i) {
    if (line_array[i].end > line_array[last_line_pos].start) {
      --result_count;
      if (line_array[i].start > line_array[last_line_pos].start) {
        last_line_pos = i;
      }
    } else {
      last_line_pos = i;
    }
  }
  return result_count;
}
#endif
int main(int argc, char** argv) {
  int input_count;
  int result_count = 0;
  scanf("%d", &input_count);
  Line line_array[101] = {0};
  for (int i = 0; i < input_count; ++i) {
    int x1, x2;
    scanf("%d %d", &x1, &x2);
    if (x1 > x2) {
      Swap(x1, x2);
    }
    line_array[i].start = x1;
    line_array[i].end = x2;
  }
  SortArray(line_array, input_count);
  ShowArray(line_array, input_count);
  result_count = NoCoverLineCount(line_array, input_count);
  printf("%d", result_count);
  return 0;
}
