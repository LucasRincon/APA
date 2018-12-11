#include <stdio.h>

void selection_sort(int array[],int length) {
  int i, j, min, aux;

  for (i = 0; i < (length - 1); i++) {              /* O min é o primeiro numero não ordenado ainda */
    min = i;
    for (j = i+1; j < length; j++) {                /* Caso tenha algum numero menor ele faz a troca do min*/
      if (array[j] < array[min]) {
   min = j;
      }
    }
    if (i != min) {                                 /* Se o min for diferente do primeiro numero não ordenado ele faz a troca para ordena-los*/
      aux = array[i];
      array[i] = array[min];
      array[min] = aux;
    }
  }
    printf("Array ordenado: ");                     /* Imprime o array ordenado */
  for (i = 0; i < length; i++) {
    printf ("\n\t\t%d ",array[i]);
  }
  printf ("\n");
}

int main () {
  int length, i;                                    /* Lê o tamanho do array*/
  printf("Insira o tamanho do array: ");
  scanf ("%d",&length);

  int  array[length];                               /* Lê os elementos do array */
  printf("Insira os elementos do array\n");
  for (i = 0; i < length; i++) {
    printf("Insira o %d elemento: ",i+1);
    scanf ("%d",&array[i]);
  }

  selection_sort (array, length);
  return 0;
}
