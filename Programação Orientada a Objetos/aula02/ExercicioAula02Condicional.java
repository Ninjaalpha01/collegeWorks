package aula02;

import java.util.Scanner;

public class ExercicioAula02Condicional {

	public static void main(String[] args) {
		
		Scanner entradaTeclado = new Scanner(System.in);
		int a, b, c;
		
		System.out.println("Insira os tr�s n�meros inteiros");
		a = entradaTeclado.nextInt();
		b = entradaTeclado.nextInt();
		c = entradaTeclado.nextInt();
		
		if (a >= b) {
			if (a >= c) {
				System.out.println(a + " � o maior n�mero");
			}
			else {
				System.out.println(c + " � o maior n�mero");
			}
		}
		else {
			if (b >= c) {
				System.out.println(b + " � o maior n�mero");
			}
			else {
				System.out.println(c + " � o maior n�mero");
			}
		}
	}
}
