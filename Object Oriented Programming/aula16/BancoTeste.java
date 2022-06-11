package aula16;

public class BancoTeste {

	public static void main(String[] args) {
		
		Banco bank = new Banco(234542, "New Bank");
		
		bank.criarNovaConta(0, "Gabriel Leonardo");
		bank.criarNovaConta(1, "Thais Boschini");
		
		bank.realizarDepositoConta(0, 900.0);
		bank.realizarDepositoConta(1, 1850.0);
		
		bank.realizarSaqueConta(0, 500.0);
		bank.realizarSaqueConta(1, 2000.0);
		bank.realizarSaqueConta(1, 200.0);
		
		bank.verificarSaldoConta(0);
		bank.verificarSaldoConta(1);
	}
}
