#include <stdio.h>
#include <stdint.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

FILE* fp;

int main(void) {
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  // open example.txt
  fp = fopen("example4.txt", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
  }

  max = 0;
  while ((len = get_line(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
    if (len > 80) {
      printf("%s", line);
    }
  }

  if (max > 0) {
    printf("Longest line: %s", longest);
  }
}

// get_line: read a line into s, return length
int get_line(char s[], int lim) {
  int c, i;

  for (i = 0; (i < (lim - 1)) && ((c = getc(fp)) != EOF) && (c != '\n'); ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i++] = c;
  }

  s[i] = '\0';
  return i;
}

// copy: copy 'from' into 'to'; assume to is big enough
void copy(char to[], char from[]) {
  int i = 0;

  while ((to[i] = from[i]) != '\0') {
    i++;
  }
}
