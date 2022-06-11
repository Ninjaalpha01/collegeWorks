package aula02;

import java.util.Scanner;

public class ExercicioAula02 {

	public static void main(String[] args) {
		
		Scanner entradaTeclado = new Scanner(System.in);
		String nomeCompleto, sexo, estadoCivil, escolaridade;
		int qntdFilhos;
		double rendaMensal;
		
		
		System.out.println("Insira seu nome completo:");
		nomeCompleto = entradaTeclado.nextLine();
		
		System.out.println("Sexo:");
		sexo = entradaTeclado.nextLine();
		
		System.out.println("Estado Civil:");
		estadoCivil = entradaTeclado.nextLine();
		
		System.out.println("Quantidade de filhos:");
		qntdFilhos = entradaTeclado.nextInt();
		
		entradaTeclado.nextLine();
		System.out.println("Escolaridade:");
		escolaridade = entradaTeclado.nextLine();
		
		System.out.println("Renda Mensal:");
		rendaMensal = entradaTeclado.nextDouble();
		
		System.out.println("Nome: " + nomeCompleto);
		System.out.println("Sexo: " + sexo);
		System.out.println("Estado Civil: " + estadoCivil);
		System.out.println("Quantidade de Filhos: " + qntdFilhos);
		System.out.println("Escolaridade: " + escolaridade);
		System.out.printf("Renda: R$%.2f\n", rendaMensal);
	}
}
