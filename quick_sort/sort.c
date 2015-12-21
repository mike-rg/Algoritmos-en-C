#include <stdio.h>
#define N 10

int A[N] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};


void swap(int a[N], int i, int j) {
  int tmp;
  tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}


void pivot(int a[N], int izq, int der, int * piv) {
  int i, j;
  *piv = izq;
  i = izq + 1;
  j = der;
  while (i <= j) {
    if (a[i] <= a[*piv]) {
      i = i + 1;
    }
    else if (a[j] > a[*piv]) {
      j = j - 1;
    }
    else if ((a[i] > a[*piv]) && (a[j] <= a[*piv])) {
      swap(a, i, j);
      i = i + 1;
      j = j - 1;
    }
  }
  swap(a, j, *piv);
  *piv = j;
}


void quick_sort_rec(int a[N], int izq, int der) {
  int piv;
  if (der > izq) {
    pivot(a, izq, der, &piv);
    quick_sort_rec(a,izq, piv - 1);
    quick_sort_rec(a, piv + 1, der);
  }
}


void imprimir(int a[N]) {
  int i;
  printf("[");
  for (i = 0; i < N; i++) {
    printf(" %d ", a[i]);
  }
  printf("]\n");
}


int main(void) {
  imprimir(A);
  quick_sort_rec(A, 0, N - 1);
  imprimir(A);
  return 0;
}
