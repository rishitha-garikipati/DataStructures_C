#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int e = arr[n - 1];
  int i = n - 2;
  while (i >= 0 && arr[i] > e) {
    arr[i + 1] = arr[i];
    i--;

    for (int j = 0; j < n; j++) {
      printf("%d ", arr[j]);
    }
    printf("\n");
  }
  arr[i + 1] = e;

  for (int j = 0; j < n; j++) {
    printf("%d ", arr[j]);
  }
  printf("\n");
}

