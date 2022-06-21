package aula05;

public class Carro {

	String modelo;
	String marca;
	String placa;
	String cor;
	int ano;
	int velocidadeAtual = 0;
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
		
		if (ligado && velocidadeAtual == 0) {
			System.out.println(marca + " " + modelo + " está desligando");
			ligado = false;
		}
		else {
			System.out.println(marca + " " + modelo + " encontra-se desligado ou andando");
		}
	}
	
	public void acelerar(int velocidade) {
		
		if (ligado) {
			velocidadeAtual += velocidade;
			System.out.println(marca + " " + modelo + " está acelerando. Velocidade: " + velocidadeAtual + "Km/h");
		}
		else {
			System.out.println(marca + " " + modelo + " encontra-se desligado");
		}
	}
	
	public void frear(int velocidade) {
		
		if (ligado && velocidadeAtual > 0) {
			velocidadeAtual -= velocidade;
			System.out.println(marca + " " + modelo + " está freando. Velocidade: " + velocidadeAtual + "Km/h");
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
		System.out.println("Velocidade: " + velocidadeAtual + "Km/h");
		System.out.println("Ligado: " + ligado);
	}
	
	@Override
	public String toString() {
		return "Carro [modelo=" + modelo + ", marca=" + marca + ", placa=" + placa + ", cor=" + cor + ", ano=" + ano
				+ ", velocidade=" + velocidadeAtual + ", ligado=" + ligado + "]";
	}
}