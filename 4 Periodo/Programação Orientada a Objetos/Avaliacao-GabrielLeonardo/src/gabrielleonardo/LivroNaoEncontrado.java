package gabrielleonardo;

public class LivroNaoEncontrado extends Exception {
	
	public LivroNaoEncontrado(Integer codigo)
	{
		System.err.println("Não foi possível encontrar o livro cod: " + codigo + " no acervo.");
	}
}
