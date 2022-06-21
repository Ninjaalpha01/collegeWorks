#include <stdio.h>

int main()
{
	float alt, med, maior, menor, saf = 0;
	char sex;
	int i, m = 0, f = 0;
	
	for (i=0; i<=50; i++)
	{
	ALT:
		printf("Insira sua altura: ");
		scanf("%f", &alt);
		for (; i==0; i++)
			menor = alt;

		if(alt >= 0)
			{
			SEX:
				fflush(stdin);
				printf("Insira seu sexo (m/f): ");
				scanf("%c", &sex);
		
				if (alt <= menor)
					menor = alt;
				else
					if (alt >= maior)
						maior = alt;
				
				switch (sex)
				{
					case 'M':
					case 'm':
						m++;
						break;
					case 'F':
					case 'f':
						{
							saf = saf+alt;
							f++;
						} break;
					default:
						{
							printf("Tente novamente\n");
							goto SEX;
							break;
						}
				}
			}
			
		else
			{
				printf("Tente novamente\n");
				goto ALT;
			}
	}
	med = (float)saf/f;
	
	printf("\nA maior e a menor altura do grupo:\n%.2f\t%.2f\n", maior, menor);
	printf("A media de altura das mulheres: %.2f\n", med);
	printf("O numero de homens: %d", m);
}
