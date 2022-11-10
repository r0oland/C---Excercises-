#include <stdio.h>

// count lines in input

int main() {
  // open example.txt
  FILE *fp;
  fp = fopen("example.txt", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
  }
  // print contents of example.txt
  int c;
  while ((c = getc(fp)) != EOF) {
    putchar(c);
  }


}
