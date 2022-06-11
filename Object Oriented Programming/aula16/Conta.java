package aula16;

public class Conta {

	private int numConta;
	private double saldo;
	private String nomeTitular;
	
	public Conta(int numConta, String nomeTitular) {
		
		this.numConta = numConta;
		this.nomeTitular = nomeTitular;
		this.saldo = 0.00;
	}
	
	public void verificarSaldo() {
		
		System.out.println("======Saldo=======");
		System.out.println("Número da Conta: " + this.numConta);
		System.out.println("Titular: " + this.nomeTitular);
		System.out.printf("Saldo: R$%.2f\n", this.saldo);
	}
	
	public void realizarSaque(double valor) {
		
		if (valor <= this.saldo) {
			this.saldo -= valor;
			System.out.println("Saque realizado na conta " + this.numConta);
		}
		else
			System.out.println("Saldo insuficiente na conta " + this.numConta);
	}
	
	public void realizarDeposito(Double valor) {
		
		this.saldo += valor;
		System.out.println("Deposito realizado na conta " + this.numConta);
	}

	public Integer getNumConta() {
		return numConta;
	}

	public String getNomeTitular() {
		return nomeTitular;
	}
}
