package listaexercicios1;


public class CarroTeste {
	
	public static void main(String[] args) {
		
		Carro carro1 = new Carro();
		Carro carro2 = new Carro();
		Carro carro3 = new Carro();
		
		carro1.modelo = "Civic";
		carro1.marca = "Honda";
		carro1.cor = "Preto";
		carro1.ano = 2020;
		carro1.renavam = 9090;
		carro1.chassi = "123908";
		carro1.placa = "IEO-2931";
		
		carro2.modelo = "Celta";
		carro2.marca = "Chevrolet";
		carro2.cor = "Vermelho";
		carro2.ano = 2019;
		carro2.renavam = 3950;
		carro2.chassi = "284104";
		carro2.placa = "XWP-2849";
		
		carro3.modelo = "Ka";
		carro3.marca = "Ford";
		carro3.cor = "Prata";
		carro3.ano = 2018;
		carro3.renavam = 8390;
		carro3.chassi = "132142";
		carro3.placa = "PYM-1741";
		
		System.out.println("Carros:");
		System.out.println("Modelo: " + carro1.modelo);
		System.out.println("Marca: " + carro1.marca);
		System.out.println("Cor: " + carro1.cor);
		System.out.println("Ano: " + carro1.ano);
		System.out.println("Renavam: " + carro1.renavam);
		System.out.println("Chassi: " + carro1.chassi);
		System.out.println("Placa: " + carro1.placa);
		
		System.out.println("==============");
		System.out.println("Modelo: " + carro2.modelo);
		System.out.println("Marca: " + carro2.marca);
		System.out.println("Cor: " + carro2.cor);
		System.out.println("Ano: " + carro2.ano);
		System.out.println("Renavam: " + carro2.renavam);
		System.out.println("Chassi: " + carro2.chassi);
		System.out.println("Placa: " + carro2.placa);
		
		System.out.println("==============");
		System.out.println("Modelo: " + carro3.modelo);
		System.out.println("Marca: " + carro3.marca);
		System.out.println("Cor: " + carro3.cor);
		System.out.println("Ano: " + carro3.ano);
		System.out.println("Renavam: " + carro3.renavam);
		System.out.println("Chassi: " + carro3.chassi);
		System.out.println("Placa: " + carro3.placa);
	}
}
