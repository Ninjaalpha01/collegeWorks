package aula10;

public class Aviao extends Veiculo {

	private Integer alturaMaxima;
	
	public Aviao(String modelo, String fabricante, Integer ano, Integer numeroPassageiros, String combustível,
			Integer alturaMaxima) {
		
		super(modelo, fabricante, ano, numeroPassageiros, combustível);
		this.alturaMaxima = alturaMaxima;
	}

	public void voar() {
		System.out.println(this.fabricante + " " + this.modelo + " está voando");
	}

	public Integer getAlturaMaxima() {
		return alturaMaxima;
	}
}
