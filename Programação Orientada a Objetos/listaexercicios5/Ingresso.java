package listaexercicios5;

public class Ingresso {

	protected Double valor;
	protected String tipo;
	
	public Ingresso(Double valor, String tipo) {
	
		this.valor = valor;
		this.tipo = tipo;
	}

	public Double getValor() {
		return valor;
	}

	public String getTipo() {
		return tipo;
	}
	
	public void imprimirDadosIngresso() {
		System.out.println("Tipo de Ingresso: " + this.tipo);
	}
}
