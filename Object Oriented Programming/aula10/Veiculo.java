package aula10;

public class Veiculo {

	protected String modelo;
	protected String fabricante;
	protected Integer ano;
	protected Integer numeroPassageiros;
	protected String combustível;
	
	public Veiculo(String modelo, String fabricante, Integer ano, Integer numeroPassageiros, String combustível) {
		
		this.modelo = modelo;
		this.fabricante = fabricante;
		this.ano = ano;
		this.numeroPassageiros = numeroPassageiros;
		this.combustível = combustível;
	}
	
	public String getModelo() {
		return modelo;
	}

	public String getFabricante() {
		return fabricante;
	}

	public Integer getAno() {
		return ano;
	}

	public Integer getNumeroPassageiros() {
		return numeroPassageiros;
	}

	public String getCombustível() {
		return combustível;
	}

	public void abastecer() {
		System.out.println(this.fabricante + " " + this.modelo + " está abastecendo com: " + this.combustível);
	}
}
