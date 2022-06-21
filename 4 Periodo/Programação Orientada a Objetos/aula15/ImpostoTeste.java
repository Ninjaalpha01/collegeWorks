package aula15;

public class ImpostoTeste {

	public static void main(String[] args) {
		
		Imposto imp = new Imposto(300.0, new INSS());
		
		imp.calcularImposto();
	}
}
