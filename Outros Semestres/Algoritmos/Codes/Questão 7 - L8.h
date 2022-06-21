#include <stdio.h>

int hora(int seg)
{
	int h;
	h = seg/3600;
	return h;
}

int minuto(int res)
{
	int h, m, s, r;
	
	h = hora(res);
	r = res-(h*3600);
	m = r/60;
	
	return m;
}

int segundo(int res)
{
	int h, m, r, s;
	
	h = hora(res);
	r = res-(h*3600);
	m = minuto(res);
	r = r-(m*60);
	s = r;
	
	return s;
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
			printf("Ate mais!\n");
			break;
				
		default:
			printf("Opcao invalida.\n"); goto RESET;
			break;
	}
}
