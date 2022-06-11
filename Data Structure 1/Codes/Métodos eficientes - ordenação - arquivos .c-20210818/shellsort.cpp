#include<stdio.h>
#include<stdlib.h>

void ShellSort(int v[], int ini, int fim)
{
	int h, i, aux, j;
	h = (fim-ini+2)/2;
	while(h > 0 )
	{
		i = h;
		while(i <= (fim-ini+1) )
		{	
			aux = v[i];
			j = i;
			while (j >=h && aux < v[j-h])
			{
				v[j] = v[j-h];
				j = j - h;	
			}
			v[j] = aux;
			i = i + 1;
		}
		h = h/2;
	}
}

int main()
{
	int i, v[10]={19,8,67,6,51,4,3,26,1,100}; //v[10]={9,8,7,6,5,4,3,2,1,0};
	ShellSort(v, 0, 8);
	for(i=0;i<10;i++)
	   printf("\n%d", v[i]);
}


