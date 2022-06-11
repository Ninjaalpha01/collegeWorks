#include<stdio.h>

void BubbleSort(int v[], int ini, int fim)
{
	int i,j,aux;
	
	for(i=ini; i<fim-1; i++)
	{
		
		for(j=0; j<fim-1; j++)
		{
			if(v[j] > v[j+1] )
			{
				//troque v[j] com v[j+1];
				aux=v[j+1];
				v[j+1] = v[j];
				v[j]=aux;
			}	
		}
	}

}

int main()
{
	int i, v[10]={9,8,7,6,5,4,3,2,1,0};
	BubbleSort(v, 0, 10);
	for(i=0;i<10;i++)
	   printf("\n%d", v[i]);
}

