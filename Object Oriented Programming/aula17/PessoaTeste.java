package aula17;

import java.util.Scanner;

public class PessoaTeste {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		System.out.println("Insira os dados:");
		
		String nome = input.nextLine();
		input.hasNextLine();
		Integer idade = input.nextInt();
		long cpf = input.nextLong();
		long cep = input.nextLong();
		
		Pessoa p1 = new Pessoa(nome, idade, cpf, cep);
		
		System.out.println(p1.toString());
		input.close();
	}
}
