package listaexercicios7;

public class BancoTeste {

	public static void main(String[] args) {
		Cliente cli1 = new Cliente("João Carlos", "2839192");
		Cliente cli2 = new Cliente("Pedro Sampaio", "2367864");
		
		Conta conta = new Conta(0, cli1);
		Conta conta2 = new Conta(1, cli2);
		
		System.out.println(conta.toString());
		System.out.println(conta2.toString());
		
		Banco bank = new Banco();
		
		bank.criarConta(0, cli1);
		bank.criarConta(1, cli2);
		
		System.out.println("Conta: " + conta.getNumConta());
		System.out.println("Conta2: " + conta2.getNumConta());
		
		bank.depositar(conta.getNumConta(), 5000.0);
		bank.depositar(conta2.getNumConta(), 2500.0);
		
		bank.sacar(conta.getNumConta(), 1500.0);
		bank.sacar(conta2.getNumConta(), 3000.0);
		
		bank.verificarSaldo(conta.getNumConta());
		bank.verificarSaldo(conta2.getNumConta());
	}
}
