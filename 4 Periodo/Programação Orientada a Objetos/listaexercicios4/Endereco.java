package listaexercicios4;

public class Endereco {

	private Integer numero;
	private String logradouro;
	private String bairro;
	private String cidade;
	private String unidadeFederativa;
	
	public Endereco(Integer numero, String logradouro, String bairro, String cidade, String unidadeFederativa){
		this.numero = numero;
		this.logradouro = logradouro;
		this.bairro = bairro;
		this.cidade = cidade;
		this.unidadeFederativa = unidadeFederativa;
	}
	
	public Endereco(Integer numero, String logradouro, String bairro, String cidade){
		this(numero, logradouro, bairro, cidade, "PR");
	}

	public void setNumero(Integer numero) {
		this.numero = numero;
	}

	public void setLogradouro(String logradouro) {
		this.logradouro = logradouro;
	}

	public void setBairro(String bairro) {
		this.bairro = bairro;
	}

	public void setCidade(String cidade) {
		this.cidade = cidade;
	}

	public void setUnidadeFederativa(String unidadeFederativa) {
		this.unidadeFederativa = unidadeFederativa;
	}

	public Integer getNumero() {
		return numero;
	}

	public String getLogradouro() {
		return logradouro;
	}

	public String getBairro() {
		return bairro;
	}

	public String getCidade() {
		return cidade;
	}

	public String getUnidadeFederativa() {
		return unidadeFederativa;
	}
	
	public void imprimirEndereco() {
		
		System.out.println("-----ENDEREÇO-----");
		System.out.println("Logradouro: " + this.logradouro);
		System.out.println("Número: " + this.numero);
		System.out.println("Bairro: " + this.bairro);
		System.out.println("Cidade: " + this.cidade);
		System.out.println("Unidade Federativa: " + this.unidadeFederativa);
	}
}
