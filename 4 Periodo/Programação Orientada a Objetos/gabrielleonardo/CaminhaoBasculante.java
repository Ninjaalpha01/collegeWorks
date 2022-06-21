package gabrielleonardo;

public class CaminhaoBasculante extends Veiculo {

	private Double maxToneladas;
	private Double numToneladas;
	
	public CaminhaoBasculante(String marca, String modelo, Integer anoFabricacao, Double maxToneladas) {
		
		super(marca, modelo, anoFabricacao);
		this.maxToneladas = maxToneladas;
		this.numToneladas = 0.0;
	}

	public Double getMaxToneladas() {
		return maxToneladas;
	}

	public Double getNumToneladas() {
		return numToneladas;
	}

	@Override
	public void ligar() {
		
		if (!super.isLigado()) {
			super.setLigado(true);
			System.out.println("O Caminhão Basculante " + super.getMarca() + " de modelo " + super.getModelo() + " ligou.");
		}
		else
			System.out.println("O Caminhão Basculante " + super.getMarca() + " de modelo " + super.getModelo() + " já está ligado.");
	}

	@Override
	public void desligar() {

		if (super.isLigado()) {
			super.setLigado(false);
			System.out.println("O Caminhão Basculante " + super.getMarca() + " de modelo " + super.getModelo() + " desligou.");
		}
		else
			System.out.println("O Caminhão Basculante " + super.getMarca() + " de modelo " + super.getModelo() + " já está desligado.");
	}

	public void carregarCacamba(Double qntdToneladas) {
		
		if (this.maxToneladas >= (qntdToneladas+this.numToneladas))
			this.numToneladas += qntdToneladas;
		else
			this.numToneladas = this.maxToneladas;
	}
	
	private void descarregarCacamba() {
		
		this.numToneladas = 0.0;
		System.out.println("O Caminhão Basculante " + super.getMarca() + " de modelo " + super.getModelo() + " descarregou.");
	}
	
	@Override
	public void realizarTransporte() {
	
		if (super.isLigado()) {
			if (this.numToneladas >= 1) {
				System.out.println("O Caminhão Basculante " + super.getMarca() + " de modelo " + super.getModelo() + " realizou o transporte.");
				this.descarregarCacamba();
			}
			else
				System.out.println("O Caminhão Basculante " + super.getMarca() + " de modelo " + super.getModelo() + " não tem carga o suficiente para o transporte.");
		}
		else
			System.out.println("O Caminhão Basculante " + super.getMarca() + " de modelo " + super.getModelo() + " se encontra desligado.");
	}

}
