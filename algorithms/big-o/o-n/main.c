#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t i32;

bool findElement(i32 arr[], i32 n, i32 key) {
  for (i32 i = 0; i < n; i++) {
    if (arr[i] == key) {
      return true;
    }
  }
  return false;
}

int main(void) {
  i32 n = 0;
  printf("Insert the size of the dataset that will be inputed: ");
  scanf("%d", &n);

  i32 arr[n];

  for (i32 i = 0; i < n; i++) {
    printf("[%d]: ", i);
    scanf("%d", &arr[i]);
  }

  srand(n);
  i32 key = rand();

  bool result = findElement(arr, n, key);
  printf("%d", result);
  return 0;
}
