#include <stdio.h>
#include <stdlib.h>

void main()
{
	float vet[10];
	float *v;
	int i;
	
	v = vet;
	
	for (i=0; i<10; i++)
		printf("%x\n", v+i);
}
