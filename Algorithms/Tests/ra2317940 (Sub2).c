#include <stdio.h>

void matriz(int matDistancia[5][5]);
int distancia(int matDistancia[5][5], int a, int b);
int distFinal(int matDistancia[5][5], int vetDistancia[], int n);

int main()
{
	/*
	opc = opção do menu;
	c = indice pra validar se o menu repete ou não;
	i e j = contadores;
	a e b = cidades (questão 2);
	dist = distancia entre duas cidades;
	n = numero de cidades no itinerario;
	df = soma das distancias, distancia final;
	matDistancia = matriz que contem as distancias.
	*/
	
	int opc, c = 1, i, j;
	int a, b, dist, n, df;
	int matDistancia[5][5];
	
	do
	{
		printf("Insira uma opcao:\n");
		printf("1 - Inserir distancia entre cidades\n");
		printf("2 - Distancia entre duas cidades (cod 0 0 para sair)\n");
		printf("3 - Calcular a distancia percorrida\n");
		printf("4 - Sair\n");
		scanf("%d", &opc);
		
		switch (opc)
		{
			case 1:
				{
					matriz(matDistancia);
					system("cls");
					printf("Matriz inserida:\n");
					for (i=0; i < 5; i++)
					{
						for (j=0; j < 5; j++)
						{
							printf("%d\t", matDistancia[i][j]);
						}
						printf("\n");
					}
					system("pause");
					printf("\n");
				}
				break;
			
			case 2:
				{
					do
					{
						do
						{
							printf("Insira as cidades: (A e B)\n");
							scanf("%d %d", &a, &b);
						} while (a < 0 || a > 5 || b < 0 || b > 5);
						
						dist = distancia(matDistancia,a,b);
						if (dist != 0)
							printf("A distancia entre as duas cidades e de: %dkm\n", dist);
						
						system("pause");
						system("cls");
					} while (a != 0 || b != 0);
				}
				break;
			
			case 3:
				{
					do
					{
						printf("Insira o numero de cidades no itinerario:\n");
						scanf("%d", &n);
					} while (n < 1 || n > 4);
					
					int vetCidades[n];
					
					printf("Insira as cidades do itinerario:\n");
					for (i=0; i < n; i++)
						scanf("%d", &vetCidades[i]);
					
					df = distFinal(matDistancia,vetCidades,n);
					
					printf("= %d\n", df);
					system("pause");
					system("cls");
				}
				break;
			
			case 4:
				{
					c = 0;
					system("cls");
					printf("Ate mais!");
				}
				break;
			
			default:
				{
					printf("Erro. Tente novamente\n");
					c = 1;
				}
		}
	} while (c == 1);
	
	return 0;
}

void matriz(int matDistancia[5][5])
{
	int i, j;
	
	//preenchendo a matriz
	printf("Insira as distancias entre as cidades:\n");
	for (i=0; i < 5; i++)
		for (j=0; j < 5; j++)
		{
			printf("%d e %d: ", i, j);
			scanf("%d", &matDistancia[i][j]);
		}
}

int distancia(int matDistancia[5][5], int a, int b)
{
	int res;
	
	//calculando a distancia e validando os valores obtidos
	if ((a == 0 || b == 0) && (a != 0 || b != 0))
		{
			printf("Nao existe cidade 0\n");
			return 0;
		}
	else
		return matDistancia[a-1][b-1];
}

int distFinal(int matDistancia[5][5], int vetCidades[], int n)
{
	int i, soma = 0;
	int vetDistancia[n-1];
	
	//zerando todos os valores de vetDistancia pois não consegui zerar na declaração
	for (i=0; i < (n-1); i++)
		vetDistancia[i] = 0;
	
	//atribuindo as distancias entre cada duas cidades no vetor
	for (i=0; i < (n-1); i++)
	{
		vetDistancia[i] += matDistancia[vetCidades[i]-1][vetCidades[i+1]-1];
		printf("Cidade %d para Cidade %d = %d\n", vetCidades[i], vetCidades[i+1], vetDistancia[i]);
	}
	
	//somando as distancias
	for (i=0; i < (n-1); i++)
		soma += vetDistancia[i];
	
	printf("Distancia final seria: ");
	for (i=0; i < (n-1); i++)
		printf("+ %d ", vetDistancia[i]);
	
	return soma;
}
