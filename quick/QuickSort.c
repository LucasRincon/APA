#include<stdio.h>

void troca(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int vetor[], int comeco, int fim)
{
    int pivo = vetor[fim];
    int i = (comeco - 1);
    int j;
    
    for (j = comeco; j <= fim - 1; j++){
        
        if (vetor[j] <= pivo){
            i++;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i + 1], &vetor[fim]);
    return (i + 1);
}

void quickSort(int vetor[], int comeco, int fim)
{
    if (comeco < fim)
    {
        int indice = partition(vetor, comeco, fim);
        quickSort(vetor, comeco, indice - 1);
        quickSort(vetor, indice + 1, fim);
    }
}

void printArray(int vetor[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}
 
int main()
{
    int vetor[] = {30, 17, 21, 7, 2, 3};
    int n = sizeof(vetor)/sizeof(vetor[0]);
    printf("Array fornecido: \n");
    printArray(vetor, n);
    
    quickSort(vetor, 0, n-1);
    printf("\nArray ordenado: \n");
    printArray(vetor, n);

    return 0;
}
