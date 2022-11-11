#include <stdio.h>
#include <stdint.h>

uint8_t getbits(uint8_t x, int8_t p, int8_t n);
uint8_t maskbits(uint8_t x, int8_t p, int8_t n);
uint8_t setbits(uint8_t x, int8_t p, int8_t n);
void printbits(uint8_t x);
uint8_t copy_bits(uint8_t x, uint8_t y, int8_t p, int8_t n);

int main(void) {
  printf("------------------\n");
  uint8_t a = 0xFF;
  uint8_t b = 0xAA;
  uint8_t c = 0x55;

  printbits(a);
  printbits(b);
  printbits(c);

  printf("------------------\n");
  a = getbits(a, 4, 4);
  b = getbits(b, 6, 4);
  c = getbits(c, 7, 2);

  printbits(a);
  printbits(b);
  printbits(c);

  printf("------------------\n");
  a = 0;
  b = 0xAA;
  b = 0xFF;
  // b = setbits(b, 5, 3);
  a = copy_bits(a, b, 5, 3);
  // c = getbits(b, 5, 3);
  c = maskbits(b, 7, 3);
  printbits(b);
  printbits(c);
  // printbits(a);
}

// getbits: get n bits from position p
uint8_t getbits(uint8_t x, int8_t p, int8_t n) {
  return (x >> (p + 1 - n)) & ~(~0 << n);
}
// maskbits
uint8_t maskbits(uint8_t x, int8_t p, int8_t n) {
  return x & (~(~0 << n) << p-n);
}

// setbits: set n bits from position p
uint8_t setbits(uint8_t x, int8_t p, int8_t n) {
  if (n == 0) {
    return x;
  }
  if (n > p) { // if n is greater than p, set all below p
    n = p + 1;
  }
  if (n == 8) {
    return ~0;
  }
  return x | (~(~0 << n) << (p + 1 - n));
}

uint8_t copy_bits(uint8_t x, uint8_t y, int8_t p, int8_t n) {
  return (x | getbits(y, p, n));
}

void printbits(uint8_t x) {
  int8_t i;
  for (i = 7; i >= 0; i--) {
    printf("%d", getbits(x, i, 1));
  }
  printf("\n");
}