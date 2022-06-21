#include<stdio.h>
void QuickSort(int v[], int ini, int fim)
{
	int i = ini, j = fim, pivo = v[ini],aux;
	while(i <= j)
	{
		while(v[i] < pivo)
		{
			i = i + 1;
		}
		while (v[j] > pivo)
		{
			j = j - 1;
		}
		if (i <= j) 
		{
			//Troca(v[i], v[j]);
		 	aux=v[j];
	     	v[j]=v[i];
	     	v[i]=aux;
			i = i + 1;
			j = j - 1;
		}
	}
	if(ini < j)
		QuickSort(v, ini, j);
	if (i < fim)
		QuickSort(v, i, fim);
}

int main()
{
	int i, v[10]={19,8,67,6,51,4,3,26,1,100}; //v[10]={9,8,7,6,5,4,3,2,1,0};
	QuickSort(v, 0, 9);
	for(i=0;i<10;i++)
	   printf("\n%d", v[i]);
}








