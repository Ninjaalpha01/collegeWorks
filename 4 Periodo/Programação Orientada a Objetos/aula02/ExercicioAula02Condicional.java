package aula02;

import java.util.Scanner;

public class ExercicioAula02Condicional {

	public static void main(String[] args) {
		
		Scanner entradaTeclado = new Scanner(System.in);
		int a, b, c;
		
		System.out.println("Insira os três números inteiros");
		a = entradaTeclado.nextInt();
		b = entradaTeclado.nextInt();
		c = entradaTeclado.nextInt();
		
		if (a >= b) {
			if (a >= c) {
				System.out.println(a + " é o maior número");
			}
			else {
				System.out.println(c + " é o maior número");
			}
		}
		else {
			if (b >= c) {
				System.out.println(b + " é o maior número");
			}
			else {
				System.out.println(c + " é o maior número");
			}
		}
	}
}
