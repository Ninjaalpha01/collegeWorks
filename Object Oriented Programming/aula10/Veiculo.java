package aula10;

public class Veiculo {

	protected String modelo;
	protected String fabricante;
	protected Integer ano;
	protected Integer numeroPassageiros;
	protected String combust�vel;
	
	public Veiculo(String modelo, String fabricante, Integer ano, Integer numeroPassageiros, String combust�vel) {
		
		this.modelo = modelo;
		this.fabricante = fabricante;
		this.ano = ano;
		this.numeroPassageiros = numeroPassageiros;
		this.combust�vel = combust�vel;
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

	public String getCombust�vel() {
		return combust�vel;
	}

	public void abastecer() {
		System.out.println(this.fabricante + " " + this.modelo + " est� abastecendo com: " + this.combust�vel);
	}
}
