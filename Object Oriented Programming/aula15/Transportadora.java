package aula15;

public class Transportadora implements Frete {

	@Override
	public double calcularFrete(Integer distancia) {
		
		return 20.0 + (distancia * 0.65);
	}

}
