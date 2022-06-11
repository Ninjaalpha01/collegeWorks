package aula11;

public class Laser extends Impressora {

	public Laser(String marca, String modelo) {
		super(marca, modelo);
	}

	public void imprimir() {
		System.out.println("Impressora Laser está imprimindo.");
	}
}
