#include <stdio.h>

#define func(val) ((val) + 10)

int main() {
  int i = 10;
  printf("func(%i) = %i\n", i, func(i));
  float f = 5.5;
  printf("func(%.1f) = %.1f\n", f, func(f));
  double d = 1.25;
  printf("func(%.3e) = %.3e\n", d, func(d));

  void *bad_stuff = &i;
  printf("func(0x%016lx) = 0x%016lx\n", (uint64_t)bad_stuff,
         (uint64_t)func(bad_stuff));
}