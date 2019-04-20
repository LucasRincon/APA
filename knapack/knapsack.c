#include <stdio.h>

void GetnM(char * str,  int *nM){

    FILE *f;
    f = fopen(str, "r");

    fscanf(f, "%d %d", &nM[0], &nM[1]);

    fclose(f);

}

void FillTable(char * str,  int *p, int *v, int n){

    FILE *f;
    f = fopen(str, "r");

    fscanf(f, "%d %d", &p[0], &v[0]);

    int i = 0;

    do{
    fscanf(f, "%d %d", &p[i], &v[i]);
    i++;
    }while (i<n);

    fclose(f);

}

int max(int a, int b) { return (a > b)? a : b; }

int knapSack(int M, int peso[], int val[], int n)
{
   int i, p;
   int R[n+1][M+1];

   for (i = 0; i <= n; i++)
   {
       for (p = 0; p <= M; p++)
       {
           if (i==0 || p==0)
                R[i][p] = 0;
           else if (peso[i-1] <= p)
                R[i][p] = max(val[i-1] + R[i-1][p-peso[i-1]],  R[i-1][p]);
           else
                R[i][p] = R[i-1][p];
       }
   }

   return R[n][M];
}

int main(){

    int n, M, nM[2];

    GetnM("mochila01.txt", &nM);
    n = nM[0];
    M = nM[1];

    int p[n], v[n];

    FillTable("mochila01.txt", &p, &v, n);



    printf("n: %d, M: %d\n\n", n, M);

    for(int i=0; i<n; i++)
    printf("p: %d, v: %d\n", p[i], v[i]);

    printf("\nValor maximo na mochila: %d", knapSack(M, p, v, n));

    return 0;

}
