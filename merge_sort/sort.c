#include <stdio.h>

#define N 10

int A[N] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};


// proc merge(in/out a:array[1..N] of T, in izq,med,der: nat)
// PRE: N >= izq,med,der >=0 y a = A y (a[izq,med] y a(med,der] ordenados)
void merge(int a[N], int izq, int med, int der) {
  int tmp[N];
  int i, j, k;
  for (i = 0; i < der; i++) {
    tmp[i] = a[i];
  }
  j = izq;
  k = med + 1;
  // INVARIANTE: a[izq, i] = intercalacion de tmp[izq, j] con a[med,k]
  for (i = izq; i <= der; i++) {
    if (j <= med && ((k > der) || (tmp[j] <= a[k]))) {
      a[i] = tmp[j];
      j = j + 1;
    }
    else {
      a[i] = a[k];
      k = k + 1;
    }
  }
}
// POS: a permutacion de A y a[izq,der] permutacion ordenada de A[izq,der]


// PRE: N >= der >= izq > 0 y a = A
void merge_sort_rec(int a[N], int izq, int der) {
  int med;
  if (der > izq) {
    med = (der + izq) / 2;    
    merge_sort_rec(a, izq, med);
    merge_sort_rec(a, med + 1, der);
    merge(a, izq, med, der);
  }
}
// POS: a permutacion de A y a[izq,der] permutacion ordenada de A[izq,der]


/* Imprime los valores del arreglo 'a' */
void imprimir (int a[N]) {
  unsigned int i;
  printf("[");
  for (i = 0; i < N; i++) {
    printf(" %d ", a[i]);
  }
  printf("]\n");
}


/* Funcion principal */
int main(void) {
  imprimir(A);
  merge_sort_rec(A, 0, N - 1);
  imprimir(A);
  return 0;
}
