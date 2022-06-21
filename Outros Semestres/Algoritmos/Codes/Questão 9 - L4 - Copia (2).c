#include <stdio.h>
#include <math.h>

int main()
{
	/*
	funcionarios: fun,
	filhos: fil,
	salario: sal,
	soma de salario: ss,
	soma de filhos: sf,
	media salarial: msa,
	media de filhos: mfi,
	soma para a porcentagem: sp,
	porcentagem: p.
	*/
	
	int fun, fil, sf, mfi, sp, n;
	float sal, ss, msa, p;
	
	printf("Insira fun: ");
	scanf ("%d", &n);
	
	fun = 1;
	msa = 0;
	mfi = 0;
	ss = 0;
	sp = 0;
	
	while (fun <= n)
	{
		printf("Insira seu salario: R$");
		scanf("%f", &sal);
		printf("Insira o numero de filhos: ");
		scanf("%d", &fil);
		
		ss = ss+sal;
		sf = sf+fil;
		
		if (sal <= 300 && fil > 0)
		{
			sp++;
		}
		
		fun++;
	}
	fun--;
	msa = (ss*1.0)/fun;
	mfi = sf/fun;
	
	printf("%d\n", fil);
	
	p = ((float)sp/fun)*100;
	
	printf("Media salarial: R$%.2f\n", msa);
	printf("Media de filhos: %d\n", mfi);
	printf("Percentual (%%): %.0f", p);
}
