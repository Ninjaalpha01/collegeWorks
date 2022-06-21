#include <stdio.h>

void adi()
{
	float a, b, adic;
	printf("Insira os valores da operacao:\n");
	scanf("%f %f", &a, &b);
	adic = a+b;
	printf("Soma = %.3f\n", adic);
}

void sub()
{
	float a, b, subt;
	printf("Insira os valores da operacao:\n");
	scanf("%f %f", &a, &b);
	subt = a-b;
	printf("Diferenca = %.3f\n", subt);
}

void mul()
{
	float a, b, mult;
	printf("Insira os valores da operacao:\n");
	scanf("%f %f", &a, &b);
	mult = a*b;
	printf("Produto = %.5f\n", mult);
}

void div()
{
	float a, b, divi;
	printf("Insira os valores da operacao:\n");
	scanf("%f %f", &a, &b);
	divi = a/b;
	printf("Divisao = %.5f\n", divi);
}

void expo()
{
	int a, b;
	long int ex=1;
	printf("Insira os valores da operacao:\n");
	scanf("%d %d", &a, &b);
	for (; b != 0; b--)
		ex = ex*a;
	printf("Exponencial = %ld\n", ex);
}

void main()
{
	char opc;
	int cont = 1;
	
	do
	{
	OPC:	
		fflush(stdin);
		printf("Escolha a operacao: \nA - adicao\nS - subtracao\nM - multiplicacao\nD - divisao\nE - exponenciacao\n");
		scanf("%c", &opc);
		
		switch (opc)
		{
			case 'a':
			case 'A':
				adi();
				break;
			
			case 's':
			case 'S':
				sub();
				break;
			
			case 'm':
			case 'M':
				mul();
				break;
			
			case 'd':
				case 'D':
				div();
				break;
			
			case 'e':
			case 'E':
				expo();
				break;
			
			default:
				printf("Erro.\n"); goto OPC;
				break;
		}
		do
		{
			printf("Quer continuar no programa? (1 - sim / 2 - nao)\n");
			scanf("%i", &cont);
			
			if (cont != 1 && cont != 2)
				printf("Erro.\n");
		} while (cont != 1 && cont != 2);
	} while (cont == 1);
}
