package aula15;

public class INSS implements TipoImposto {

	@Override
	public Double calcularImposto(Double mercadoria) {
		
		return mercadoria * 0.11;
	}
}
