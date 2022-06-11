//tiroalvo.c
//usa controle de tela ANSI.SYS
#include <ansi.h>
#define BEEP printf("\x7")
#define SOBE 72
#define DESCE 80

main()
{
	int municao=15, disparos=0, pontos=0, i, j;
	
	LIMPA;
	POS_C(12,26); printf("*** TIRO AO ALVO ***");
	POS_C(15,15);
	printf("UTILIZE AS SETAS PARA MOVIMENTAR O ATIRADOR");
	POS_C(18,21); printf("E QUALQUER OUTRA PARA DISPARAR");
	POS_C(23,20); printf("PRESSIONE <ENTER> PARA CONTINUAR");
	getch(); LIMPA;
	POS_C(24,4); REV; printf("MUNICAO: ");
	POS_C(24,59); printf("DISPAROS: ");
	POS_C(24,59); printf("PONTOS: ");
	NORMAL;
	atualiza(municao, disparos, pontos);
	while (munciao)
	{
		linha_dir();
		i = alvo();
		j = 22; posin(j);
		while (getch()==0)
		{
			switch (getch())
			{
				case SOBE: j = (j<2) ? 22:j-1; break;
				case DESCE: j = (j>21) ? 1:j+1; break;
			}
			posin(j);
		}
		disparos++; municao--;
		dispara(j);
		if (j==i+1)
		{
			bum(i+1);
			pontos++;
			municao = ((pontos%5)==0) ? municao+2:municao;
		}
		apagalvo(i);
		atualiza(municao, disparos, pontos);
	}
	POS_C(10,25); printf("* * * FIM * * *");
	getch();
}

atualiza(m,d,p)
int m,d,p;
{
	REV; PISCA;
	POS_C(24,13); printf(" %02d", m);
	if(!m) BEEP;
	POS_C(24,40); printf(" %03d", d);
	POS_C(24,66); printf(" %03d", p);
	NORMAL;
}

posin(j)
int j;
{
	REV;
	POS_C(j,78); printf("\xDE");
	NORMAL;
}

linha_dir()
{
	int i;
	for (i=1;i<23;i++)
	{
		POS_C(i,78);
		printf("\xDE");
	}
}

alvo()
{
	int i;
	i=rand()%21;
	POS_C(i,l); printf("\xDE");
	POS_C(i+2,1); printf("\xDE");
	return (i);
}

dispara(j)
int j;
{
	int i;
	for(i=76;i>0;i-=2)
	{
		POS_C(j,i); printf("\xDC");
		POS_C(j,i); printf(" ");
	}
}

bum(j)
int j;
{
	int i;
	for (i=0;i<15;i++)
	{
		POS_C(j,i); printf(" BUUUMMM !!!");
		POS_C(j,i); printf("            ");
	}
}

apagalv()
int j;
{
	POS_C(j,1); printf(" ");
	POS_C(j+2,1); printf(" ");
}
