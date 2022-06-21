package aula14;

import java.util.Scanner;

public class FuncionarioTeste {

	public static void main(String[] args) {
		
		Funcionario f1 = null;
		Scanner input = new Scanner(System.in);
		String nome = "José";
		long cpf = 4325930;
		Double salarioBase = 2500.0;
		
		System.out.println("1 - Assalariado \n2 - Comissionado \n3 - Horista");
		System.out.print("Insira: ");
		Integer opc = input.nextInt();
		
		switch (opc)
		{
			case 1:
				f1 = new Assalariado(nome, cpf, salarioBase, 500.0);
				break;
			
			case 2:
				f1 = new Comissionado(nome, cpf, salarioBase, 5.0, 10.0);
				break;
			
			case 3:
				f1 = new Horista(nome, cpf, salarioBase, 15.0, 160);
				break;
			
			default:
				break;
		}
		
		System.out.printf("Salário de %s: R$%.2f\n", f1.getNome(), f1.calcularSalario());
	}
}
