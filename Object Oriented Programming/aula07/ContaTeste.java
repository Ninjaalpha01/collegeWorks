package aula07;

public class ContaTeste {

	public static void main(String[] args) {
		
		Conta c1 = new Conta(111, "João da Silva");
		
		c1.depositar(1000.00);
		c1.imprimirSaldo();
		c1.sacar(1100.00);
		System.out.println("Nome: " + c1.getTitular());
		c1.setTitular("Maria da Silva");
		System.out.println("Nome: " + c1.getTitular());
	}
}
