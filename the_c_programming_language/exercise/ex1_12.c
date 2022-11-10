#include <stdio.h>
#include <stdint.h>
#include <time.h>

// count lines in input

typedef uint8_t bool;

#define IN              1 // inside a word
#define OUT             0 // outside a word
#define MAX_WORD_LENGTH 15
#define NUM_ABC         26

int main() {

  clock_t begin = clock();

  // open example.txt
  FILE* fp;
  fp = fopen("example2.txt", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
  }

  // word counting
  char c;
  uint32_t numLines, numWords, numChars, wordLength;
  bool state;
  state = OUT;

  uint32_t wordLengths[MAX_WORD_LENGTH]    = {0};
  uint8_t normWordLengths[MAX_WORD_LENGTH] = {0};

  uint32_t numABC[NUM_ABC]    = {0};
  uint8_t normNumABC[NUM_ABC] = {0};

  numLines = numWords = numChars = wordLength = 0;
  while ((c = getc(fp)) != EOF) {
    numChars++;
    // check for newline
    if (c == '\n') {
      numLines++;
    }
    // check for whitespace, this means this word is over
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      // store the length of the word
      if (wordLength > MAX_WORD_LENGTH) {
        wordLength = MAX_WORD_LENGTH;
      }
      wordLengths[wordLength]++;
      wordLength = 0; // reset our wordlength
    } else if (state == OUT) {
      state = IN;
      numWords++;
    } else if (state == IN) {
      wordLength++;
      // counts a-z and A-Z
      if ((c >= 'A' && c <= 'Z')) {
        // turn capital letters into lowercase
        c += 32;
      }
      if (c >= 'a' && c <= 'z'){
        c -= 'a'; // start at 0
        numABC[(uint8_t)c]++;
      }
      // count the character occurance
    }
  }
  printf("new lines: %d words: %d chars: %d\n", numLines, numWords, numChars);

  // get the maximum word count of the histogram to scale the histogram
  uint16_t maxWordCount = 0;
  for (int i = 0; i < MAX_WORD_LENGTH; i++) {
    if (wordLengths[i] > maxWordCount) {
      maxWordCount = wordLengths[i];
    }
  }

  // scale the histogram
  for (int i = 0; i < MAX_WORD_LENGTH; i++) {
    normWordLengths[i] = (wordLengths[i] * 30) / maxWordCount;
  }

    // print the histogram
  for (uint8_t i = 0; i < MAX_WORD_LENGTH; i++) {
    printf("%2d=", i);
    printf("%6u words | ", wordLengths[i]);
    for (int j = 0; j < normWordLengths[i]; j++) {
      printf("X");
    }
    printf("\n");
  }

  printf("#######################################################\n");

  // ===========================================================================
  // get the maximum char count of the histogram to scale the histogram
  uint32_t maxCharCount = 0;
  for (int i = 0; i < NUM_ABC; i++) {
    if (numABC[i] > maxCharCount) {
      maxCharCount = numABC[i];
    }
  }

  // scale the histogram
  for (int i = 0; i < NUM_ABC; i++) {
    normNumABC[i] = (numABC[i] * 30) / maxCharCount;
  }

  // print the histogram
  for (uint8_t i = 0; i < NUM_ABC; i++) {
    printf("%c=", i + 'a');
    printf("%6ux | ", numABC[i]);
    for (int j = 0; j < normNumABC[i]; j++) {
      printf("X");
    }
    printf("\n");
  }

  clock_t end       = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("time spent: %f seconds\n", time_spent);
}
