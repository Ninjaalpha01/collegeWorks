#include <stdlib.h>
#include <string.h>
#include "recursividade.c"

int main()
{
	int opc, mul, a, b, tam, x, c=1, n, k, n1, re;
	unsigned int t;
	char  p[30];

	do
	{
		//Comando para apagar as informacoes da tela
		system("cls");
		
		//Menu para a selecao de questoes
		printf("------ MENU ------\n");
		printf("1 - Devolver ab onde a; b E N.\n");
		printf("2 - Faca uma funcao recursiva que receba um numero inteiro positivo N e imprima todos os numeros naturais de 0 ate N em ordem decrescente.\n");
		printf("3 - Dado n E N, imprimir numeros impares que incidem no intervalo [n,0].\n");
		printf("4 - Dado n E N, devolver o produto dos numeros pares que incidem no intervalo [1,n].\n");
		printf("5 - Verifique se uma palavra e palindromo (Ex. aba, abcba, xyzzyx).\n");
		printf("6 - Soma de dois numeros naturais, atraves de incrementos sucessivos (Ex.: 3 + 2 = + + (+ + 3)).\n");
		printf("7 - Devolver o indice i de um dado vetor v com n inteiros tal que v[i]==k ou -1 caso tal indice inexista. k e dado.\n");
		printf("8 - Sair do programa\n");
		fflush(stdin);
		printf("Insira qual questao gostaria de testar: ");
		scanf("%d", &opc);

		switch (opc)
		{
			case 1:
			{
				do
				{
					system("cls");
					//Solicita a entrada das duas variaveis a e b
					printf("Insira o valor de a (positivo): ");
					scanf("%d", &a);
				} while (a < 0);
				do
				{
					printf("Insira o valor de b (positivo): ");
					scanf("%d", &b);
				} while (b < 0);
				
				//Chama a funcao multiplicacao e a retorna na varialvel mul
				mul = multiplicacao(a,b);
				
				//Apresenta o resultado do retorno da funcao
				printf("Resultado: %d\n", mul);
				
				//Comando que solicita que clique em qualquer tecla para prosseguir
				system("pause");
			}
			break;
			
			case 2:
			{
				//solicita a entrada da variavel testando se realmente e positiva
				do
				{
					system("cls");
					printf("Insira um numero inteiro positivo N: ");
					scanf("%d", &n);
				} while (n < 0);

				//printando cada um dos elementos solicitados na tela
				printf("Numeros naturais de N a 0: \n");
				/*chama a funcao decrescente mas nao necessita de nenhum retorno
				para a main, já que serao apenas imprimidos os valores na propria funcao*/
				decrescente(n);
			}
			break;
			
			case 3:
			{
				//solicita a entrada da variavel testando se realmente e positiva
				do
				{
					system("cls");
					printf("Insira um numero positivo N: ");
					scanf("%d", &n);
				} while (n < 0);

				/*chama a funcao impares mas nao necessita de nenhum retorno
				para a main, ja que o vetor e sempre passado por referencia.
				Tambem printa na tela avisando o usuário o resultado*/
				printf("Numeros naturais de impares: \n");

				impares(n);
			}
			break;
			
			case 4:
			{
				
				//solicita a entrada da variavel testando se realmente e positiva
				do
				{
					system("cls");
					printf("Insira um numero positivo N: ");
					scanf("%d", &n);
				} while (n < 0);

				//chama a funcao pares e a retorna na variavel x
				t = pares(n,1);
				//Imprime o resultado da multiplicação
				printf("Multiplicacao dos numeros pares: %u\n", t);
				system("pause");
			}
			break;
			
			case 5:
			{
				system("cls");
				//solicita a entrada da palavra
				printf("Insira uma palavra: ");
				scanf("%s", p+0);
				
				tam = strlen(p);

				//chama a funcao palindromo e a retorna na variavel x
				x = palindromo(p,tam,0);
				//Se a função retornar "1" significa que eh um palindromo
				if (x==1){
					printf("\nEh palindromo\n");
					system("pause");				
				}
				//Se a função retornar "0" significa que nao eh um palindromo
				else{
					printf("\nNao eh palindromo\n");
					system("pause");
				}
			}
			break;
			
			case 6:
			{
				//Solicita a entrada das duas variaveis a e b
				do
				{
					system("cls");
					printf("Informe o primeiro numero (natural) a ser somado: ");
					scanf("%d", &a);
				} while (a < 0);
				do
				{
					system("cls");
					printf("Informe o segundo numero (natural) a ser somado: ");
					scanf("%d", &b);
				} while (b < 0);
				//Retorna a soma das variaveis na variavel x
				x = somanaturais(a,b);
				//Imprime a soma das variaveis
				system("cls");
				printf("\nA soma dos dois numeros eh %d\n", x);
				system("pause");
			}
			break;
			
			case 7:
			{
				int *v = malloc(n1*(sizeof(int*)));
				//Solicita a entrada do tamanho do vetor V[]
				do
				{
					system("cls");
					printf("Informe o tamanho do Vetor: ");
					scanf("%d", &n1);
				} while (n1 < 0);
				//Preenche o Vetor
				int i;
				for(i=0; i<n1; i++){
					system("cls");
					printf("Insira o numero a ser inserido na %d posicao do Vetor ", i+1);
					scanf("%d",v+i);
				}
				//Solicita a entrada do numero "K", para descobrir seu indice
				do
				{
					system("cls");
					printf("Informe o numero do vetor para receber seu indice: ");
					scanf("%d", &k);
				} while (k < 0);
				//Retorna o valor da função para a variavel "re", caso seja -1 "k" nao esta no vetor
				re = devolveindice(v,k,n1);
				//Imprime o indice ou "-1"
				system("cls");
				printf("\nO indice eh %d (Lembrando que o indice comeca de 0 ate n)\n", re);
				system("pause");

			}
			break;
			
			case 8:
			{
				//Aciona o critério de parada do loop "do-while" do men, alterando o valor da
				//variável "c" para 0
				c = 0;
				printf("Ate mais!\n");
			}
			break;
			
			default:
			//Opcao default do "switch-case" caso o usuário insira um valor não suportado
				printf("Opcao invalida. Tente novamente!\n");
		}
	} while (c == 1);

	return 0;
}
