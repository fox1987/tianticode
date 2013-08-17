#include <stdio.h>
#include <string.h>

const int kMaxLen = 502;
int StrToInt(char* s, int len) {
  int num = 0, pos = 0;
  while (pos < len) {
    num *= 10;
    num += s[pos++] - '0';
  }
  return num;
}

// less : <0, eq : 0, large : >0
int CompareStr(char* s1, int len1, char* s2, int len2) {
  if (len1 < len2) {
    return -1;
  } else if (len1 > len2) {
    return 1;
  } else {
    // note this  In C++
    // 当s1<s2时，返回值小于0
    // 当s1==s2时，返回值等于0
    // 当s1>s2时，返回值 大于0
    return strcmp(s1, s2);
  }
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
int Multi(char* s1, int len1, char* s2, int len2, char* result, int& len_result) {
  int carry = 0;
  ReverseStr(s1, len1);
  ReverseStr(s2, len2);
  int tmp_array[kMaxLen * 2 + 1]= {0};
  for (int pos1 = 0; pos1 < len1; ++pos1) {
    for (int pos2 = 0; pos2 < len2; ++pos2) {
      tmp_array[pos1 + pos2] += (s1[pos1] - '0') * (s2[pos2] - '0');
    }
  }
  for (int i = 0; i < len1 + len2; ++i) {
    int val = tmp_array[i] + carry;
    result[len_result++] = val % 10 + '0';
    carry = val / 10;
  }
  while(carry) {
    result[len_result++] = carry % 10 + '0';
    carry /= 10;
  }
  while (result[--len_result] == '0');
  result[++len_result] = '\0';
  ReverseStr(s1, len1);
  ReverseStr(s2, len2);
  ReverseStr(result, len_result);
  return len_result;
}

int main(int argc, char** argv) {
  char num1[kMaxLen] = {0};
  char num2[kMaxLen] = {0};
  char result[kMaxLen * 2 + 1] = {0};
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
  Multi(num2, len2, num1, len1, result, result_len);
  printf("%s", result);
  return 0;
}
