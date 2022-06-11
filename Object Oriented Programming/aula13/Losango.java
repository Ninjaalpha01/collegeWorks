package aula13;

public class Losango extends Quadrilatero {

	private Double diagonalMenor;
	private Double diagonalMaior;
	
	public Losango(Double diagonalMenor, Double diagonalMaior) {
		
		super();
		this.diagonalMenor = diagonalMenor;
		this.diagonalMaior = diagonalMaior;
	}
	
	public void calcularArea() {
		
		double area = this.diagonalMaior*this.diagonalMenor/2;
		System.out.println("Área losango: " + area);
	}
}
