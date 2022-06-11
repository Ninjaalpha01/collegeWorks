package listaexercicios7;

import java.util.ArrayList;
import java.util.List;

public class Banco {

	List<Conta> contas;
	
	public Banco() {
		this.contas = new ArrayList<Conta>();
	}

	public void criarConta(Integer numConta, Cliente titular) {
		
		Conta conta = new Conta(numConta, titular);
		contas.add(conta);
	}
	
	public void sacar(Integer numConta, Double valor) {
		
		Double saldo;
		
		for (Conta conta : contas) {
			if (conta.getNumConta() == numConta)
			{
				saldo = conta.getSaldo();
				
				if (saldo >= valor)
				{
					saldo -= valor;
					conta.setSaldo(saldo);
					System.out.println("Saque realizado na conta " + conta.getNumConta());
				}
				else
					System.out.println("Saldo insuficiente");
				
				return;
			}
		}
		System.out.println("Conta não encontrada.");
	}
	
	public void depositar(Integer numConta, Double valor) {
		
		Double saldo;
		
		for (Conta conta : contas) {
			if (conta.getNumConta() == numConta)
			{
				saldo = conta.getSaldo() + valor;
				conta.setSaldo(saldo);
				System.out.println("Deposito realizado na conta " + conta.getNumConta());
				return;
			}
		}
		System.out.println("Conta não encontrada.");
	}
	
	public void verificarSaldo(Integer numConta) {
		
		for (Conta conta : contas) {
			if (conta.getNumConta().equals(numConta))
			{
				System.out.print("Saldo da conta " + conta.getNumConta() + ": ");
				System.out.printf("R$%.2f\n", conta.getSaldo());
				return;
			}
		}
		System.out.println("Conta não encontrada.");
	}
}
