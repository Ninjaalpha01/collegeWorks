package listaexercicios2;

public class Notebook {

	String marca;
	String modelo;
	String tela;
	String processador;
	int ram;
	int armazenamento;
	
	public void ligar() {
		
		System.out.println("O modelo " + modelo + " esta ligando");
	}
	
	public void desligar() {
		
		System.out.println("O modelo " + modelo + " esta desligando");
	}
	
	public void processarInformacoes() {
		
		System.out.println("O modelo " + modelo + " esta processando informacoes");
	}
	
	public void conectarInternet() {
	
		System.out.println("O modelo " + modelo + " esta conectando a internet");
	}
}
