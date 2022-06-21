package aula15;

public class CarrinhoCompraTeste {

	public static void main(String[] args) {
		
		CarrinhoCompra cc = new CarrinhoCompra(100.0, 200, new Transportadora());
		
		cc.realizarCompra();
	}
}
