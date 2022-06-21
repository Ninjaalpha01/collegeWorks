#include <stdio.h>
#include <math.h>

int main()
{
	int mul = 100, som = 0;
	
	printf("Os multiplos de 7 entre 100 e 200 sao:\n");
	
	do 
	{
		if ((mul%7) == 0)
		{
			printf("%d\t", mul);
			som = som+mul;
		}
		
		mul++;
	} while (mul >= 100 && mul <= 200);
	printf("\nA soma desses numeros eh igual a: %d", som);
}
