package aula11;

import java.util.Scanner;

public class ImpressoraTeste {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		Impressora printer = null;
		
		System.out.println("Escolha a impressora a ser usada:");
		System.out.println("1 - Laser");
		System.out.println("2 - Jato de Tinta");
		System.out.print("Opção: ");
		
		Integer opc = input.nextInt();
		
		switch (opc) {
			case 1:
				printer = new Laser("HP", "Laser - 1102");
				break;
			
			case 2:
				printer = new JatoDeTinta("HP", "JetWay - 129");
				break;
			
			default:
				System.out.println("Opção inválida.");
		}
		
		printer.imprimir();
		
		input.close();
	}
}
