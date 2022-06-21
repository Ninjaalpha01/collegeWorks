#include <stdio.h>

int main ()
{
	char ec;
	
	printf("Digite a primeira letra do seu estado civil: ");
	scanf("%c", &ec);
	printf("Estado civil:\n");
	
	switch (ec)
	{
		case 'S':
		case 's': 
			printf("Solteiro");
			break;
		case 'C':
		case 'c':
			printf("Casado");
			break;
		case 'V':
		case 'v':
			printf("Viuvo");
			break;
		case 'D':
		case 'd':
			printf("Divorciado");
			break;
		case 'U':
		case 'u':
			printf("Uniao estavel");
			break;
		default:
			printf("Resposta invalida");
			break;
	}
}
