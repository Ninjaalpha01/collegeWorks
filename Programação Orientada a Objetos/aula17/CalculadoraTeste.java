package aula17;

import java.util.InputMismatchException;
import java.util.Scanner;

public class CalculadoraTeste {

	public static void main(String[] args) {
		
		Calculadora calc = new Calculadora();
		Scanner input = new Scanner(System.in);
		
		int x=0, y=0;

		try {
			System.out.print("x: ");
			x = input.nextInt();
			System.out.print("y: ");
			y = input.nextInt();	
		}
		catch (InputMismatchException ime) {
			System.err.println("Entrada de dados inválida.");
		}
		finally {
			Double res;
			
			res = calc.adicao(x, y);
			System.out.println(x + " + " + y + " = " + res);
			
			res = calc.subtracao(x, y);
			System.out.println(x + " - " + y + " = " + res);
			
			res = calc.multiplicacao(x, y);
			System.out.println(x + " * " + y + " = " + res);

			res = calc.divisao(x, y);
			System.out.println(x + " / " + y + " = " + res);
			
			res = calc.potenciacao(x, y);
			System.out.println(x + "^" + y + " = " + res);
			
			res = calc.raizQuadrada(x);
			System.out.println("sqrt(" + x + ")" + " = " + res);
			
			res = calc.inverso(x);
			System.out.println("1 / " + x + " = " + res);
		}
		
		input.close();
	}
}
