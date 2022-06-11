package listaexercicios5;

public class IngressoNormal extends Ingresso {

	public IngressoNormal(Double valor, String tipo) {
		super(valor,tipo);
	}
	
	public void imprimirDadosIngresso() {
		
		super.imprimirDadosIngresso();
		System.out.printf("Valor do Ingresso: R$%.2f\n", this.valor);
	}
}
