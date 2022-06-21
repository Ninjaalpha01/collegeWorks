package aula14;

public class Quadrado extends Forma {

	private Double lado;

	public Quadrado(String cor, Double lado) {
	
		super(cor);
		this.lado = lado;
	}

	public Double getLado() {
		return lado;
	}

	public void setLado(Double lado) {
		this.lado = lado;
	}

	@Override
	public Double calcularPerimetro() {
	
		return this.lado * 4;
	}

	@Override
	public Double calcularArea() {
	
		return Math.pow(this.lado, 2);
	}
}
