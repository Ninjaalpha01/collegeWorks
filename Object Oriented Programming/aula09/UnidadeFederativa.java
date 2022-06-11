package aula09;

public enum UnidadeFederativa {

	SANTA_CATARINA("Santa Catarina", "SC", ""),
	RIO_GRANDE_SUL("Rio Grande do Sul", "RS", "Porto Alegre"),
	SAO_PAULO("S�o Paulo", "SP", "S�o Paulo"),
	ESPIRITO_SANTO("Esp�rito Santo", "ES", "Vit�ria"),
	PARANA("Paran�", "PR", "Curitiba"),
	RIO_DE_JANEIRO("Rio de Janeiro", "RJ", "Rio de Janeiro"),
	MINAS_GERAIS("Minas Gerais", "MG", "Belo Horizonte");
	
	private String nomeEstado;
	private String sigla;
	private String capital;
	
	private UnidadeFederativa(String nomeEstado, String sigla, String capital) {
		
		this.nomeEstado = nomeEstado;
		this.sigla = sigla;
		this.capital = capital;
	}

	public String getNomeEstado() {
		return nomeEstado;
	}

	public String getSigla() {
		return sigla;
	}

	public String getCapital() {
		return capital;
	}
}
