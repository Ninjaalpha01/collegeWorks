package listaexercicios5;

public class Imovel {

	protected Double valorBase;
	protected String endereco;
	
	public Imovel(Double valorBase, String endereco) {
		super();
		this.valorBase = valorBase;
		this.endereco = endereco;
	}
	
	public void imprimirDados() {
		
		System.out.println("Valor Base: " + this.valorBase);
		System.out.println("Endere�o: " + this.endereco);
	}

	public Double getValorBase() {
		return valorBase;
	}

	public String getEndereco() {
		return endereco;
	}
}
