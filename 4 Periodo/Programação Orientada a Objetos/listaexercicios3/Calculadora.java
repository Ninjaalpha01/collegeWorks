package listaexercicios3;

public class Calculadora {

	private String marca;
	private String modelo;
	private String tipo;
	private int memoria;
	
	public Calculadora(String marca, String modelo, String tipo, int memoria) {
		super();
		this.marca = marca;
		this.modelo = modelo;
		this.tipo = tipo;
		this.memoria = memoria;
	}
	
	public void somar(double x, double y) {
		System.out.printf("%.2f + %.2f = %.2f\n", x, y, (x+y));
	}

	public void subtrair(double x, double y) {
		System.out.printf("%.2f - %.2f = %.2f\n", x, y, (x-y));
	}
	
	public void multiplicar(double x, double y) {
		System.out.printf("%.2f * %.2f = %.2f\n", x, y, (x*y));
	}
	
	public void dividir(double x, double y) {
		System.out.printf("%.2f / %.2f = %.2f\n", x, y, (x/y));
	}
	
	public String getMarca() {
		return marca;
	}

	public String getModelo() {
		return modelo;
	}

	public String getTipo() {
		return tipo;
	}

	public int getMemoria() {
		return memoria;
	}

	@Override
	public String toString() {
		return "Calculadora [marca=" + marca + ", modelo=" + modelo + ", tipo=" + tipo + ", memoria=" + memoria + "]";
	}
}
