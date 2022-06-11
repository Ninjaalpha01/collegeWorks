#include <stdio.h>

void media(float g1[], float g2[], float g3[], int n);

int main()
{
	int n, c=1, i, opc;
	
	do
	{
		printf("Insira uma opcao:\n");
		printf("1 - Calcular a media dos alunos \n2 - Quit\n");
		scanf("%d", &opc);
		system("cls");
		
		switch (opc)
		{
			case 1:
				{
					do
					{	
						system("cls");
						printf("Insira a quantidade de alunos: ");
						scanf("%d", &n);
					} while (n < 0);
					
					float g1[n], g2[n], g3[n];
					
					printf("Insira as notas referentes ao G1:\n");
					for (i=0; i < n; i++)
					{
						printf("Aluno %d: ", i+1);
						scanf("%f", &g1[i]);
					}
					system("pause");
					system("cls");
					printf("Insira as notas referentes ao G2:\n");
					for (i=0; i < n; i++)
					{
						printf("Aluno %d: ", i+1);
						scanf("%f", &g2[i]);
					}
					
					media(g1,g2,g3,n);
					
					for (i=0; i< n; i++)
					printf("Aluno %d:\ng1: %.2f \t g2: %.2f \t media: %.2f\n\n", i+1, g1[i], g2[i], g3[i]);
					system("pause");
					system("cls");
				}
				break;
			
			case 2:
				{
					printf("Ate mais!");
					c = 0;
				}
				break;
			
			default:
				printf("Opcao invalida, tente novamente\n");
		}
		
	} while (c == 1);
	
	return 0;
}

void media(float g1[], float g2[], float g3[], int n)
{
	int i;
	for (i=0; i < n; i++)
	{
		g3[i] = (g1[i]+g2[i])/2;
	}
}
