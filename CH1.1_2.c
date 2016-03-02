#include "stdio.h"

void LeftRotateString(char* s, int n, int m);
void ReverseString(char* s, int from, int to);

int main(int argc, char const *argv[])
{
  char str[] = "abcdefg";
  printf("%s\n", str );
  LeftRotateString(str, (int)sizeof(str) - 1, 2);
  printf("%s\n", str );
  return 0;
}

void LeftRotateString(char s[], int n, int m) {
  ReverseString(s, 0, m-1);
  ReverseString(s, m, n-1);
  ReverseString(s, 0, n-1);

}

void ReverseString(char s[], int from, int to) {
  while(to-- > from++) {
    char tmp = s[from];
    s[from] = s[to];
    s[to] = tmp;
  }
}