#include <stdint.h>
#include <stdio.h>

#define MY_PI 3.14
#define MY_COUNT 10

char my_data[MY_COUNT] = {'a'};

int main() {
  printf("Some stuff %f %c", MY_PI, my_data[0]);
}