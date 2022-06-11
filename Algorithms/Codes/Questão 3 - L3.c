#include <stdio.h>

int main ()
{
	int cod;
	float qnt, vt;
	
	printf("Insira o codigo do produto: ");
	scanf("%d", &cod);
	printf("Insira a quantidade: ");
	scanf("%f", &qnt);
	
	switch (cod)
	{
		case 1001:
			{
				vt = 5.32*qnt;
				printf("Valor a pagar: R$%.2f", vt);
			}
			break;
		case 1324:
			{
				vt = 6.45*qnt;
				printf("Valor a pagar: R$%.2f", vt);
			}
			break;
		case 6548:
			{
				vt = 2.37*qnt;
				printf("Valor a pagar: R$%.2f", vt);
			}
			break;
		case 987:
			{
				vt = 5.32*qnt;
				printf("Valor a pagar: R$%.2f", vt);
			}
			break;
		case 7623:
			{
				vt = 6.45*qnt;
				printf("Valor a pagar: R$%.2f", vt);
			}
			break;
		default:
			printf("Erro: codigo invalido");
	}
}
