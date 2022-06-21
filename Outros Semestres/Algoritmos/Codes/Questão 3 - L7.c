#include <stdio.h>

char res;
int opc;

void conrd(float x)
{
	//real -> dolar
	fflush(stdin);
	float real, dolar;

VALOR:
	printf("Insira o valor em reais: \nR$");
	scanf("%f", &real);
	
	if (real > 0)
	{
		dolar = real/x;
		printf("Conversao: U$%.2f\n\n", dolar);
	}
	else
	{
		printf("Erro. Valor invaldo!\n");
		goto VALOR;
	}
}

void condr(float x)
{
	//dolar -> real
	float dolar, real;

VALOR:
	printf("Insira o valor em dolar: \nU$");
	scanf("%f", &dolar);
	
	if (dolar > 0)
	{
		real = dolar*x;
		printf("Conversao: R$%.2f\n\n", real);
	}
	else
	{
		printf("Erro. Valor invalido!\n");
		goto VALOR;
	}
}

void cotacao(float c)
{
	
	printf("Insira:\n");
	printf("1 - conversao de real para dolar\n");
	printf("2 - conversao de dolar para real\n");
	scanf("%d", &opc);
	
	switch (opc)
	{
		case 1:
			{
				printf("Cotacao do dolar: U$1.00 = R$%.2f\n", c);
				conrd(c);
			} break;
		
		case 2:
			{
				printf("Cotacao do dolar: U$1.00 = R$%.2f\n", c);
				condr(c);
			} break;
			
		default:
			printf("Erro. Opcao invalida!\n");
			break;
	}
}

void reset()
{
RESET:
	fflush(stdin);
	printf("Deseja fazer uma nova conversao? (s/n)\n");
	scanf("%c", &res);
	
	switch (res)
	{
		case 's':
		case 'S':
			res = 1;
			break;
		
		case 'n':
		case 'N':
			printf("Obrigado por usar o algoritmo!\n");
			break;
				
		default:
			printf("Opcao invalida.\n"); goto RESET;
			break;
	}
}

void main()
{
	float cot;
	
	do
	{
		do
		{
		COT:
			fflush(stdin);
			printf("Insira a cotacao dolar/real: ");
			scanf("%f", &cot);
			if(cot > 0)	
			{
				cotacao(cot);
			}
			else
			{
				printf("Erro. Valor invalido!\n");
				goto COT;
			}
		} while (opc != 1 && opc != 2);
		reset();
	} while (res == 1);
}
