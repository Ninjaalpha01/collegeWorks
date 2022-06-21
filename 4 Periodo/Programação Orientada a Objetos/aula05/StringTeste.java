package aula05;

import java.util.Scanner;

public class StringTeste {
	
	public static void main(String[] args) {
		
		Scanner inTeclado = new Scanner(System.in);
		String teste;
		String teste2;
		String [] subteste;
		int tam;
		int tamSplit;
		int i;
		
		System.out.println("Insira a string: ");
		teste = inTeclado.nextLine();
		
		System.out.println("Caractere posição 3: " + teste.charAt(3));
		tam = teste.length();
		System.out.println("Tamanho: " + tam);
		System.out.println(teste.toLowerCase());
		
		subteste = teste.split(" ");
		tamSplit = 3;
		for (i=0; i<tamSplit; i++)
			System.out.println(subteste[i]);
		
		System.out.println("Insira a segunda string: ");
		teste2 = inTeclado.nextLine();
		
		if (teste.equals(teste2))
			System.out.println("As strings são iguais");
		
		else	
			System.out.println("As strings são diferentes");
		
		inTeclado.close();
	}
}
