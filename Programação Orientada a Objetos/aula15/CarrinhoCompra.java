package aula15;

public class CarrinhoCompra {

	private Double valorProdutos;
	private Integer distancia;
	private Frete frete;
	
	public CarrinhoCompra(Double valorProdutos, Integer distancia, Frete frete) {
		
		this.valorProdutos = valorProdutos;
		this.distancia = distancia;
		this.frete = frete;
	}

	public void realizarCompra() {
		
		double valorTotalCompra = this.valorProdutos + this.frete.calcularFrete(this.distancia);
		
		System.out.println("Valor total = " + valorTotalCompra);
	}
	
}
