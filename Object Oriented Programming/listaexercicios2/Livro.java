package listaexercicios2;

public class Livro {

	String titulo;
	String autor;
	String editora;
	int numPaginas;
	int anoPublicacao;
	boolean situacao = true; //true = disponivel
	
	public void emprestar() {
		
		if(situacao) {
			situacao = false;
			System.out.println("Livro foi emprestado com sucesso");
		}
		else 
			System.out.println("Livro indisponivel no momento");
	}
	
	public void devolver() {
		if(!situacao) {
			situacao = true;
			System.out.println("Livro foi devolvido com sucesso");
		}
		else
			System.out.println("Livro ja devolvido");
	}
	
	public void imprimirDados() {
		System.out.print(titulo + ", " + autor + ", " + editora
					+ ", " + numPaginas + ", " + anoPublicacao);
		if(situacao)
			System.out.println(", disponivel para emprestimo");
		else
			System.out.println(", indisponivel para emprestimo");
	}
}
