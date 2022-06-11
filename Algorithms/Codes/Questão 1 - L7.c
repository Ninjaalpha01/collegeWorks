#include <stdio.h>

void obj(float x, float h)
{
	int res;
	h *= 100;
	res = h/x;
	printf("Eh necessario %d degraus para alcancar o objetivo\n\n", res);
}

void main()
{
	float a, b, i = 1;
	char opc;
	
	do
	{
		printf("Insira a altura de um degrau em cm: ");
		scanf("%f", &a);
		printf("Insira a altura que quer alcancar em m: ");
		scanf("%f", &b);
		
		if (a > 0 && b > 0 && a <= (b*100))
			obj(a,b);
		else
		{
			printf("Erro. Impossivel calcular.\n");
			i = 1;
		}
	OPC:
		fflush(stdin);	
		printf("Deseja continuar no programa? (s/n)\n");
		scanf("%c", &opc);
		
		switch (opc)
		{
			case 's':
			case 'S':
				{
					printf("\n");
				}
				break;
				
			case 'n':
			case 'N':
				{
					i = 0;
					printf("\nObrigado por usar o algoritmo!\n");
				} break;
				
			default:
				{
					printf("Erro. Resposta invalida\n");
					goto OPC;
				}
				break;
		}
	} while (i == 1);
}
