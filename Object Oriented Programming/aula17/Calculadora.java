package aula17;

public class Calculadora {

	public Double adicao(int x, int y) {
		return (double)x + y;
	}
	
	public Double subtracao(int x, int y) {
		return (double)x - y;
	}
	
	public Double multiplicacao(int x, int y) {
		return (double)x * y;
	}
	
	public Double divisao(int x, int y) {
		try {
			return (double)x / y;
		}
		catch (ArithmeticException ae) {
			System.err.println("Divisão por 0");
		}
		return null;
	}
	
	public Double potenciacao(int x, int y) {
		return Math.pow(x, y);
	}
	
	public Double raizQuadrada(int x) {
		return Math.sqrt((double)x);
	}
	
	public Double inverso(int x) {
		try {
			return (double)1 / x;
		}
		catch (ArithmeticException ae) {
			System.err.println("Divisão por 0");
			return null;
		}
	}
}
