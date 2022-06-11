package listaexercicios6;

public class Filme {

	private String titulo;
	private Integer duracao;
	
	public Filme(String titulo, Integer duracao) {
		
		this.titulo = titulo;
		this.duracao = duracao;
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
}
