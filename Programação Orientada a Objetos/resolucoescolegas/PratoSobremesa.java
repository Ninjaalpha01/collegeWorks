package resolucoescolegas;

public class PratoSobremesa  {

	private String nome;
	private String numero;
	private String ingredientes;
	private double pre�o;
	
	public PratoSobremesa(String nome, String numero, String ingredientes, double pre�o) {
		this.nome = nome;
		this.numero = numero;
		this.ingredientes = ingredientes;
		this.pre�o = pre�o;
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

	public double getPre�o() {
		return pre�o;
	}

	public void setPre�o(double pre�o) {
		this.pre�o = pre�o;
	}
	
	
	
}
