package aula10;

public class Aviao extends Veiculo {

	private Integer alturaMaxima;
	
	public Aviao(String modelo, String fabricante, Integer ano, Integer numeroPassageiros, String combust�vel,
			Integer alturaMaxima) {
		
		super(modelo, fabricante, ano, numeroPassageiros, combust�vel);
		this.alturaMaxima = alturaMaxima;
	}

	public void voar() {
		System.out.println(this.fabricante + " " + this.modelo + " est� voando");
	}

	public Integer getAlturaMaxima() {
		return alturaMaxima;
	}
}
