package aula15;

public class IOF implements TipoImposto {

	@Override
	public Double calcularImposto(Double mercadoria) {

		return mercadoria * 0.06;
	}
}
