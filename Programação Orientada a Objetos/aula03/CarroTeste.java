package aula03;

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
		
		System.out.println("Informe o modelo do carro 2");
		carro2.modelo = entradaTeclado.nextLine();
		
		System.out.println("Informe a marca do carro 2");	
		carro2.marca = entradaTeclado.nextLine();
		
		System.out.println("Informe o ano do carro 2");
		carro2.ano = entradaTeclado.nextInt();
		
		entradaTeclado.nextLine(); // limpeza buffer
		
		System.out.println("Informe a placa do carro 2");
		carro2.placa = entradaTeclado.nextLine();
		
		System.out.println("Informe a cor do carro 2");
		carro2.cor = entradaTeclado.nextLine();
		
		System.out.println("CARRO 1");
		System.out.println(carro1.modelo);
		System.out.println(carro1.marca);
		System.out.println(carro1.ano);
		System.out.println(carro1.placa);
		System.out.println(carro1.cor);
		
		System.out.println("================");
		
		System.out.println("CARRO 2");
		System.out.println(carro2.modelo);
		System.out.println(carro2.marca);
		System.out.println(carro2.ano);
		System.out.println(carro2.placa);
		System.out.println(carro2.cor);
	}
}