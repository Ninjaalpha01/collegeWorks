package aula14;

import java.util.Scanner;

public class FormaTeste {

	public static void main(String[] args) {
		
		Double lado = 10.0, altura = 3.0, base = 5.0, raio = 7.5;
		Forma f1 = null;
		Integer opc;
		Scanner input = new Scanner(System.in);
		
		System.out.println("1 - Circulo \n2 - Quadrado \n3 - Retangulo");
		System.out.print("Insira: ");
		
		opc = input.nextInt();
		
		switch (opc)
		{
			case 1:
				f1 = new Circulo("Laranja", raio);
				break;
			
			case 2:
				f1 = new Quadrado("Verde", lado);
				break;
				
			case 3:
				f1 = new Retangulo("Azul", base, altura);
				break;
			
			default:
				break;
		}
		
		System.out.println("Área = " + f1.calcularArea());
		System.out.println("Perímetro = " + f1.calcularPerimetro());
	}
}
