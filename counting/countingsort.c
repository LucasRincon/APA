#include <stdio.h>

int absolute(int value){
      if (value < 0) {
        return -value;
      }
      else {
        return value;  
      }
    }

void counting_sort(int A[], int k, int n, int min){
     int i, j, mod=0;

     int B[n], C[k];
     
     for (i = 0; i < n; i++)
         B[i] = 0;

     for (i = 0; i <= k; i++)
         C[i] = 0;
         
     for (j = 0; j <= n-1; j++)
         C[A[j]] = C[A[j]] + 1;

     for (i = 1; i <= k; i++)
         C[i] = C[i] + C[i-1];

     for (j = n-1; j >= 0; j--){
         B[C[A[j]]-1] = A[j];

         C[A[j]] = C[A[j]] - 1;
        }

        printf("Array ordenado: ");
        for (i = 0; i < n; i++)
            printf("%d ", B[i]);
            printf("\n");
            
     if (min < 0){
	 mod = absolute(min);
	 for (i = 0; i < n; i++){
         B[i] = B[i] - mod;
         }
     }

     printf("Com negativo ordenado: ");
     printArray(B, n);

}

void printArray(int aux[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", aux[i]);
    printf("\n");
}

int main()
{
    int i, k = 0, min = 0, modulo=0;

    int vetor_size;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &vetor_size);

    int vetor[vetor_size];
	printf("\n\t Informe os elementos vetor:");
	for(int i = 0; i < vetor_size;i++){
		printf("\nDigite o %d numero: ",i+1);
		scanf("%d",&vetor[i]);
	}

    printf("Array fornecido: ");
    printArray(vetor, vetor_size);

    for (i=0; i < vetor_size; i++) //menor valor do vetor
    {
	if (vetor[i] < min)
	   min = vetor[i];
    }
    printf("MIN= %d", min);

    if (min < 0){
	   modulo = absolute(min);
	   for (i = 0; i <= vetor_size-1; i++){
         vetor[i] = vetor[i] + modulo;
        }
    }
     printf("Sem negativo: ");
     printArray(vetor, vetor_size);

    for(i=0; i < vetor_size; i++) //maior valor do vetor
    {
        if (vetor[i] > k)
            k = vetor[i];
    }
    
    counting_sort(vetor, k, vetor_size, min);

    return 0;

}
