#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void main()
{
    /*vc + valor de contribuição total,
    vc1 = valor de contribuição da pessoa 1,
    vc2 = valor de contribuição da pessoa 2,
    vp = valor total do premio,
    vp1 = valor do premio para a pessoa 1,
    vp2 = valor do premio para a  pessoa 2*/

   float vc, vc1, vc2, vp, vp1, vp2;

   printf("Valor com que o primeiro contribuiu:\n");
   scanf("%f", &vc1);
   printf("Valor com que o segundo contribuiu:\n");
   scanf("%f", &vc2);
   printf("Valor total do premio:\n");
   scanf("%f", &vp);

   vc = vc1+vc2;
   vp1 = vp*(vc1/vc);
   vp2 = vp*(vc2/vc);

   printf("Valor a ser recebido pelo primeiro:\nR$");
   printf("%2.f", vp1);
   printf("\nValor a ser recebido pelo segundo:\nR$");
   printf("%2.f", vp2);
}
