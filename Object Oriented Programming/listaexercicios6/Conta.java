package listaexercicios6;

import java.util.Scanner;

public class Conta {

	private Prato entrada;
	private Prato principal;
	private Prato sobremesa;
	private Double valorTotal;
	private Cliente cliente;
	private Scanner input;
	
	public Conta(Cliente cliente) {
		
		this.valorTotal = 0.0;
		this.cliente = cliente;
		this.input = new Scanner(System.in);
	}

	public Prato getEntrada() {
		return entrada;
	}

	public void setEntrada(Prato entrada) {
		this.entrada = entrada;
	}

	public Prato getPrincipal() {
		return principal;
	}

	public void setPrincipal(Prato principal) {
		this.principal = principal;
	}

	public Prato getSobremesa() {
		return sobremesa;
	}

	public void setSobremesa(Prato sobremesa) {
		this.sobremesa = sobremesa;
	}

	public void setValorTotal(Double valorTotal) {
		this.valorTotal = valorTotal;
	}

	public Double getValorTotal() {
		return valorTotal;
	}

	public Cliente getCliente() {
		return cliente;
	}

	public void setCliente(Cliente cliente) {
		this.cliente = cliente;
	}
	
	public void adicionarPrato() {
		
		Integer opc;
		
		System.out.println("Qual prato deseja adicionar:");
		System.out.println("1 - Prato de Entrada");
		System.out.println("2 - Prato Principal");
		System.out.println("3 - Sobremesa");
		
		opc = input.nextInt();
		
		switch(opc)
		{
			case 1:
				this.entrada = new Prato(1, "Shimeji", "Porção de cogumelos", 7.00);
				this.valorTotal += this.entrada.getPrecoUnid();
				break;
			
			case 2:
				this.principal = new Prato(2, "Temaki de Salmão", "Arroz com salmão enrolado em algas", 45.99);
				this.valorTotal += this.principal.getPrecoUnid();
				break;
			
			case 3:
				this.sobremesa = new Prato(3, "4 Hot Rolls de Morango", "Arroz com morango envolto em alga frita", 21.50);
				this.valorTotal += this.sobremesa.getPrecoUnid();
				break;
		}
	}
	
	public void imprimirConta() {
		
		System.out.println("Pratos consumidos:");
		
		if (this.entrada != null)
		{
			System.out.println("Nome: " + this.entrada.getNome());
			System.out.printf("Preço: R$%.2f\n", this.entrada.getPrecoUnid());
		}
		
		if (this.principal != null)
		{
			System.out.println("Nome: " + this.principal.getNome());
			System.out.printf("Preço: R$%.2f\n", this.principal.getPrecoUnid());
		}
		
		if (this.sobremesa != null)
		{
			System.out.println("Nome: " + this.sobremesa.getNome());
			System.out.printf("Preço: R$%.2f\n", this.sobremesa.getPrecoUnid());
		}
		
		this.valorTotal *= 1.1;
		System.out.printf("Valor total: R$%.2f\n", this.valorTotal);
	}
}
