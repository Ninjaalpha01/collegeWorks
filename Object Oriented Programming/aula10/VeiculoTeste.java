package aula10;

public class VeiculoTeste {

	public static void main(String[] args) {
		
		Carro carro1 = new Carro("Ka", "Ford", 2020, 5, "Flex", 4);
		
		carro1.abastecer();
		carro1.calibrarPneus();
		
		Aviao aviao1 = new Aviao("777", "Boing", 2018, 200, "Combustível de Aviação", 1500);
		
		aviao1.abastecer();
		aviao1.voar();
	}
}
