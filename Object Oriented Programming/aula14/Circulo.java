package aula14;

public class Circulo extends Forma {

	private Double raio;

	public Circulo(String cor, Double raio) {
	
		super(cor);
		this.raio = raio;
	}
	
	public Double getRaio() {
		return raio;
	}

	public void setRaio(Double raio) {
		this.raio = raio;
	}

	@Override
	public Double calcularPerimetro() {
		
		return 2 * Math.PI * this.raio;
	}

	@Override
	public Double calcularArea() {
		
		return Math.pow(Math.PI * this.raio, 2);
	}
}
