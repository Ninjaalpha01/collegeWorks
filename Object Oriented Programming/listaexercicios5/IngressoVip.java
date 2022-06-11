package listaexercicios5;

public class IngressoVip extends Ingresso {

	protected Double valorAdicional;
	protected String localizacao;
	protected Double valorTotal;
	
	public IngressoVip(Double valor, String tipo, Double valorAdicional, String localizacao) {
		
		super(valor, tipo);
		this.valorAdicional = valorAdicional;
		this.localizacao = localizacao;
	}

	public Double getValorAdicional() {
		return valorAdicional;
	}

	public String getLocalizacao() {
		return localizacao;
	}

	public Double getValorTotal() {
		return valorTotal;
	}
	
	public Double calcularValorIngressoVip() {
		
		this.valorTotal = super.valor + this.valorAdicional;
		return this.valorTotal;
	}
	
	public void imprimirDadosIngresso() {
		
		super.imprimirDadosIngresso();
		System.out.println("Localização: " + this.localizacao);
		System.out.printf("Valor do Ingresso VIP: R$%.2f\n", this.valorTotal);
	}
}
