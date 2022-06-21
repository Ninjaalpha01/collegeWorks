
#include<stdio.h>

int BuscaPosMenor(int v[], int ini, int fim)
{
	int i, menor=v[ini], pmenor=ini;
	for(i=ini; i<fim; i++)
	{
		if(v[i] < menor)
		{
			menor=v[i];
			pmenor=i;
		}
	}
	return pmenor;
}

void SelectionSort(int v[], int ini, int fim)
{
	int i, menor,aux;
	for(i=ini; i<fim; i++)
	{
		menor = BuscaPosMenor(v, i, fim);
		//Troca(v[i], v[menor]);
		aux=v[menor];
		v[menor] = v[i];
		v[i] = aux;
	}
}
int main()
{
	int i, v[10]={9,8,7,6,5,4,3,2,1,0};
	SelectionSort(v, 0, 10);
	//printf("\n%d", v[0]);
	for(i=0;i<10;i++)
	   printf("%d\n", v[i]);
}




