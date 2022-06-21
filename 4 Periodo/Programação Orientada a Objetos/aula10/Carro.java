package aula10;

public class Carro extends Veiculo {

	private Integer numeroPortas;
	
	public Carro(String modelo, String fabricante, Integer ano, Integer numeroPassageiros, String combustível,
			Integer numeroPortas) {
		
		super(modelo, fabricante, ano, numeroPassageiros, combustível);
		this.numeroPortas = numeroPortas;
	}

	public void calibrarPneus() {
		System.out.println(this.fabricante + " " + this.modelo + " está calibrando pneus");
	}

	public Integer getNumeroPortas() {
		return numeroPortas;
	}
}
