package aula11;

public class CalculadoraTeste {

	public static void main(String[] args) {
	
		Calculadora calc = new Calculadora("Casio");
		
		System.out.println("Media: " + calc.calcularMedia(3.04, 34.1, 23.02, 43.2));
	}
}
