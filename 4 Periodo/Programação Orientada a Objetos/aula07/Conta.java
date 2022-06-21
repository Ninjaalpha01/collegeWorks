package aula07;

public class Conta {

	private int numeroConta;
	private String titular;
	private double saldo;
	
	public Conta(int numeroConta, String titular) {
		
		this.numeroConta = numeroConta;
		this.titular = titular;
		this.saldo = 0.00;
	}
	
	public void depositar(double valor) {
		
		this.saldo += valor;
		System.out.println("----Deposito realizado com sucesso.----");
		this.calcularRendimento();
	}
	
	public void sacar(double valor) {
		
		if (this.saldo >= valor) {
			
			this.saldo -= valor;
			System.out.println("----Saque realizado com sucesso.----");
		}
		else {
			System.out.println("----Saldo insuficiente.----");
		}
	}
	
	private void calcularRendimento() {
		
		double rendimento = this.saldo*0.10;
		this.saldo += rendimento;
	}
	
	public void imprimirSaldo() {
		
		System.out.println("Numero da conta: " + this.numeroConta);
		System.out.println("Titular: " + this.titular);
		System.out.println("Saldo: " + this.saldo);
	}
	
	public void setTitular(String titular) {
		
		if (!titular.equals("")) {
			this.titular = titular;
		}
		else {
			System.out.println("String não válida.");
		}
	}
	
	public String getTitular() {
		return this.titular;
	}
}