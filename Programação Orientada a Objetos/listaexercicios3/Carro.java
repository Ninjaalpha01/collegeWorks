package listaexercicios3;

public class Carro {

	private String nomeCarro;
	private String[] marcha = {"Neutro", "1a marcha", "2a marcha",
	                         "3a marcha", "4a marcha", "5a marcha"};
	private int engate = 0;
	private int velocidade = 0;
	
	public Carro(String nomeCarro) {
		this.nomeCarro = nomeCarro;
	}
	
	public void acelerar() {
		
		if (velocidade < 130)
			velocidade += 5;
		else
			System.out.println("Velocidade maxima atingida.");
		
		marcha();
	}
	
	public void frear() {
		
		if (velocidade > 0)
			velocidade -= 5;
		else
			System.out.println("Carro parado.");
		
		marcha();
	}
	
	private void marcha() {
		

		if (velocidade == 0)
			engate = 0;

		if (velocidade >= 1 & velocidade < 20)
			engate = 1;
		else {
			if (velocidade >= 20 & velocidade < 40)
				engate = 2;
			else {
				if (velocidade >= 40 & velocidade < 60)
					engate = 3;
				else {
					if (velocidade >= 60 & velocidade < 90)
						engate = 4;
					else {
						if (velocidade >= 90 & velocidade <= 130)
							engate = 5;
					}
				}
			}
		}
	}

	public String getNomeCarro() {
		return nomeCarro;
	}
	
	public String getMarcha() {
		return marcha[engate];
	}

	public int getEngate() {
		return engate;
	}

	public int getVelocidade() {
		return velocidade;
	}
}
