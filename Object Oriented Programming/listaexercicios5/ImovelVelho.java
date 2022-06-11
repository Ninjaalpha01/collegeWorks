package listaexercicios5;

public class ImovelVelho extends Imovel {

	private Double desconto;
	private Double valorTotal;
	
	public ImovelVelho(Double valorBase, String endereco, Double desconto) {
		
		super(valorBase, endereco);
		this.desconto = desconto;
		this.valorTotal = super.valorBase - desconto;
	}

	public Double getDesconto() {
		return desconto;
	}
	
	public Double getValorTotal() {
		return valorTotal;
	}
	
	public void imprimirDados() {
		
		super.imprimirDados();
		System.out.println("Valor de desconto: " + this.desconto);
		System.out.println("Valor total: " + this.valorTotal);
	}
}
