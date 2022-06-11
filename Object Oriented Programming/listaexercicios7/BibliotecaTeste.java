package listaexercicios7;

import java.util.ArrayList;
import java.util.List;

public class BibliotecaTeste {

	public static void main(String[] args) {

		List<Livro> acervo = new ArrayList<Livro>();
		
		Livro liv1 = new Livro("O Dia Depois de Amanhã", "Selton Melo");
		Livro liv2 = new Livro("Interestelar", "Christopher Nolan");
		Livro liv3 = new Livro("Harry Potter", "JK Rowling");
		Livro liv4 = new Livro("OpenGL SuperBible", "Mauren");
		Livro liv5 = new Livro("Sistemas Operacionais", "Taunerman");
		
		acervo.add(liv1);
		acervo.add(liv2);
		acervo.add(liv3);
		acervo.add(liv4);
		
		Biblioteca library = new Biblioteca();
		
		library.addAcervo(acervo);
		
		library.verificarDisponibilidade("interestelar");
		library.emprestarLivro("Interestelar", 15);
		library.verificarDisponibilidade("Interestelar");
		
		library.addLivro(liv5);
		library.verificarDisponibilidade("Harry Potter");
		library.emprestarLivro("Harry Potter", 18);
		
		library.devolverLivro("Interestelar", 18);
		library.devolverLivro("harry Potter", 30);
	}
}
