package aula14;

public abstract class Forma {

	protected String cor;

	public Forma(String cor) {
	
		this.cor = cor;
	}
	
	public String getCor() {
		return cor;
	}

	public void setCor(String cor) {
		this.cor = cor;
	}

	public abstract Double calcularPerimetro();
	
	public abstract Double calcularArea();
}
