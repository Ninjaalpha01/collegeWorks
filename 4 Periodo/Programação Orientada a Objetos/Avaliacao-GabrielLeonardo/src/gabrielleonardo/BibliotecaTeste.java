package gabrielleonardo;

import java.util.ArrayList;
import java.util.List;

public class BibliotecaTeste {

	public static void main(String[] args) {
		
		List<Livro> acervo1 = new ArrayList<Livro>();
		
		Livro liv1 = new Livro(135, "Viagem ao Centro da Terra", "Julio Verne", "EditLivros", 350, 2006);
		Livro liv2 = new Livro(212, "Fundamentos de Cáculo", "Griffin", "Casteldit", 120, 2012);
//		Livro liv3 = new Livro(231, "Programação Orientada a Objetos", "Noah Jason", "Geniedit", 278, 2017);
		
		acervo1.add(liv1);
		acervo1.add(liv2);
		
		Biblioteca libUtf = new Biblioteca(acervo1);
		
		libUtf.adicionarLivro(231, "Programação Orientada a Objetos", "Noah Jason", "Geniedit", 278, 2017);
		libUtf.verificarAcervo();
		
		libUtf.emprestarLivro(135, "Gabriel", 11);
		libUtf.emprestarLivro(135, "Jose", 12);
		libUtf.emprestarLivro(212, "José", 12);
		
		libUtf.devolverLivro(212, 18);
		libUtf.devolverLivro(135, 20);
		
		libUtf.devolverLivro(231, 20);
		libUtf.emprestarLivro(231, "Maria", 20);
		libUtf.emprestarLivro(23, "Carlos", 22);
		libUtf.emprestarLivro(212, "Carlos", 22);
		
		libUtf.verificarAcervo();
	}
}
