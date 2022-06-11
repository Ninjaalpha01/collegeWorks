package listaexercicios7;

import java.util.ArrayList;
import java.util.List;

public class Biblioteca {

	private List<Livro> acervo;
	private Double multa;
	
	public Biblioteca() {
		
		this.acervo = new ArrayList<Livro>();
		this.multa = 1.50;
	}
	
	public List<Livro> getAcervo() {
		return acervo;
	}

	public Double getMulta() {
		return multa;
	}

	public void addAcervo(List<Livro> newAcervo) {
		
		this.acervo = newAcervo;
		System.out.println("Acervo adicionado a biblioteca\n");
	}
	
	public void addLivro(Livro livro) {
		this.acervo.add(livro);
		System.out.println("Livro \"" + livro.getTitulo() + "\" adicionado ao acervo\n");
	}
	
	private Livro buscaLivro(String titulo) {
		
		titulo = titulo.toLowerCase();
		
		for (Livro livro : acervo) {
			if (livro.getTitulo().toLowerCase().equals(titulo))
				return livro;
		}
		System.out.println("Livro não encontrado\n");
		return null;
	}
	
	public void verificarDisponibilidade(String  titulo) {
		
		System.out.println("=====Verificação====");
		
		Livro livro = this.buscaLivro(titulo);
		
		if (livro == null)
			return;
		
		if (livro.isDisponivel())
			System.out.println("O livro \"" + livro.getTitulo() + "\" está disponivel\n");
		else
			System.out.println("O livro \"" + livro.getTitulo() + "\" não está disponivel\n");
	}
	
	public void emprestarLivro(String titulo, Integer diaEmprestimo) {
		
		System.out.println("=====Empréstimo=====");
		
		Livro livro = this.buscaLivro(titulo);
		
		if (livro == null)
			return;
		
		if (livro.isDisponivel())
		{
			livro.setDiaEmprestimo(diaEmprestimo);
			livro.setDisponivel(false);
			System.out.println("Livro \"" + livro.getTitulo() + "\" emprestado\n");
		}
		else
			System.out.println("O livro \"" + livro.getTitulo() + "\" não está disponível\n");
	}
	
	public void devolverLivro(String titulo, Integer diaDevolucao) {
		
		System.out.println("======Devolução======");
		
		Livro livro = this.buscaLivro(titulo);
		Integer diasEmprestado;
		Double valorMulta;
		
		if (livro == null)
			return;
		
		if (livro.isDisponivel())
		{
			System.out.println("Livro já devolvido\n");
			return;
		}
		
		livro.setDisponivel(true);
		System.out.println("Livro \"" + livro.getTitulo() + "\" devolvido\n");
		
		diasEmprestado = diaDevolucao - livro.getDiaEmprestimo();
		
		if (diasEmprestado > 7)
		{
			valorMulta = this.multa * (diasEmprestado - 7);
			System.out.println("A devolução ocorreu depois do prazo");
			System.out.println((diasEmprestado - 7) + " dias atrasados");
			System.out.printf("Multa a pagar: R$%.2f\n\n", valorMulta);
		}
	}
}
