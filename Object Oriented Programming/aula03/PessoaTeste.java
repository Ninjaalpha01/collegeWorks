package aula03;

public class PessoaTeste {

	public static void main(String[] args) {
		
		Pessoa p1 = new Pessoa();
		Pessoa p2 = new Pessoa();
		Pessoa p3 = new Pessoa();
		
		p1.nome = "João";
		p1.idade = 25;
		p1.peso = 68.5;
		
		p2.nome = "Maria";
		p2.idade = 30;
		p2.peso = 55.6;
		
		p3.nome = "José";
		p3.idade = 32;
		p3.peso = 62.4;
		
		System.out.println("Pessoas:");
		System.out.println("Nome: " + p1.nome);
		System.out.println("Idade: " + p1.idade);
		System.out.println("Peso: " + p1.peso);
		System.out.println("+++++++++++++");
		
		System.out.println("Nome: " + p2.nome);
		System.out.println("Idade: " + p2.idade);
		System.out.println("Peso: " + p2.peso);
		System.out.println("+++++++++++++");
		
		System.out.println("Nome: " + p3.nome);
		System.out.println("Idade: " + p3.idade);
		System.out.println("Peso: " + p3.peso);
	}
}
