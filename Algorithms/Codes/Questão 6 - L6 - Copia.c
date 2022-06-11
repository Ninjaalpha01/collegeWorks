#include <stdio.h>

/*
i = numero de funcionarios,
f = numero de filhos,
ssal = soma dos salarios,
sf = soma de filhos,
ps = soma de pessoas com salario até 300$ e tem filhos,
sal = salraio,
meds = media salarial,
medf = media de filhos,
pps = percentual de pessoas com salario até 300$ e com filhos.
*/

int main()
{
	int i, f, ssal, sf, ps;
	float sal, meds, medf, pps;
	
	ssal = 0;
	sf = 0;
	
	for (i=0; i<2; i++)
	{
	SAL:
		printf("Insira seu salario: R$");
		scanf("%f", &sal);
		
		if (sal > 0)
		{
		F:
			printf("Insira quantos filhos voce tem: ");
			scanf("%i", &f);
			
			if (f >= 0)
			{
				ssal = ssal+sal;
				sf = sf+f;
				
				if (f > 0 && sal < 300)
					ps++;
			}
			else
			{
				printf("Erro. Tente novamente\n");
				goto F;
			}
		}
		else
		{
			printf("Erro. Tente novamente\n");
			goto SAL;
		}
	}
	meds = (float)ssal/i;
	medf = (float)sf/i;
	pps = (float)ps/i;
	
	printf("Media salarial dos funcionarios: R$%.2f\n", meds);
	printf("Media do numero de filhos por funcionario: %.1f\n", medf);
	printf("Percentual de pessoas com salario ate R$300,00 que tem filhos: %.1f ou seja %.2f%%\n", pps, pps*100);
}
