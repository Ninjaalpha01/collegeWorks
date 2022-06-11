package aula04;

public class Pessoa {

	String nome;
	int idade;
	double peso;
	
	public void andar() {
		
		System.out.println(nome + " está andando");
	}
	
	public void correr() {
		
		System.out.println(nome + " está correndo");
	}
	
	public void falar() {
		
		System.out.println(nome + " está falando");
	}
	
	@Override
	public String toString() {
		return "Pessoa [nome=" + nome + ", idade=" + idade + ", peso=" + peso + "]";
	}
}
