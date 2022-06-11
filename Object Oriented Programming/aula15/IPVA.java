package aula15;

public class IPVA implements TipoImposto {

	@Override
	public Double calcularImposto(Double mercadoria) {
		
		return mercadoria * 0.03;
	}
}
