package listaexercicios3;

public class Conta {

	private int numAgencia;
	private String numConta;
	private double saldo;
	
	public Conta(int numAgencia, String numConta) {
		super();
		this.numAgencia = numAgencia;
		this.numConta = numConta;
		this.saldo = 0;
	}
	
	public void sacar(double valor) {
		
		if (saldo < valor)
			System.out.println("Saldo insuficiente.");
		else
			saldo -= valor;
	}
	
	public void depositar(double valor) {
		saldo += valor;
	}
	
	public void verificacaoSaldo() {
		System.out.println("Saldo: R$" + saldo);
	}

	public int getNumAgencia() {
		return numAgencia;
	}

	public String getNumConta() {
		return numConta;
	}
}
