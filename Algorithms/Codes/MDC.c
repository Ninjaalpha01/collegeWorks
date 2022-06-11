#include <stdio.h>

int main()
{
	int t, x, y, z, mul;
	
	printf("Insira os tres valores:\n");
	scanf("%d%d%d", &x, &y, &z);
	
	t = 2;
	mul = 1;
	
	do
	{
		do
		{
			if(x % t == 0 && y % t == 0 && z % t == 0)
			{
				x = x/t;
				y = y/t;
				z = z/t;
				
				mul = mul*t;
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
								{
									if(x % t == 0 && y % t != 0 && z % t != 0)
										x = x/t;
										
									else
									{
										if(x % t != 0 && y % t != 0 && z % t != 0)
											goto T;
									}
								}
							}
						}
					}
				}
			}
		} while (x % t == 0 || y % t == 0 || z % t == 0);
	T:
		if (t == 2)
			t++;
		else
			t = t+2;
			
	} while (x != 1 || y != 1 || z != 1);
	
	printf("mdc = %d", mul);
}
