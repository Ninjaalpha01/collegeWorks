#include<stdio.h>

void InsertionSort(int v[], int ini, int fim)
{
	int i, aux, j;
	for(i=ini+1; i < fim; i++)//Para i de ini + 1 até fim faça
	{
		aux = v[i];
		j = i - 1;
		while (j >= ini && aux < v[j]) //enquanto
		{
			//troca(v[j+1], v[j]);
			aux=v[j+1];
			v[j+1] = v[j];
			v[j]=aux;
			j = j - 1;	
		}
	}
}

int main()
{
	int i, v[10]={9,8,7,6,5,4,3,2,1,0};
	InsertionSort(v, 0, 10);
	for(i=0;i<10;i++)
	   printf("\n%d", v[i]);
}







