package listaexercicios5;

public class ImovelNovo extends Imovel {

	private Double adicional;
	private Double valorTotal;

	public ImovelNovo(Double valorBase, String endereco, Double adicional) {
		
		super(valorBase, endereco);
		this.adicional = adicional;
		this.valorTotal = adicional+super.valorBase;
	}
	
	public void imprimirDados() {
		
		super.imprimirDados();
		System.out.println("Valor adicional: " + this.adicional);
		System.out.println("Valor total: " + this.valorTotal);
	}

	public Double getAdicional() {
		return adicional;
	}

	public Double getValorTotal() {
		return valorTotal;
	}
}
