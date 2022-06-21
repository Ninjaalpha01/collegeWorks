#include <stdio.h>

int main()
{
	int num, som;
	
	som = 0;
	num = 100;
	
	printf("Multiplos de 7 entre 100 e 200:\n");
	
	for(; num>=100 && num<=200; num++)
		if (num%7 == 0)
		{
			som = som+num;
			printf("%d\t", num);
		}
	printf("\nSoma igual a: %d", som);
}

