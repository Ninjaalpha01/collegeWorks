package listaexercicios6;

public class FilmeLoca {

	private String titulo;
	private Integer duracao;
	private Double preco;
	private boolean disponivel;
	
	public FilmeLoca(String titulo, Integer duracao, Double preco) {
		
		this.titulo = titulo;
		this.duracao = duracao;
		this.preco = preco;
		this.disponivel = true;
	}

	public String getTitulo() {
		return titulo;
	}

	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}

	public Integer getDuracao() {
		return duracao;
	}

	public void setDuracao(Integer duracao) {
		this.duracao = duracao;
	}

	public Double getPreco() {
		return preco;
	}

	public void setPreco(Double preco) {
		this.preco = preco;
	}

	public boolean isDisponivel() {
		return disponivel;
	}
	
	public void setDisponivel(boolean disponivel) {
		this.disponivel = disponivel;
	}
}
