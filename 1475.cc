#include <stdio.h>
int CharToi(char c) {
  int num = 0;
  switch (c) {
    case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
     {num = c - 'a' + 10; break;}
    case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
     {num = c - 'A' + 10; break;}
    default: {num = c - '0'; break;}
  }
  return num;
}
int main(int argc, char** argv) {
  int value = 0, scale, input_len = 0;
  char input[8];
  char c;
  while ((c = getchar()) != EOF) {
    if (c == ' ') break;
    input[input_len++] = c;
  }
  input[input_len] = '\0';
  scanf("%d", &scale);
  for (int i = 0; i < input_len; ++i) {
    value *= scale;
    value += CharToi(input[i]);
  }
  printf("%d", value);
  return 0;
}
