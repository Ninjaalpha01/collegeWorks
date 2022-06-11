package aula02;

import java.util.Scanner;

public class ExercicioAula02Condicional2 {

	public static void main(String[] args) {
		
		Scanner entradaTeclado = new Scanner(System.in);
		double valorTotal, desconto;
		
		System.out.println("Insira o valor total da compra: ");
		valorTotal = entradaTeclado.nextDouble();
		
		desconto = (valorTotal >= 50) ? 0.10*valorTotal : 0.05*valorTotal;
		
		System.out.printf("Desconto: R$%.2f\n", desconto);
	}
}
