package listaexercicios7;

public class Livro {

	private String titulo;
	private String autor;
	private Integer anoPublicacao;
	private String editora;
	private Integer numPag;
	private boolean disponivel;
	private Integer diaEmprestimo;
	private Integer diaDevolucao;
	
	public Livro(String titulo, String autor, Integer anoPublicacao, String editora, Integer numPag) {
		
		this.titulo = titulo;
		this.autor = autor;
		this.anoPublicacao = anoPublicacao;
		this.editora = editora;
		this.numPag = numPag;
		this.disponivel = true;
	}
	
	public Livro(String titulo, String autor) {
		this(titulo, autor, 2020, "Panamá", 300);
	}

	public boolean isDisponivel() {
		return disponivel;
	}

	public void setDisponivel(boolean disponivel) {
		this.disponivel = disponivel;
	}

	public String getTitulo() {
		return titulo;
	}

	public String getAutor() {
		return autor;
	}

	public Integer getAnoPublicacao() {
		return anoPublicacao;
	}

	public String getEditora() {
		return editora;
	}

	public Integer getNumPag() {
		return numPag;
	}

	public Integer getDiaEmprestimo() {
		return diaEmprestimo;
	}

	public void setDiaEmprestimo(Integer diaEmprestimo) {
		this.diaEmprestimo = diaEmprestimo;
	}

	public Integer getDiaDevolucao() {
		return diaDevolucao;
	}

	public void setDiaDevolucao(Integer diaDevolucao) {
		this.diaDevolucao = diaDevolucao;
	}
}
