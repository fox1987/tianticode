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

// less : -1, eq : 0, large : 1
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
int Sub(char* s1, int len1, char* s2, int len2, char* result, int& len_result) {
  int carry = 0;
  ReverseStr(s1, len1);
  ReverseStr(s2, len2);
  int pos1 = 0, pos2 = 0;
  while (pos1 < len1 && pos2 < len2) {
    int num = s1[pos1] - '0'  -  (s2[pos2] - '0') - carry;
    if (num < 0) {
      num += 10;
      carry = 1;
    } else {
      carry  = 0;
    }
    result[len_result++] = num + '0';
    ++pos1;
    ++pos2;
  }
  if (pos1 < len1) {
    while (pos1 < len1) {
      int num = s1[pos1] - '0' - carry;
      if (num < 0) {
        num += 10;
        carry = 1;
      } else {
        carry = 0;
      }
      result[len_result++] = num + '0';
      ++pos1;
    }
  } else {
    // can not be this
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
  int sign = 1;
  if (CompareStr(num1, len1, num2, len2) == 0) {
    result[0] = '0';
    result[1] = '\0';
  } else if (CompareStr(num1, len1, num2, len2) < 0) {
    sign = 0;
    Sub(num2, len2, num1, len1, result, result_len);
  } else {
    Sub(num1, len1, num2, len2, result, result_len);
  }
  if (sign) {
    printf("%s", result);
  } else {
    printf("-%s", result);
  }
  return 0;
}
