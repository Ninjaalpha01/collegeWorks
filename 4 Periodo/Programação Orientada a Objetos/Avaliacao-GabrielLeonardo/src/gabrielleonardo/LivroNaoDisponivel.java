package gabrielleonardo;

public class LivroNaoDisponivel extends Exception {

	public LivroNaoDisponivel(Integer codigo) {
		
		System.err.println("O livro cod: " + codigo + " não está disponível para empréstimo");
	}
}
