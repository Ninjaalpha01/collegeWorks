#include <stdio.h>
#include <math.h>

int main()
{
	char nome[15], sex;
	float peso, alt, imc, po, ppn;
	int id, f, o, pn;
	
	o = 0;
	pn = 0;
	
	for (f=0; f<4; f++)
	{
		printf("\nInsira seu nome: ");
		scanf("%s", nome);
	SEX:
		fflush(stdin);
		printf("Informe seu sexo (f/m): ");
		scanf("%c", &sex);
		
		if (sex == 'M' || sex == 'm' || sex == 'F' || sex == 'f')
		{
		PESO:
			printf("Insira seu peso (em kg): ");
			scanf("%f", &peso);
			
			if (peso > 0)
			{
			ALT:
				printf("Insira sua altura (em metros): ");
				scanf("%f", &alt);
				
				if (alt > 0)
				{
				ID:
					printf("Insira sua idade: ");
					scanf("%d", &id);
					
					if (id > 0)
					{
						imc = (float)peso/pow(alt,2);
						
						if (imc >= 30)
							o++;
						else
							if (imc <= 25 && (sex == 'M' || sex == 'm'))
								pn++;
							else
								if (imc <= 27 && (sex == 'F' || sex == 'f'))
								pn++;
					}
					else
					{
						printf("Erro. Tente novamente\n");
						goto ID;
					}
				}
				else
				{
					printf("Erro. Tente novamente\n");
					goto ALT;
				}
			}
			else
			{
				printf("Erro. Tente novamente\n");
				goto PESO;
			}
		}
		else
		{
			printf("Erro. Tente novamente\n");
			goto SEX;
		}
	}
	po = (float)o/f;
	ppn = (float)pn/f;
	
	printf("Percentual de funcionarios obesos: %.2f ou seja %.2f%%\n", po, po*100);
	printf("Percentual de funcionarios com peso normal: %.2f ou seja %.2f%%\n", ppn, ppn*100);
}
