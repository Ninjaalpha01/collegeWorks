package aula15;

public class Imposto {

	private Double mercadoria;
	TipoImposto tipoImp;
	
	public Imposto(Double mercadoria, TipoImposto tipoImp) {

		this.mercadoria = mercadoria;
		this.tipoImp = tipoImp;
	}
	
	public void calcularImposto() {
		
		System.out.printf("Valor a se pagar: R$%.2f\n", mercadoria + this.tipoImp.calcularImposto(this.mercadoria));
	}
}
