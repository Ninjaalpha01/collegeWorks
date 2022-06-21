#include <stdio.h>

/*
t = divisor,
x = valor fornecido pelo usu�rio,
y = valor fornecido pelo usu�rio,
z = valor fornecido pelo usu�rio,
mdc = m�ximo divisor comum.
*/

int main()
{
	int t, x, y, z, mdc;
	
In:
	printf("Insira os tres valores:\n"); 
	scanf("%d%d%d", &x, &y, &z);
	
	t = 2;
	mdc = 1; //m�nimo valor do mdc, j� que todos os numeros s�o divis�veis por 1
	
	if (x > 0 && y > 0 && z > 0)
	{
		do
		{ //repetir at� que n�o haja mais termos divisores poss�veis
			do
			{ //repetir at� que o resto das divis�es pelo mesmo termo seja != 0
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
