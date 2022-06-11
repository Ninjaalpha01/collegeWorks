package listaexercicios2;

public class LivroTeste {

	public static void main(String[] args) {
		
		Livro livro1 = new Livro();
		
		livro1.titulo = "Java - Como Programar";
		livro1.autor = "Paul Deitel";
		livro1.editora = "Editora Pearson";
		livro1.numPaginas = 297;
		livro1.anoPublicacao = 2013;
		
		livro1.emprestar();
		livro1.imprimirDados();
		livro1.devolver();
		livro1.imprimirDados();
	}
}
