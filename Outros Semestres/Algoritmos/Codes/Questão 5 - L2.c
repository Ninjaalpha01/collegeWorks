#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/* renda familiar = ren
renda liquida = rl
percentual de desconto por dependente = dpd
salario minimo = sm
numero de dependentes = nd
valor a se pagar = vp
aliquota = al
*/

int main(void)
{
	char cpf[11];
    int nd;
    float ren, rl, dpd, sm, vp, al;

    printf("Numero do CPF: ");
    scanf("%s", &cpf);
    printf("Numero de dependentes: ");
    scanf("%d", &nd);
    printf("Renda familiar mensal: R$");
    scanf("%f", &ren);
    printf("Salario minimo: R$");
    scanf("%f", &sm);

    dpd = nd*0.05;
    rl = ren/sm;
    al = 0.05;

	printf("CPF: %s\n", cpf);

    if (rl < 2)
    {
        printf("Valor a ser pago do imposto de renda eh de: R$0,00");
	}
	else
	{
	    if (rl >= 2 && rl < 3)
	    {
		    vp = ren*dpd-(ren*al);
	       
		    if (vp < 0)
	        {
	        	vp = vp*(-1);
			}
			printf("Valor a ser pago do imposto de renda eh de: R$");
			printf("%.2f", vp);
		}
		else
		{
			if (rl >= 3 && rl < 5)
			{
		        vp = ren*dpd-(ren*2*al);
		        
				if (vp < 0)
		        {
		        	vp = vp*(-1);
				}
		        printf("Valor a ser pago do imposto de renda eh de: R$");
		        printf("%.2f", vp);
			}
			else
			{
				if (rl >= 5 && rl <= 7)
		    	{
			        vp = ren*dpd-(ren*3*al);
			        
					if (vp < 0)
			        {
			        	vp = vp*(-1);
					}
					printf("Valor a ser pago do imposto de renda eh de: R$");
			        printf("%.2f", vp);
			    }
		        else
				{
			    	if (rl > 7)
			    	{
				        vp = ren*dpd-(ren*4*al);
				        
						if (vp < 0)
				        {
				        	vp = vp*(-1);
						}
						printf("Valor a ser pago do imposto de renda eh de: R$");
				        printf("%.2f", vp);
					}
				}
			}
		}
	}
	    
    return 0;
}
