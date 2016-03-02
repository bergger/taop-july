#include "stdio.h"

void LeftRotateString(char* s, int n, int m);
void LeftShiftOne(char* s, int n);

int main(int argc, char const *argv[])
{
  char str[] = "abcdefg";
  printf("%s\n", str );
  LeftRotateString(str, 7, 2);
  printf("%s\n", str );
  return 0;
}

void LeftRotateString(char s[], int n, int m) {
  while(m--) {
    LeftShiftOne(s, n);
  }
}

void LeftShiftOne(char s[], int n) {
  char temp = s[0];
  for (int i = 0; i < n-1; ++i)
  {
     s[i] = s[i+1];
  } 
  s[n-1] = temp;
}
