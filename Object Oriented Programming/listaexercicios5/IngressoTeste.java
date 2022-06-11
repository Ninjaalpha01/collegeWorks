package listaexercicios5;

public class IngressoTeste {

	public static void main(String[] args) {
		
		IngressoNormal ingNorm = new IngressoNormal(250.0, "Pista");
		CamaroteSuperior camSup = new CamaroteSuperior(400.0, "Camarote", 75.0, "Superior");
		CamaroteInferior camInf = new CamaroteInferior(400.0, "Camarote", 25.0, "Inferior");
		
		camSup.calcularValorIngressoVip();
		camInf.calcularValorIngressoVip();
		
		ingNorm.imprimirDadosIngresso();
		System.out.println("===============");
		camSup.imprimirDadosIngresso();
		System.out.println("===============");
		camInf.imprimirDadosIngresso();
	}
}
