#include <stdio.h>
#include "biblio.h"

int main()
{
	int i;
	float p, pol, jar, mil;
	
	do
	{
		printf("Insira a medida em pes: ");
		scanf("%f", &p);
		
		if (p > 0)
		{
			pol = pp(p);
			jar = pj(p);
			mil = pm(p);
			
			printf("\n%f pes equivale a:\n", p);
			printf("%f polegadas\n", pol);
			printf("%f jardas\n", jar);
			printf("%f milhas\n", mil);
			
			i = reset();
		}
		else
		{
			printf("Erro. Medida invalida\n");
			i = 0;
		}
	} while (i == 1);
	
	return 0;
}
