package listaexercicios2;

public class Carro {

	String modelo;
	String marca;
	String placa;
	String cor;
	int ano;
	
	public void ligar() {
		
		System.out.println(marca + " " + modelo + " está ligando");
	}
	
	public void desligar() {
		
		System.out.println(marca + " " + modelo + " está desligando");
	}
	
	public void acelerar() {
		
		System.out.println(marca + " " + modelo + " está acelerando");
	}
	
	public void frear() {
		
		System.out.println(marca + " " + modelo + " está freando");
	}
	
	@Override
	public String toString() {
		return "Carro [modelo=" + modelo + ", marca=" + marca + ", placa=" + placa + ", cor=" + cor + ", ano=" + ano
				+ "]";
	}
}