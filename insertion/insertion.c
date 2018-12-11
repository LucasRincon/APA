#include <stdio.h>

void InsertionSort(int array[], int length) {
	int i, j, aux;
	for (i = 1; i < length; i++) {
		j = i;
		while (j > 0 && array[j - 1] > array[j]) {
			aux = array[j];
			array[j] = array[j - 1];
			array[j - 1] = aux;
			j--;
		}
	}
}

int main()
{
	int length;
	printf("Digite o tamanho do array: ");
	scanf("%d", &length);

	int array[length];
	printf("\n\t Informe os elementos array:");
	for(int i = 0; i < length;i++){
		printf("\nDigite o %d numero: ",i+1);
		scanf("%d",&array[i]);
	}

	InsertionSort(array,length);
	
	printf("\nArray ordenado: \n");
	for(int i=0; i<length; i++){
		printf("\t%d\n", array[i]);
	}
}
