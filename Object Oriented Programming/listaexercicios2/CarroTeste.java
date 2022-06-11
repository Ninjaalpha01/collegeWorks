package listaexercicios2;

public class CarroTeste {

	public static void main(String[] args) {
		
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
		
		carro1.ligar();
		carro1.acelerar();
		carro1.frear();
		carro1.desligar();
	}
}
