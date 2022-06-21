package aula10;

public class Endereço {

	private String logradouro;
	private Integer numero;
	private String bairro;
	private String cidade;
	private String unidadeFederativa;
	
	public Endereço(String logradouro, Integer numero, String bairro, String cidade, String unidadeFederativa) {
		super();
		this.logradouro = logradouro;
		this.numero = numero;
		this.bairro = bairro;
		this.cidade = cidade;
		this.unidadeFederativa = unidadeFederativa;
	}
	
	public String getLogradouro() {
		return logradouro;
	}
	
	public Integer getNumero() {
		return numero;
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
	
	public void setLogradouro(String logradouro) {
		this.logradouro = logradouro;
	}
	
	public void setNumero(Integer numero) {
		this.numero = numero;
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
}
