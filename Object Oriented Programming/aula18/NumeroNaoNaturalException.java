package aula18;

public class NumeroNaoNaturalException extends Exception {

	public NumeroNaoNaturalException() {
		super("Número não Natural");
	}
	
	public NumeroNaoNaturalException(String message) {
		super(message);
	}
}
