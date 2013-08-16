#include <stdio.h>

const int kMaxLen = 502;
int StrToInt(char* s, int len) {
  int num = 0, pos = 0;
  while (pos < len) {
    num *= 10;
    num += s[pos++] - '0';
  }
  return num;
}

template <class Type>
void Swap(Type& a, Type& b) {
  Type temp = a;
  a = b;
  b = temp;
}
char* ReverseStr(char* s, int len) {
  for (int i = 0; i < len/2; ++i) {
    Swap(s[i], s[len - 1 - i]);
  }
  return s;
}

int IntToChar(char* s, int num) {
  return sprintf(s, "%d", num);
}
int Min(int num1, int num2) {
  return num1 < num2 ? num1 : num2;
}
int Add(char* s1, int len1, char* s2, int len2, char* result, int& len_result) {
  int carry = 0;
  ReverseStr(s1, len1);
  ReverseStr(s2, len2);
  int pos1 = 0, pos2 = 0;
  len_result = 0;
  while (pos1 < len1 && pos2 < len2) {
    int num = s1[pos1] - '0' + s2[pos2] - '0' + carry;
    carry = num / 10;
    num = num %10;
    result[len_result++] = num + '0';
    ++pos1;
    ++pos2;
  }
  if (pos1 < len1) {
    while (pos1 < len1) {
      int num = s1[pos1] - '0' + carry;
      carry = num / 10;
      num = num %10;
      result[len_result++] = num + '0';
      ++pos1;
    }
  } else if (pos2 < len2) {
    while (pos2 < len2) {
      int num = s2[pos2] - '0' + carry;
      carry = num / 10;
      num = num %10;
      result[len_result++] = num + '0';
      ++pos2;
    }
  } else {
    if (carry) {
      result[len_result++] = '1';
    }
  }
  result[len_result] = '\0';
  ReverseStr(s1, len1);
  ReverseStr(s2, len2);
  ReverseStr(result, len_result);
  return len_result;
}

int main(int argc, char** argv) {
  char num1[kMaxLen] = {0};
  char num2[kMaxLen] = {0};
  char result[kMaxLen + 1] = {0};
  int len1 = 0, len2 = 0 ,result_len = 0;
  char c;
  while ((c=getchar()) != EOF) {
    if (c == ' ') {
      break;
    }
    num1[len1++] = c;
  }
  num1[len1] = '\0';
  while ((c=getchar()) != EOF) {
    if (c == ' '|| c =='\n') {
      break;
    }
    num2[len2++] = c;
  }
  num2[len2] = '\0';
  Add(num1, len1, num2, len2, result, result_len);
  printf("%s", result);
  return 0;
}
