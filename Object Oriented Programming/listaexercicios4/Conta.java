package listaexercicios4;

public class Conta {

	private String numero;
	private Double saldo;
	private Titular titular;
	
	public Conta(String numero, Double saldo, Titular titular) {
		
		this.numero = numero;
		this.saldo = saldo;
		this.titular = titular;
	}
	
	public void sacar(Double valor) {
		
		if (saldo >= valor) 
		{
			saldo -= valor;
			System.out.printf("Saque efetuado no valor de R$%.2f\n", valor);
		}
		else
			System.out.println("Saldo insuficiente para realizar o saque.");
	}
	
	public void depositar(Double valor) {
		
		saldo += valor;
		System.out.printf("Depósito efetuado no valor de R$%.2f\n", valor);
	}
	
	public void emitirSaldo() {
		
		System.out.println("-----CONTA-----");
		System.out.println("Número da Conta: " + this.numero);
		System.out.printf("Saldo: R$%.2f\n", this.saldo);
		this.titular.imprimirTitular();
	}
}
