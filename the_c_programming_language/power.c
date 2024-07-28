#include <stdio.h>

int power(int base, int exponent);

int main() {
  for (int i = 0; i < 10; ++i) {
    printf("%d %3d %6d\n", i, power(2, i), power(-3, i));
  }
}

int power(int base, int exponent) {
  int result = 1;

  while (exponent > 0) {
    result *= base;
    --exponent;
  }

  return result;
}
