package listaexercicios2;

public class NotebookTeste {

	public static void main(String[] args) {
		
		Notebook note1 = new Notebook();
		Notebook note2 = new Notebook();
		
		note1.marca = "Lenovo";
		note1.modelo = "L2393";
		note1.processador = "AMD9203";
		note1.ram = 8;
		note1.armazenamento = 512;
		
		note2.marca = "Asus";
		note2.modelo = "A3920";
		note2.processador = "Ryzen-7";
		note2.ram = 16;
		note2.armazenamento = 1024;
		
		note1.ligar();
		note1.processarInformacoes();
		note2.conectarInternet();
		note2.desligar();
	}
}
