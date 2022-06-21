package aula10;

public class Carro extends Veiculo {

	private Integer numeroPortas;
	
	public Carro(String modelo, String fabricante, Integer ano, Integer numeroPassageiros, String combust�vel,
			Integer numeroPortas) {
		
		super(modelo, fabricante, ano, numeroPassageiros, combust�vel);
		this.numeroPortas = numeroPortas;
	}

	public void calibrarPneus() {
		System.out.println(this.fabricante + " " + this.modelo + " est� calibrando pneus");
	}

	public Integer getNumeroPortas() {
		return numeroPortas;
	}
}
