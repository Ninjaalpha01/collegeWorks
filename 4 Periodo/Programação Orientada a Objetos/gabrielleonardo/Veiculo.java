package gabrielleonardo;

public abstract class Veiculo {

	protected String marca;
	protected String modelo;
	protected Integer anoFabricacao;
	protected boolean ligado;
	
	public Veiculo(String marca, String modelo, Integer anoFabricacao) {
	
		this.marca = marca;
		this.modelo = modelo;
		this.anoFabricacao = anoFabricacao;
		this.ligado = false;
	}
	
	public boolean isLigado() {
		return ligado;
	}
	
	public void setLigado(boolean ligado) {
		this.ligado = ligado;
	}

	public String getMarca() {
		return marca;
	}

	public void setMarca(String marca) {
		this.marca = marca;
	}

	public String getModelo() {
		return modelo;
	}

	public void setModelo(String modelo) {
		this.modelo = modelo;
	}

	public Integer getAnoFabricacao() {
		return anoFabricacao;
	}

	public void setAnoFabricacao(Integer anoFabricacao) {
		this.anoFabricacao = anoFabricacao;
	}

	public abstract void ligar();
	public abstract void desligar();
	public abstract void realizarTransporte();
}
