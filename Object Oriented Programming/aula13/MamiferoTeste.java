package aula13;

public class MamiferoTeste {

	public static void main(String[] args) {
		
		Mamifero mamifero = null;
		
		mamifero = new Gato("Garfield");
		//mamifero = new Cachorro("Spike");
		
		mamifero.emitirSom();
	}
}
