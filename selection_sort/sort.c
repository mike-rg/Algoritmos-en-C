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


/* Busca la posicion del minimo elemento del arreglo a[i,N] */
// fun min_pos_from(a:array[0,N], i:nat)
// PRE: 0 < i <= N
int min_pos_from(int a[N], int i) {
   int min = i;
   int j = i + 1;
   // INVARIANTE: 'min' tiene la posicion del elemento minimo
   // del segmento a[i,j] del arreglo 'a' y 'i' es menor que 'N'
   while (j < N) {
       if (a[j] < a[min]) {
           min = j;
       }
       j = j + 1;
   }
   return min;
}
// POS: a[min] es el minimo de a[i,N]


/* Ordenacion por seleccion */
// proc selection_sort(in/out: a:array[0,N] oF T, in: n:nat)
// PRE: N > 0 y a = A
void selection_sort (int a[N], int n) {
    int i, minp;
    i = 0;
    // INVARIANTE: un segmento inicial a[0,i] del arreglo esta
    // ordenado y contiene los elementos minimos del arreglo y
    // 'a' es una permutacion de 'A'.
    while (i < n) {
        minp = min_pos_from(a, i);
        swap(a, i, minp);
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
    selection_sort(A, N);
    imprimir(A);
    return 0;
}
