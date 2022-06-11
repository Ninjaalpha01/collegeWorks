package aula14;

public class Comissionado extends Funcionario {

	private Double totalVendas;
	private Double taxaComissao;
	
	public Comissionado(String nome, Long cpf, Double salarioBase, Double totalVendas, Double taxaComissao) {
		
		super(nome, cpf, salarioBase);
		this.totalVendas = totalVendas;
		this.taxaComissao = taxaComissao;
	}
	
	public Double getTotalVendas() {
		return totalVendas;
	}

	public void setTotalVendas(Double totalVendas) {
		this.totalVendas = totalVendas;
	}

	public Double getTaxaComissao() {
		return taxaComissao;
	}

	public void setTaxaComissao(Double taxaComissao) {
		this.taxaComissao = taxaComissao;
	}

	@Override
	public Double calcularSalario() {
		
		return super.getSalarioBase() + (this.getTotalVendas() * this.getTaxaComissao());
	}

	@Override
	public String toString() {
		return "Comissionado [totalVendas=" + totalVendas + ", taxaComissao=" + taxaComissao + "]";
	}
}
