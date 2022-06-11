package listaexercicios3;

public class ContaTeste {

	public static void main(String[] args) {
		
		Conta c1 = new Conta(999, "123456");
		
		c1.depositar(100.50);
		c1.sacar(60.43);
		System.out.println("Numero da agencia: " + c1.getNumAgencia());
		System.out.println("Numero da conta: " + c1.getNumConta());
		c1.verificacaoSaldo();
		c1.sacar(100);
	}
}
