#include <cstdint>
#include <cstdio>

int func(int i) { return i + 10; }
float func(float f) { return f + 10.0f; }
double func(double d) { return d + 10.0; }

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