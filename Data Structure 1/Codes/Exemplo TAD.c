#include<stdio.h>
typedef struct aluno{
char nome[50];
int ra;
int idade;
}TipoAluno;

struct aluno1 {
int ra;
char idade; //no m?ximo 255 anos.
char nome[20];
short int d;
};


void Insere(TipoAluno *alu);

int main(){
  TipoAluno a1, a2, vetalunos[3];
  struct aluno1 x;
  int i;
/*  for(i=0; i < 3; i++)
  {
  	printf("\nIdade:");
    scanf("%d",&vetalunos[i].idade);
    printf("\nRA:");
    scanf("%d",&vetalunos[i].ra);
    printf("\nNome:");
    scanf("%s",&vetalunos[i].nome);
  }*/
  Insere(&a1);
  printf("\nnome:%s", a1.nome);
  printf("\nRA:%d", a1.ra);  
  printf("\nIdade:%d", a1.idade);
  return 0;
}

void Insere(TipoAluno *paluno)
{
   printf("Informe nome:");
   fgets(paluno->nome,50,stdin);
   printf("Informe ra:");
   scanf("%d",&(paluno->ra));
   printf("Informe idade:");
   scanf("%d",&(paluno->idade));
}
