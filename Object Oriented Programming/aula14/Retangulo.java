package aula14;

public class Retangulo extends Forma {

	private Double base;
	private Double altura;
	
	public Retangulo(String cor, Double base, Double altura) {
		super(cor);
		this.base = base;
		this.altura = altura;
	}
	
	public Double calcularPerimetro() {
		
		return (this.base * 2) + (this.altura * 2);
	}
	
	public Double calcularArea() {
		
		return this.altura * this.base;
	}
}
