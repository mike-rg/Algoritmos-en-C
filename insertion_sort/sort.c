#include <stdio.h>

// N tamanio del arreglo 'A'
#define N 10

// A[N] puede ser definida con otros valores
int A[N] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};


/* Intercambia el contenido entre 'i' y 'j' posiciones del arreglo a[0,N] */
// proc swap(in/out a:array of T, in i,j:nat)
// PRE: 0 <= i,j <= N y a = A
void swap(int a[N], int i, int j) {
    int tmp;
    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
// POS: a[i] = A[j] y a[j] = A[i] y para todo k. K no pertenece
// a {i,j} entonces a[k] = A[K]


/* Inserta el j-esimo elemento de 'a' desplazandolo de izquierda a derecha */
// proc insert(in/out a:array[0,N], in i:nat)
// PRE: 0 < i <= N
int insert(int a[N], int i) {
   int j = i;
   // INVARIANTE: a[1'j,i] y a[j,i] estan ordenados y 'a' es permutacion de A
   while (j > 0 && a[j] < a[j - 1]) {
       swap(a, j, j - 1);	
       j = j - 1;
   }
}
// POS: a[0,i] esta ordenado y 'a' es una permutacion de 'A'


/* Ordenacion por insercion */
// proc insertion_sort(in/out: a:array[0,N] oF T, in: n:nat)
// PRE: N > 0 y a = A
void insertion_sort (int a[N], int n) {
    int i, minp;
    i = 1;
    // INVARIANTE: a[1,i) esta ordenado y 'a' es permutacion de A
    while (i < n) {
	insert(a,i);
        i = i + 1;
    }
}
//POST: 'a' esta ordenado y es una permutacion de 'A'


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
    insertion_sort(A, N);
    imprimir(A);
    return 0;
}
