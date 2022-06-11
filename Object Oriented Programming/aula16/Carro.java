package aula16;

public class Carro {

	private String placa;
	private String nome;
	
	public Carro(String placa, String nome) {
		super();
		this.placa = placa;
		this.nome = nome;
	}

	public String getPlaca() {
		return placa;
	}

	public void setPlaca(String placa) {
		this.placa = placa;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}
}
