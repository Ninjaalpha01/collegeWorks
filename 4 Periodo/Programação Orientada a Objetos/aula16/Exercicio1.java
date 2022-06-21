package aula16;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Exercicio1 {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		List<Integer> lista = new ArrayList<Integer>();
		Integer x, soma = 0;
		Double media;

		System.out.println("Insira 5 valores");
		
		for (int i = 0; i < 5; i++) 
		{
			x = input.nextInt();
			lista.add(x);
		}
		
		input.close();
		
		for (int i = 0; i < lista.size(); i++)
			soma += lista.get(i);
		
		media = (double) (soma/lista.size());
		
		System.out.println("Soma dos valores: " + soma);
		System.out.println("Média aritmética: " + media);
	}
}
