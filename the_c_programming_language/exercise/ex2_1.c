#include <stdio.h>
#include <stdint.h>

// get max value of integer types from limits.h
#include <limits.h>



int main(void) {
  int8_t int8     = 0xFF / 2 + 1;
  uint8_t uint8   = 0xFF;
  int16_t int16   = 0xFFFF / 2 + 1;
  uint16_t uint16 = 0xFFFF;
  int32_t int32   = 0xFFFFFFFF / 2 + 1;
  uint32_t uint32 = 0xFFFFFFFF;

  printf("  int8: %d \n"
         " uint8: %d \n"
         " int16: %d \n"
         "uint16: %d \n"
         " int32: %d \n"
         "uint32: %lu \n",
         int8, uint8, int16, uint16, int32, uint32);

  printf("INT_MAX: %d \n"
         "INT_MIN: %d \n"
         "UINT_MAX: %d \n",
         INT_MAX, INT_MIN, UINT_MAX);
}
