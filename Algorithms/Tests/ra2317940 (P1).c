#include <stdio.h>

/*
t = divisor,
x = valor fornecido pelo usuário,
y = valor fornecido pelo usuário,
z = valor fornecido pelo usuário,
mdc = máximo divisor comum.
*/

int main()
{
	int t, x, y, z, mdc;
	
In:
	printf("Insira os tres valores:\n"); 
	scanf("%d%d%d", &x, &y, &z);
	
	t = 2;
	mdc = 1; //mínimo valor do mdc, já que todos os numeros são divisíveis por 1
	
	if (x > 0 && y > 0 && z > 0)
	{
		do
		{ //repetir até que não haja mais termos divisores possíveis
			do
			{ //repetir até que o resto das divisões pelo mesmo termo seja != 0
				if(x % t == 0 && y % t == 0 && z % t == 0)
				{
					x = x/t;
					y = y/t;
					z = z/t;
					
					mdc = mdc*t;
				}
				else
				{
					if (x % t != 0 && y % t == 0 && z % t == 0)
					{
						y = y/t;
						z = z/t;
					}
					else
					{
						if (x % t == 0 && y % t != 0 && z % t == 0)
						{
							x = x/t;
							z = z/t;
						}
						else
						{
							if(x % t == 0 && y % t == 0 && z % t != 0)
							{
								x = x/t;
								y = y/t;
							}
							else
							{
								if(x % t != 0 && y % t != 0 && z % t == 0)
									z = z/t;
								else
								{
									if(x % t != 0 && y % t == 0 && z % t != 0)
										y = y/t;
									else
										if(x % t == 0 && y % t != 0 && z % t != 0)
											x = x/t;
								}
							}
						}
					}
				}
				printf("t = %d, mdc = %d\n", t, mdc);
			} while (x % t == 0 || y % t == 0 || z % t == 0);
			
			if (t == 2)
				t++;
			else
				t = t+2;
				
		} while (x != 1 || y != 1 || z != 1);
		printf("mdc = %d", mdc);
	}
	else
	{
		printf("Valor Invalido.\n");
		goto In; //resetar a escolha
	}
}
