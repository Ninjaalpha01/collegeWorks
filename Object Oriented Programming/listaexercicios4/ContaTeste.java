package listaexercicios4;

public class ContaTeste {

	public static void main(String[] args) {
		
		Endereco end = new Endereco(101, "Laurentino Deco Fagundes", "Jd. Carvalho", "Ponta Grossa");
		Titular tit = new Titular("482392594-90", "Cleiton Fernandes", "10/10/1989", 3450.00, end);
		Conta conta = new Conta("012230-5", 5000.0, tit);
		
		conta.sacar(175.30);
		conta.emitirSaldo();
		conta.depositar(1000.0);
		conta.emitirSaldo();
		conta.sacar(6000.0);
	}
}
