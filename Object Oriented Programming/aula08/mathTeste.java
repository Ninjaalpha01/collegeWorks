package aula08;

import java.util.Scanner;

public class mathTeste {

	public static void main(String[] args) {
		
		Scanner entrada = new Scanner(System.in);
		Integer x, y;
		
		System.out.println("Insira x: ");
		x = entrada.nextInt();
		
		System.out.println("Insira y: ");
		y = entrada.nextInt();
		
		Integer maiorValor = Math.max(x,y);
		System.out.println("Maior: " + maiorValor);
		
		Double raiz = Math.sqrt(x);
		System.out.println("Raiz: " + raiz);
		
		Double potenciacao = Math.pow(x, y);
		System.out.println(x + "elevado a " + y + ": " + potenciacao);
		
		entrada.close();
	}
}
