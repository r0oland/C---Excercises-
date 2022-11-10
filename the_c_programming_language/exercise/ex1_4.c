#include <stdio.h>

// print celsius-to-farenheit table
// for celius = -20, -40, ..., 160  floating-point version
// (DegC * 1.8) + 32 = DegF

int main() {
  float fahr, cel;
  int lower, upper, step;

  lower = -20;   // lower limit of temperature table
  upper = 160; // upper limit
  step  = 20;  // step size

  cel = lower;
  printf("DegC DegF\n");

  
  while (cel <= upper) {
    fahr = cel * 1.8 + 32;
    printf("%6.1f\t%3.0f\n", cel, fahr);
    cel = cel + step;
  }
  printf("\n");
}
