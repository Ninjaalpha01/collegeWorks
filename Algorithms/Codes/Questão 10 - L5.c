#include <stdio.h>

/*
sex = sexo,
opc = gostou ou não do produto,
n = numero de entrevistados,
f = numero de mulheres,
m = numero de homens,
ss = quantidade de pessoas que responderam sim,
sn = quantidade de pessoas que responderam não,
sfs = soma de mulheres que responderam sim,
smn = soma de homens que responderam não,
pfs = porcentagem de mulheres que responderam sim,
pmn = porcentagem de homens que responderam não.
*/

int main()
{
	char sex, opc;
	int n, m, f, ss, sn, sfs, smn;
	float pfs, pmn;
	
	n = 1;
	m = 0;
	f = 0;
	ss = 0;
	sn = 0;
	sfs = 0;
	smn = 0;
	
	do
	{
	SEX:
		fflush(stdin);
		printf("Insira seu sexo (m/f): ");
		scanf("%c", &sex);
		
		switch (sex)
		{
			case 'F':
			case 'f':
				{
				OPC:
					fflush(stdin);
					printf("Gostou do nosso produto (s/n): ");
					scanf("%c", &opc);
					
					switch (opc)
					{
						case 'S':
						case 's':
							{
								ss++;
								f++;
								sfs++;
							} break;
						
						case 'N':
						case 'n':
							{
								sn++;
								f++;
							} break;
						default:
							{
								printf("Opcao invalida, tente novamente\n");
								goto OPC;
							} break;
					}
				} break;
			case 'M':
			case 'm':
				{
					fflush(stdin);
					printf("Gostou do nosso produto (s/n): ");
					scanf("%c", &opc); fflush(stdin);
					
					switch (opc)
					{
						case 'S':
						case 's':
							{
								ss++;
								m++;
							} break;
						
						case 'N':
						case 'n':
							{
								sn++;
								m++;
								smn++;
							} break;
						default:
							printf("Erro\n");
							break;
					}
				} break;
			default:
				{
					printf("Sexo invalido, tente novamente\n");
					goto SEX;
				} break;
		}
		n++;
	} while (n <= 2000);
	
	pfs = (float)sfs/f*100;
	pmn = (float)smn/m*100;
	
	printf("Numero de pessoas que responderam sim: %d\n", ss);
	printf("Numero de pessoas que responderam nao: %d\n", sn);
	
	if (f > 0)
		printf("Porcentagem de mulheres que responderam sim: %.2f%%\n", pfs);
	else
		printf("Porcentagem de mulheres que responderam sim: 0%%\n");
	
	if (m > 0)
		printf("Porcentagem de homens que responderam nao: %.2f%%\n", pmn);
	else
		printf("Porcentagem de homens que responderam nao: 0%%\n");
	
}
