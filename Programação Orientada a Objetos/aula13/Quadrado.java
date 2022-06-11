package aula13;

public class Quadrado extends Quadrilatero {

	private Double lado;
	
	public Quadrado(Double lado) {
		
		super();
		this.lado = lado;
	}
	
	public void calcularArea() {
		
		double area = Math.pow(this.lado, 2);
		System.out.println("Área quadrado: " + area);
	}
}
