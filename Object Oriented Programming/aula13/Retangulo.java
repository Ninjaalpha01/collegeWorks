package aula13;

public class Retangulo extends Quadrilatero {

	private Double base;
	private Double altura;
	
	public Retangulo(Double base, Double altura) {
		
		super();
		this.base = base;
		this.altura = altura;
	}
	
	public void calcularArea() {
		
		double area = this.base*this.altura;
		System.out.println("Área retangulo: " + area);
	}
}
