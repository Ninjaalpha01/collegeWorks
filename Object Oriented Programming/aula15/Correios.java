package aula15;

public class Correios implements Frete {
	@Override
	public double calcularFrete(Integer distancia) {
		
		return 10.00 + (distancia * 0.35);
	}
}
