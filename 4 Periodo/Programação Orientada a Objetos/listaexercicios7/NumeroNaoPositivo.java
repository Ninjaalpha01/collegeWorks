package listaexercicios7;

public class NumeroNaoPositivo extends Exception {

	public NumeroNaoPositivo() {
		super("N�mero n�o Positivo");
	}
	
	public NumeroNaoPositivo(String message) {
		super(message);
	}
}
