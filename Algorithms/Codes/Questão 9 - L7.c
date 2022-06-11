#include <stdio.h>

int tf(int h, int m); //verifica se o horário digitado é válido.
int hora(int h);
int min(int h, int m);
int reset();

int main()
{
	int x, hr, minu, total;
	
	do
	{
		fflush(stdin);
		printf("Insira o horario (00:00h): ");
		scanf("%d:%d", &hr, &minu);
		
		x = tf(hr,minu);
		
		if(x == 1)
		{
			hr = hora(hr);
			total = min(hr,minu);
			printf("Ja se passaram %d minutos\n\n", total);
		}
	} while (reset() == 1);
	
	return 0;
}

int tf(int h, int m)
{
	int x=0;
	if (h >= 0 && h < 24 && m >= 0 && m < 60)
		{
			return x=1;
		}
	else
		printf("erro\n\n"); return x;
}

int hora(int h)
{
	int min;
	min = h*60;
	return min;
}

int min(int h, int m)
{
	int total;
	total = h+m;
	return total;
}

int reset()
{
	int res;
RESET:
	fflush(stdin);
	printf("\nDeseja refazer o processo? (s/n)\n");
	scanf("%c", &res);
	
	switch (res)
	{
		case 's':
		case 'S':
			return res=1;
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
