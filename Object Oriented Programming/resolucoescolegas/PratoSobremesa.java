package resolucoescolegas;

public class PratoSobremesa  {

	private String nome;
	private String numero;
	private String ingredientes;
	private double preço;
	
	public PratoSobremesa(String nome, String numero, String ingredientes, double preço) {
		this.nome = nome;
		this.numero = numero;
		this.ingredientes = ingredientes;
		this.preço = preço;
	}

	
	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getNumero() {
		return numero;
	}

	public void setNumero(String numero) {
		this.numero = numero;
	}

	public String getIngredientes() {
		return ingredientes;
	}

	public void setIngredientes(String ingredientes) {
		this.ingredientes = ingredientes;
	}

	public double getPreço() {
		return preço;
	}

	public void setPreço(double preço) {
		this.preço = preço;
	}
	
	
	
}
