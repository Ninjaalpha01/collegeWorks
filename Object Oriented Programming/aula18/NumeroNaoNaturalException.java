package aula18;

public class NumeroNaoNaturalException extends Exception {

	public NumeroNaoNaturalException() {
		super("N�mero n�o Natural");
	}
	
	public NumeroNaoNaturalException(String message) {
		super(message);
	}
}
