package gabrielleonardo;

public class LivroNaoDisponivel extends Exception {

	public LivroNaoDisponivel(Integer codigo) {
		
		System.err.println("O livro cod: " + codigo + " n�o est� dispon�vel para empr�stimo");
	}
}
