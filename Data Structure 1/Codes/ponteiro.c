#include <stdio.h>

int main()
{
	float a=2.0, *b=NULL;
	float *p=&a;
	
	*p = 5.0;
	b = p;
	
	printf("%f\n", *b);
}
