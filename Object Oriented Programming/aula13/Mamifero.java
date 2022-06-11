package aula13;

public class Mamifero {

	protected String nome;
	
	public Mamifero(String nome) {
		
		this.nome = nome;
	}
	
	public void emitirSom() {
		
		System.out.println(this.nome + " está emitindo som genérico.");
	}
}
