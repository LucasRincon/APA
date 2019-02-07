#include <stdio.h>
#include <stdlib.h>

void merge(int vetor[], int comeco, int meio, int fim) {

    int parte1 = comeco, parte2 = meio+1, parteAux = 0, tam = fim-comeco+1;
    int *vetAux;

    vetAux = (int*)malloc(tam * sizeof(int));

    while(parte1<=meio && parte2<=fim){

        if(vetor[parte1] <= vetor[parte2]){
            vetAux[parteAux] = vetor[parte1];
            parte1++;
        }else{
            vetAux[parteAux] = vetor[parte2];
            parte2++;
        }
        parteAux++;
    }
    
    while(parte1<=meio){

        vetAux[parteAux] = vetor[parte1];
        parteAux++;parte1++;
    }

    while(parte2<=fim){

        vetAux[parteAux] = vetor[parte2];
        parteAux++;parte2++;
    }

    for(parteAux=comeco;parteAux<=fim;parteAux++){

        vetor[parteAux] = vetAux[parteAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){

    if (comeco < fim) {

        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);

        mergeSort(vetor, meio+1, fim);

        merge(vetor, comeco, meio, fim);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int vetor[] = {21, 30, 17, 7, 2, 3};
    int vetor_size = sizeof(vetor)/sizeof(vetor[0]);
 
    printf("Array fornecido: \n");
    printArray(vetor, vetor_size);
    
    mergeSort(vetor, 0, vetor_size - 1);
 
    printf("\nArray Ordenado: \n");
    printArray(vetor, vetor_size);
    
    return 0;
}
