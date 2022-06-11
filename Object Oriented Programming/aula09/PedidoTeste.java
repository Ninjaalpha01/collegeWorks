package aula09;

public class PedidoTeste {

	public static void main(String[] args) {
		
		Pedido pedido = new Pedido(1, "10/10/2010");
		
		System.out.println(pedido);
		
		pedido.setStatusPedido(Status.PROCESSANDO);
		
		System.out.println("========================================");
		System.out.println(pedido);
	}
}
