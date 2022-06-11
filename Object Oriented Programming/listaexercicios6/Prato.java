package listaexercicios6;

public class Prato {

	private Integer num;
	private String nome;
	private String descricao;
	private Double precoUnid;
	
	public Prato(Integer num, String nome, String descricao, Double precoUnid) {
	
		this.num = num;
		this.nome = nome;
		this.descricao = descricao;
		this.precoUnid = precoUnid;
	}

	public Integer getNum() {
		return num;
	}

	public void setNum(Integer num) {
		this.num = num;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getDescricao() {
		return descricao;
	}

	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}

	public Double getPrecoUnid() {
		return precoUnid;
	}

	public void setPrecoUnid(Double precoUnid) {
		this.precoUnid = precoUnid;
	}
}
