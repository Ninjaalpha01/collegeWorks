package listaexercicios6;

public class ProcessoInstituicao {

	private Integer numero;
	private String descricao;
	private String dataCriacao;
	
	public ProcessoInstituicao(Integer numero, String descricao, String dataCriacao) {
		
		this.numero = numero;
		this.descricao = descricao;
		this.dataCriacao = dataCriacao;
	}

	public Integer getNumero() {
		return numero;
	}

	public void setNumero(Integer numero) {
		this.numero = numero;
	}

	public String getDescricao() {
		return descricao;
	}

	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}

	public String getDataCriacao() {
		return dataCriacao;
	}

	public void setDataCriacao(String dataCriacao) {
		this.dataCriacao = dataCriacao;
	}
}
