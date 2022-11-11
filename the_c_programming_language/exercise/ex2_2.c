#include <stdio.h>
#include <stdint.h>

void squeeze(char s[], int c);
int8_t any(char s1[], char s2[]);

int main(void) {
  char myString[] = "Hello World";

  printf("myString: %s \n", myString);

  squeeze(myString, 'l');

  printf("myString: %s \n", myString);

  char aCoolString[] = "XXX";
  char bCoolString[] = "abs;trey';lvkj;iqwerh.asfg";

  printf("idx = %i\n", any(aCoolString, bCoolString));
}

// squeeze: delete all c from s
void squeeze(char s[], int c) {
  int i, j;
  for (i = j = 0; s[i] != '\0'; i++) {
    if (s[i] != c) {
      s[j++] = s[i];
    }
  }
  s[j] = '\0';
}

int8_t any(char s1[], char s2[]) {
  int i, j;

  for (i = 0; s1[i] != '\0'; i++) {
    for (j = 0; s2[j] != '\0'; j++) {
      if (s1[i] == s2[j]) {
        printf("i = %i | j = %i | char = %c\n", i, j, s1[i]);
        return i;
      }
    }
  }
  return -1;
}