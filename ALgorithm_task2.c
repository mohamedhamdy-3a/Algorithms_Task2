#include <stdio.h>

#include <time.h>
void InsertionSort(int a[], int size) {
  int i;
  clock_t start, end;
  start = clock();
  for (i = 1; i < size; ++i) {
    int CurrentElement = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > CurrentElement) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = CurrentElement;
  }
  end = clock();
  printf("The array is sorted using insertion sort Algorithm in : %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

}
int partition(int a[], int low, int high) {
  int j;
  int pivot = a[high];
  int i = low - 1;
  for (j = low; j < high; ++j) {
    if (a[j] < pivot) {
      i++;
      int temp = a[j];
      a[j] = a[i];
      a[i] = temp;
    }
  }
  int temp = a[high];
  a[high] = a[i + 1];
  a[i + 1] = temp;
  return (i + 1);
}

void QuickSort(int a[], int low, int high) {
  if (low < high) {
    int p = partition(a, low, high);
    QuickSort(a, low, p - 1);
    QuickSort(a, p + 1, high);
  }
}

int main(void) {
  int i;
  srand(time(NULL));
  int a[100000];
  clock_t start, end;
  for (i = 0; i < 100000; ++i) {
    a[i] = rand() % 100000;
  }
  start = clock();
  QuickSort(a, 0, 99999);
  end = clock();
  printf("The array is sorted using Quick sort ALgorithm  in: %f seconds \n", (double)(end - start) / CLOCKS_PER_SEC);
  for (i = 0; i < 100000; ++i) {
    a[i] = rand() % 100000;
  }
  InsertionSort(a, 100000);

}
