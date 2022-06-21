#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void)
{
    unsigned int id;
    char res, con;
    float nt1, nt2, nt3, me, ma;

    printf("Numero de identificacao do aluno: ");
    scanf("%i", &id);
    printf("Nota avaliacao 1: ");
    scanf("%f", &nt1);
    printf("Nota avaliacao 2: ");
    scanf("%f", &nt2);
    printf("Nota avaliacao 3: ");
    scanf("%f", &nt3);
    printf("Media obtida dos exercicios: ");
    scanf("%f", &me);

    ma = (nt1+nt2*2+nt3*3+me)/7;

    if (ma >= 9.0 && ma <= 10.0)
    {
        con = 'A';
        printf("ID aluno: %d\n", id);
        printf("Notas:\nN1\tN2\tN3\n%.1f\t%.1f\t%.1f\n", nt1, nt2, nt3);
        printf("Media dos exercicios: %.1f\n", me);
        printf("Media de aproveitamento: %.1f\n", ma);
        printf("Conceito obtido: %c\n", con);
        printf("Resultado final: APROVADO");
	}
    if (ma < 9.0 && ma >= 7.5)
	{
		con = 'B';
       	printf("ID aluno: %d\n", id);
       	printf("Notas:\nN1\tN2\tN3\n%.1f\t%.1f\t%.1f\n", nt1, nt2, nt3);
       	printf("Media dos exercicios: %.1f\n", me);
       	printf("Media de aproveitamento: %.1f\n", ma);
       	printf("Conceito obtido: %c\n", con);
       	printf("Resultado final: APROVADO");
    }
   	if (ma < 7.5 && ma >= 6.0)
	{
	    con = 'C';
		printf("ID aluno: %d\n", id);
	    printf("Notas:\nN1\tN2\tN3\n%.1f\t%.1f\t%.1f\n", nt1, nt2, nt3);
	    printf("Media dos exercicios: %.1f\n", me);
	    printf("Media de aproveitamento: %.1f\n", ma);
	    printf("Conceito obtido: %c\n", con);
	    printf("Resultado final: APROVADO");
	}
	if (ma >= 4.0 && ma < 6.0)
	{
	    con = 'D';
	    printf("ID aluno: %d\n", id);
	    printf("Notas:\nN1\tN2\tN3\n%.1f\t%.1f\t%.1f\n", nt1, nt2, nt3);
	    printf("Media dos exercicios: %.1f\n", me);
	    printf("Media de aproveitamento: %.1f\n", ma);
	    printf("Conceito obtido: %c\n", con);
	    printf("Resultado final: REPROVADO");
	}
	if (ma < 4.0 && ma >= 0)
	{
	con = 'E';
	printf("ID aluno: %d\n", id);
	printf("Notas:\nN1\tN2\tN3\n%.1f\t%.1f\t%.1f\n", nt1, nt2, nt3);
	printf("Media dos exercicios: %.1f\n", me);
	printf("Media de aproveitamento: %.1f\n", ma);
	printf("Conceito obtido: %c\n", con);
	printf("Resultado final: REPROVADO");
	}
	  
    return 0;
}
