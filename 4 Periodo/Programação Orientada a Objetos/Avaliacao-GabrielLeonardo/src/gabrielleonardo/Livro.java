package gabrielleonardo;

public class Livro {
	
	private int codigo;
	private String titulo;
	private String autor;
	private String editora;
	private int numPag;
	private int anoPublicacao;
	private boolean disponivel;
	private String nomeAluno;
	private int diaEmprestimo;
	private int diaDevolucao;
	
	public Livro(int codigo, String titulo, String autor, String editora, int numPag, int anoPublicacao) {
		
		this.codigo = codigo;
		this.titulo = titulo;
		this.autor = autor;
		this.editora = editora;
		this.numPag = numPag;
		this.anoPublicacao = anoPublicacao;
		this.disponivel = true;
	}

	public int getCodigo() {
		return codigo;
	}

	public boolean isDisponivel() {
		return disponivel;
	}

	public void setDisponivel(boolean disponivel) {
		this.disponivel = disponivel;
	}

	public String getNomeAluno() {
		return nomeAluno;
	}

	public void setNomeAluno(String nomeAluno) {
		this.nomeAluno = nomeAluno;
	}

	public int getDiaEmprestimo() {
		return diaEmprestimo;
	}

	public void setDiaEmprestimo(Integer diaEmprestimo) {
		this.diaEmprestimo = diaEmprestimo;
	}

	public int getDiaDevolucao() {
		return diaDevolucao;
	}

	public void setDiaDevolucao(Integer diaDevolucao) {
		this.diaDevolucao = diaDevolucao;
	}

	public String getTitulo() {
		return titulo;
	}

	public String getAutor() {
		return autor;
	}

	public String getEditora() {
		return editora;
	}

	public int getNumPag() {
		return numPag;
	}

	public int getAnoPublicacao() {
		return anoPublicacao;
	}
	
}
