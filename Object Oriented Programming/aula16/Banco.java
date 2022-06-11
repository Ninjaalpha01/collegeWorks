package aula16;

import java.util.ArrayList;
import java.util.List;

public class Banco {

	private Integer cnpj;
	private String nomeBanco;
	private List<Conta> contas;
	
	public Banco(Integer cnpj, String nomeBanco) {
		
		this.cnpj = cnpj;
		this.nomeBanco = nomeBanco;
		this.contas = new ArrayList<Conta>();
	}
	
	public Integer getCnpj() {
		return cnpj;
	}

	public String getNomeBanco() {
		return nomeBanco;
	}
	
	public void criarNovaConta(Integer numConta, String nomeTitular) {
		
		Conta conta = new Conta(numConta, nomeTitular);
		contas.add(conta);
		
		System.out.println("Conta " + conta.getNumConta() + " criada com sucesso.");
	}
	
	public void verificarSaldoConta(Integer numConta) {
		
		for (Conta conta : contas) {
			if (conta.getNumConta() == numConta)
			{
				conta.verificarSaldo();
				return;
			}
		}
		System.out.println("Número da conta não encontrado.");
	}
	
	public void realizarSaqueConta(Integer numConta, Double valor) {
		
		for (Conta conta : contas) {
			if (conta.getNumConta() == numConta)
			{
				conta.realizarSaque(valor);
				return;
			}
		}
		System.out.println("Número da conta não encontrado.");
	}
	
	public void realizarDepositoConta(Integer numConta, Double valor) {
		
		for (Conta conta : contas) {
			if (conta.getNumConta() == numConta)
			{
				conta.realizarDeposito(valor);
				return;
			}
		}
		System.out.println("Número da conta não encontrado.");
	}
}
