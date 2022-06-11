#include <stdio.h>

int main()
{
	int c=1, i, n, opc;
	
	do
	{
		printf("Insira uma opcao:\n");
		printf("1 - Media de cada conjunto \n2 - Quit\n");
		scanf("%d", &opc);
		system("cls");
		
		switch (opc)
		{
			case 1:
				{
					printf("Inira o tamanho dos conjuntos: ");
					scanf("%d", &n);
					
					int vet1[n], vet2[n], vet3[n];
					float vetm[n];
					
					printf("Insira os valores do 1 conjunto:\n");
					for (i=0; i < n; i++)
						scanf("%d", &vet1[i]);
						
					printf("Insira os valores do 2 conjunto:\n");
					for (i=0; i < n; i++)
						scanf("%d", &vet2[i]);
						
					printf("Insira os valores do 3 conjunto:\n");
					for (i=0; i < n; i++)
						scanf("%d", &vet3[i]);
					
					for (i=0; i < n; i++)
					{
						vetm[i] = vet1[i]+vet2[i]+vet3[i];
						vetm[i] /= 3.0;
					}
					
					
					printf("Vetor de media:\n");				
					for(i=0; i < n; i++)
						printf("Vet[%d]: %f\n", i, vetm[i]);
					
					system("pause");
					system("cls");
				}
				break;
			
			case 2:
				{
					printf("Ate mais!\n");
					c = 0;
				}
				break;
				
			default:
				printf("Opcao invalida. Tente novamente\n");
		}
	} while (c == 1);
	
	return 0;
}
