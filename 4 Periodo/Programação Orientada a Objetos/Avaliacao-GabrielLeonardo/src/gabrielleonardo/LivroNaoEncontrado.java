package gabrielleonardo;

public class LivroNaoEncontrado extends Exception {
	
	public LivroNaoEncontrado(Integer codigo)
	{
		System.err.println("N�o foi poss�vel encontrar o livro cod: " + codigo + " no acervo.");
	}
}
