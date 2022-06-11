package aula09;

public class Pedido {

	private Integer id;
	private String data;
	private Status statusPedido;
	
	public Pedido(Integer id, String data) {
		super();
		this.id = id;
		this.data = data;
		this.statusPedido = Status.AGUARDANDO_PAGAMENTO;
	}

	public void setStatusPedido(Status statusPedido) {
		this.statusPedido = statusPedido;
	}

	@Override
	public String toString() {
		return "id: " + id + "\ndata: " + data + "\nstatusPedido: " + statusPedido;
	}
	
}
