#include <stdio.h>
#include <math.h>

int main()
{
	char nome[15];
	int sex;
	
	printf("Digite seu nome: ");
	scanf("%s", nome);
	printf("Qual o seu sexo? (1-masculino/0-feminino)\n");
	scanf("%i", &sex);
	
	if (sex == 1)
		printf("Ilmo Sr.\n%s", nome);
		
	if (sex == 0)
		printf("Ilma Sra.\n%s", nome);
		
	if (sex != 0 && sex != 1)
		printf("Selecao de sexo invalida");
	
	return 0;
}
