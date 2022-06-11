package listaexercicios5;

public class ImovelTeste {

	public static void main(String[] args) {
		
		ImovelVelho imov1 = new ImovelVelho(100000.0, "Cu de Judas", 25000.0);
		
		imov1.imprimirDados();
		
		System.out.println("==============================");
		
		ImovelNovo imov2 = new ImovelNovo(100000.0, "Rampa para céu", 30000.0);
		
		imov2.imprimirDados();
	}
}
