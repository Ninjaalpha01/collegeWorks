#include <stdio.h>

/*
p = pessoas entrevistadas,
id = idade,
op = opini�o sobre o filme,
ro = pessoas que responderam �timo,
rb = pessoas que responderam bom,
rre = pessoas que responderam regular,
rru = pessoas que responderam ruim,
rp = pessoas que responderam p�ssimo,
pbo = percentual que respondeu bom,
pre = percentual que respondeu regular,
dp = diferen�a de percentual entre respostas bom e ruim,
mdi_ru = m�dia de idade de pessoas que respnderam ruim,
pp = porcentagem de respostas p�ssimo,
mipe = maior idade de que utilizou a op��o p�ssimo,
miot = maior idade de quem respondeu �timo,
miru = maior idade de quem respondeu ruim,
som_id = soma da idade de quem respondeu ruim,
di = difeeren�a de idade entre os dois acima.
*/

int main()
{
	int p, id, op, ro, rb, rre, rru, rp, mipe, miot, miru, som_id, di;
	float pbo, pre, dp, pp, mdi_ru;
	
	p = 1;
	ro = 0;
	rb = 0;
	rre = 0;
	rru = 0;
	rp = 0;
	mipe = 0;
	miot = 0;
	miru = 0;
	som_id = 0;
	
	do
	{
	ID:
		printf("Insira sua idade: ");
		scanf("%d", &id);
		if (id > 0)
		{
		OP:
			printf("Insira sua opiniao (5-otimo 4-bom 3-regular 2-ruim 1-pessimo): \n");
			scanf("%d", &op);
			
			switch (op)
			{
				case 5:
					{
						ro++;
						if (id > miot)
							miot = id;
					} break;
				case 4:
					{
						rb++;
					} break;
				case 3:
					{
						rre++;
					} break;
				case 2:
					{
						rru++;
						som_id = som_id+id;
						if (id > miru)
							miru = id;
					} break;
				case 1:
					{
						rp++;
						if (id > mipe)
							mipe = id;
					} break;
				default:
					{
						printf("Tente novamente\n");
						goto OP; //testar at� que op seja v�lida
					} break;
			}
		}
		else
			{
				printf("Tente novamente\n");
				goto ID; //testar at� que id seja v�lida
			}
			
		p++;
	} while (p <= 9);
	
	p--;
	pbo = (float)rb/p*100;
	pre = (float)rre/p*100;
	dp = pbo-pre;
	mdi_ru = (float)som_id/rru;
	pp = (float)rp/p*100;
	di = miot-miru;
	
	printf("Quantidade de respostas otimo: %d\n\n", ro);
	
	printf("Diferenca de percentual entre respostas bom e regular:\n");
	if (dp > 0)
		printf("Bom foi mais avaliado em %.2f%%\n\n", dp);
	else
		if (dp < 0)
			printf("Regular fou mais avaliado em: %.2f%%\n\n", -dp);
		else
			printf("Nao ha diferenca de percentual\n\n");
	
	if (mdi_ru > 0)
		printf("Media de idade das pessoas que responderam ruim: %.1f anos\n\n", mdi_ru);
	else
		printf("Ninguem selecionou a opcao ruim\n\n");
	
	printf("Percentagem de respostas pessimo: %.2f%%\n", pp);
	printf("Maior idade que utilizou esta opcao: %d anos\n\n", mipe);
	
	printf("Difernca entre a maior idade que respondeu otimo e que respondeu ruim:\n");
	if (di > 0)
		printf("%d anos", di);
	else
		if (di < 0)
			printf("%d anos", -di);
		else
			printf("Nao ha diferenca de idades");
}
