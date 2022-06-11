package aula18;

import java.util.InputMismatchException;

public class Calculadora {

	public Double adicao(int x, int y) throws InputMismatchException, Exception{
		return (double)x + y;
	}
	
	public Double subtracao(int x, int y) throws InputMismatchException, Exception{
		return (double)x - y;
	}
	
	public Double multiplicacao(int x, int y) throws InputMismatchException, Exception {
		return (double)x * y;
	}
	
	public Double divisao(int x, int y) throws ArithmeticException, InputMismatchException, Exception {
		return (double)x / y;
	}
	
	public Double potenciacao(int x, int y)throws InputMismatchException, Exception {
		return Math.pow(x, y);
	}
	
	public Double raizQuadrada(int x) throws InputMismatchException, NumeroNaoNaturalException, Exception {
		if (x < 0) {
			throw new NumeroNaoNaturalException();
		}
		return Math.sqrt((double)x);
	}
	
	public Double inverso(int x) throws ArithmeticException, InputMismatchException, Exception {
		return (double)1 / x;
	}
}
