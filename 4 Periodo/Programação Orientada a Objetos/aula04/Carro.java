package aula04;

public class Carro {

	String modelo;
	String marca;
	String placa;
	String cor;
	int ano;
	int velocidade = 0;
	boolean ligado = false;
	
	public void ligar() {
		
		if (!ligado) {
			System.out.println(marca + " " + modelo + " está ligando");
			ligado = true;
		}
		else {
			System.out.println(marca + " " + modelo + " já está ligado");
		}
	}
	
	public void desligar() {
		
		if (ligado && velocidade == 0) {
			System.out.println(marca + " " + modelo + " está desligando");
			ligado = false;
		}
		else {
			System.out.println(marca + " " + modelo + " encontra-se desligado ou andando");
		}
	}
	
	public void acelerar() {
		
		if (ligado) {
			velocidade += 10;
			System.out.println(marca + " " + modelo + " está acelerando. Velocidade: " + velocidade + "Km/h");
		}
		else {
			System.out.println(marca + " " + modelo + " encontra-se desligado");
		}
	}
	
	public void frear() {
		
		if (ligado && velocidade > 0) {
			velocidade -= 10;
			System.out.println(marca + " " + modelo + " está freando. Velocidade: " + velocidade + "Km/h");
		}
		else {
			System.out.println(marca + " " + modelo + " encontra-se desligado ou parado");
		}
	}
	
	//relatório para usuário
	public void imprimirDados() {
		
		System.out.println("Modelo: " + modelo);
		System.out.println("Marca: " + marca);
		System.out.println("Ano: " + ano);
		System.out.println("Placa: " + placa);
		System.out.println("Cor: " + cor);
		System.out.println("Velocidade: " + velocidade + "Km/h");
		System.out.println("Ligado: " + ligado);
	}
	
	@Override
	public String toString() {
		return "Carro [modelo=" + modelo + ", marca=" + marca + ", placa=" + placa + ", cor=" + cor + ", ano=" + ano
				+ ", velocidade=" + velocidade + ", ligado=" + ligado + "]";
	}
}