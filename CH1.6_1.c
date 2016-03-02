#include "stdio.h"

void calcAllPermutation(char str[], int from, int to);
void swap(char str[], int from, int index);

int main(int argc, char const *argv[])
{
  char str[] = "abcd";

  calcAllPermutation(str, 0, 3);

  return 0;
}

void calcAllPermutation(char str[], int from, int to) {
  if (from == to)
  {
    printf("%s\n", str);
    return;
  }

  int index = from;

  while(index <= to) {
    swap(str, from, index);
    calcAllPermutation(str, from+1, to);
    swap(str, from, index);
    index++;
  }
}

void swap(char str[], int from, int index) {
  char tmp = str[from];
  str[from] = str[index];
  str[index] = tmp;
}