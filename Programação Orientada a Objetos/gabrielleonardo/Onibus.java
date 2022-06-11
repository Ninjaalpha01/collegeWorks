package gabrielleonardo;

public class Onibus extends Veiculo {

	private Integer maxPassageiros;
	private Integer numPassageiros;
	
	public Onibus(String marca, String modelo, Integer anoFabricacao, Integer maxPassageiros) {
	
		super(marca, modelo, anoFabricacao);
		this.maxPassageiros = maxPassageiros;
		this.numPassageiros = 0;
	}

	public Integer getNumPassageiros() {
		return numPassageiros;
	}

	public Integer getMaxPassageiros() {
		return maxPassageiros;
	}

	public void setMaxPassageiros(Integer maxPassageiros) {
		this.maxPassageiros = maxPassageiros;
	}

	@Override
	public void ligar() {
		
		if (!super.isLigado()) {
			super.setLigado(true);
			System.out.println("O Onibus " + super.getMarca() + " de modelo " + super.getModelo() + " ligou.");
		}
		else
			System.out.println("O Onibus " + super.getMarca() + " de modelo " + super.getModelo() + " já está ligado.");
	}

	@Override
	public void desligar() {

		if (super.isLigado()) {
			super.setLigado(false);
			System.out.println("O Onibus " + super.getMarca() + " de modelo " + super.getModelo() + " desligou.");
		}
		else
			System.out.println("O Onibus " + super.getMarca() + " de modelo " + super.getModelo() + " já está desligado.");
	}

	public void inserirPassageiros(int qntdPassageiros) {
		
		this.numPassageiros += qntdPassageiros;
	}
	
	public void retirarPassageiros(int qntdPassageiros) {
		
		if (this.numPassageiros >= qntdPassageiros)
			this.numPassageiros -= qntdPassageiros;
		else
			this.numPassageiros = 0;
	}
	
	@Override
	public void realizarTransporte() {
	
		if (super.isLigado()) {
			if (this.numPassageiros > 0) {
				if (this.numPassageiros <= this.maxPassageiros)
					System.out.println("O Onibus " + super.getMarca() + " de modelo " + super.getModelo() + " realizou o transporte.");
				else
					System.out.println("O Onibus " + super.getMarca() + " de modelo " + super.getModelo() + " excedeu sua capacidade máxima.");
			}
			else
				System.out.println("O Onibus " + super.getMarca() + " de modelo " + super.getModelo() + " não tem nenhum passageiro em seu interior.");
		}
		else
			System.out.println("O Onibus " + super.getMarca() + " de modelo " + super.getModelo() + " se encontra desligado.");
	}
}
