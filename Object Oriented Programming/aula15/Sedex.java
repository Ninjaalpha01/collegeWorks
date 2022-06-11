package aula15;

public class Sedex implements Frete {
	@Override
	public double calcularFrete(Integer distancia) {
		return 15.0 + (distancia * 0.50);
	}
}
