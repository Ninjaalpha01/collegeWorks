package aula15;

public class IRPF implements TipoImposto {

	@Override
	public Double calcularImposto(Double mercadoria) {
		
		return mercadoria * 0.075;
	}
}
