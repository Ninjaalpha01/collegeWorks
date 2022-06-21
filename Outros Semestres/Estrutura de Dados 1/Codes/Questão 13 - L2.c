#include <stdio.h>

void inverter_valores(int *pb, int *pa);

void main ()
{
	int a, b;
	
	printf("Insira dois valores inteiros:\n");
	scanf("%d %d", &a, &b);
	
	inverter_valores(&a,&b);
	
	printf("PA: %d, PB: %d", a, b);
}

void inverter_valores(int *pa, int *pb)
{
	int buf;
	buf = *pa;
	*pa = *pb;
	*pb = buf;
}
