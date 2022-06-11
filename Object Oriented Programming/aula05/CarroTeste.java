package aula05;

import java.util.Scanner;

public class CarroTeste {

	public static void main(String[] args) {
		
		Scanner entradaTeclado = new Scanner(System.in);
		
		Carro carro1 = new Carro();
		Carro carro2 = new Carro();
		
		carro1.modelo = "Civic";
		carro1.marca = "Honda";
		carro1.ano = 2022;
		carro1.placa = "ABC-1234";
		carro1.cor = "Azul";
		
		carro2.modelo = "Ka";
		carro2.marca = "Ford";
		carro2.ano = 2019;
		carro2.placa = "DEG-0923";
		carro2.cor = "Prata";
		
		System.out.println(carro1);
		
		System.out.println("CARRO 1");
		carro1.imprimirDados();
		
		System.out.println("================");
		
		System.out.println(carro2);
		
		System.out.println("CARRO 2");
		carro2.imprimirDados();
		
		System.out.println("================");
		
		carro1.desligar();
		carro1.ligar();
		System.out.println("Quanto quer acelerar? ");
		carro1.acelerar(entradaTeclado.nextInt());
		carro1.desligar();
		carro1.frear(3);
		carro1.frear(7);
		carro1.frear(5);
		carro1.frear(10);
		carro1.desligar();
		
		entradaTeclado.close();
	}
}