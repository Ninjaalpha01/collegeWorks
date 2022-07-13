package gabrielleonardo;

public class LivroNaoEmprestado extends Exception {

	public LivroNaoEmprestado(Integer codigo) {
		System.err.println("O livro cod: " + codigo + " não se encontra emprestado.");
	}
}
