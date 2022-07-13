package gabrielleonardo;

import java.util.List;

public class Biblioteca {
	
	List<Livro> acervo;

	public Biblioteca(List<Livro> acervo) {
	
		this.acervo = acervo;
	}
	
	public Livro buscarLivro(int codigo) {
		
		try
		{
			for (Livro livro : acervo) {
				if (livro.getCodigo() == codigo)
					return livro;
			}
			throw new LivroNaoEncontrado(codigo);
		}
		catch (LivroNaoEncontrado lne) {
			return null;
		}
	}
	
	public void adicionarLivro(Integer codigo, String titulo, String autor, String editora, Integer numPag, Integer anoPublicacao) {
		
		Livro livro = new Livro(codigo, titulo, autor, editora, numPag, anoPublicacao);
		
		acervo.add(livro);
		System.out.println("Livro cod: " + codigo + " adicionado ao acervo.\n");
	}
	
	public void emprestarLivro(int codigo, String nomeAluno, Integer diaEmprestimo) {
		
		Livro livro = this.buscarLivro(codigo);
		
		try
		{
			if (livro != null) {
				if (livro.isDisponivel() == false)
					throw new LivroNaoDisponivel(codigo);
				
				livro.setDisponivel(false);
				livro.setNomeAluno(nomeAluno);
				livro.setDiaEmprestimo(diaEmprestimo);
				System.out.println("Empréstimo do livro cod: " + codigo + " foi realizado com sucesso.\n");
			}
		}
		catch (LivroNaoDisponivel lnd)
		{
			return;
		}
		
	}
	
	public void devolverLivro(int codigo, int diaDevolucao) {
		
		Livro livro = this.buscarLivro(codigo);
		
		try
		{
			if (livro != null) {
				if (livro.isDisponivel() == true)
					throw new LivroNaoEmprestado(codigo);
				
				livro.setDisponivel(true);
				livro.setNomeAluno(null);
				livro.setDiaDevolucao(diaDevolucao);
				
				double valorMulta = this.verificarMulta(livro.getDiaEmprestimo(), livro.getDiaDevolucao());
				
				System.out.println("Dia de empréstimo: " + livro.getDiaEmprestimo());
				System.out.println("Dia de devolução: " + livro.getDiaDevolucao());
				
				if (valorMulta > 0.0)
					System.out.printf("Valor de multa a se pagar: R$%.2f \n", valorMulta);
				
				System.out.println("Devolução do livro cod: " + codigo + " foi realizado com sucesso.\n");
			}
		}
		catch(LivroNaoEmprestado lne)
		{
			return;
		}
	}
	
	public double verificarMulta(int diaEmprestimo, int diaDevolucao) {
		
		Double valorMulta = 0.0;
		int diasEmprestados = diaDevolucao-diaEmprestimo; 
		
		if (diasEmprestados > 7)
			valorMulta = 1.5 * (diasEmprestados-7);
		
		return valorMulta;
	}
	
	public void verificarAcervo() {
		
		for (Livro livro : acervo) {
			System.out.println("---Livro cod: " + livro.getCodigo() + "---");
			System.out.println("Titulo: " + livro.getTitulo());
			System.out.println("Autor: " + livro.getAutor());
			System.out.println("Editora: " + livro.getEditora());
			System.out.println("Número de Páginas: " + livro.getNumPag());
			if (livro.isDisponivel())
				System.out.println("Livro Disponível");
			else {
				System.out.println("Livro Emprestado para: " + livro.getNomeAluno());
				System.out.println("Dia do Empréstimo: " + livro.getDiaEmprestimo());
			}
			System.out.println("\n");
		}
	}
}
