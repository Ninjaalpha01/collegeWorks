#include <stdio.h>

float maior(float vet[], const tam);
int posic(float vet[], const tam, float res);

int main()
{
	const tam = 5;
	int opc, c = 1, i, pos;
	float vet[tam], res;
	
	do
	{
		//system ("cls");
		printf("Escolha uma operacao:\n");
		printf("1 - Encontrar o maior elemento \n2 - Quit\n");
		scanf("%d", &opc);
		//system ("cls");
		
		switch (opc)
		{
			case 1:
				{
					printf("Insira\n");
					
					for (i=0; i < tam; i++)
					{
						printf("%d numero: ", i+1);
						scanf("%f", &vet[i]);
						//system ("cls");
					}
					
					res = maior(vet,tam);
					pos = posic(vet,tam,res);
					
					printf("Maior numero: %f \nPosicao no vetor: %d\n", res, pos);
					c = 1;
					//system ("pause");
				}
				break;
				
			case 2:
				{
					printf("Ate mais!");
					c = 0;
				}
				break;
			
			default:
				printf("Opcao invalida. Tente novamente\n");
		}
	} while (c == 1);
	
	return 0;
}

float maior(float vet[], const tam)
{
	int i;
	float maior = vet[0];
	
	for (i=1; i < tam; i++)
	{
		if (vet[i] > maior)
			maior = vet[i];
	}
	
	return maior;
}

int posic(float vet[], const tam, float res)
{
	int pos=0, i;
	for (i=0; res != vet[i]; i++)
			pos = i+1;
	return pos;
}
