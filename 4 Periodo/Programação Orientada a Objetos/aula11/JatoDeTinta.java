package aula11;

public class JatoDeTinta extends Impressora {

	public JatoDeTinta(String marca, String modelo) {
		super(marca, modelo);
	}

	public void imprimir() {
		System.out.println("Jato de Tinta está imprimindo.");
	}
}
