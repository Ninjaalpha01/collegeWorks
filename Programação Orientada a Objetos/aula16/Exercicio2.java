package aula16;

import java.util.ArrayList;
import java.util.List;

public class Exercicio2 {

	public static void main(String[] args) {
		
		long inicio = System.currentTimeMillis();
		
		List<Double> lista = new ArrayList<Double>();
		
		for (int i = 0; i < 500000; i++) {
			lista.add(Math.random()*100);
		}
		
		for (int i = 0; i < lista.size(); i++) {
			System.out.println(lista.get(i));
		}
		
		long fim = System.currentTimeMillis();
		long time = fim - inicio;
		
		System.out.println("Tempo gasto: " + time);
	}
}
