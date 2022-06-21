package listaexercicios7;

public class NumeroNaoPositivo extends Exception {

	public NumeroNaoPositivo() {
		super("Número não Positivo");
	}
	
	public NumeroNaoPositivo(String message) {
		super(message);
	}
}
