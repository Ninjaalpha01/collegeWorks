package aula04;

public class Pessoa {

	String nome;
	int idade;
	double peso;
	
	public void andar() {
		
		System.out.println(nome + " est� andando");
	}
	
	public void correr() {
		
		System.out.println(nome + " est� correndo");
	}
	
	public void falar() {
		
		System.out.println(nome + " est� falando");
	}
	
	@Override
	public String toString() {
		return "Pessoa [nome=" + nome + ", idade=" + idade + ", peso=" + peso + "]";
	}
}
