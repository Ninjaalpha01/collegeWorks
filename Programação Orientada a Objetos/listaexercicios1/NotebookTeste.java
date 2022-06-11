package listaexercicios1;

public class NotebookTeste {

	public static void main(String[] args) {
		
		Notebook note1 = new Notebook();
		Notebook note2 = new Notebook();
		Notebook note3 = new Notebook();
		
		note1.marca = "Positivo";
		note1.modelo = "P2324";
		note1.tela = 14.2;
		note1.processador = "Intel";
		note1.ram = 8;
		note1.armazenamento = 512;
		
		note2.marca = "Asus";
		note2.modelo = "A9305";
		note2.tela = 17;
		note2.processador = "Ryzen";
		note2.ram = 16;
		note2.armazenamento = 1024;
		
		note3.marca = "Apple";
		note3.modelo = "MAC32";
		note3.tela = 16.4;
		note3.processador = "MC2091";
		note3.ram = 12;
		note3.armazenamento = 1024;
		
		System.out.println("Notebooks:");
		System.out.println("Marca: " + note1.marca);
		System.out.println("Modelo: " + note1.modelo);
		System.out.println("Tamanho da tela: " + note1.tela + "\"");
		System.out.println("Modelo do Processador: " + note1.processador);
		System.out.println("Quantidade memória RAM: " + note1.ram + " GB");
		System.out.println("Quantidade de Armazenamento: " + note1.armazenamento + " GB");
		
		System.out.println("==============");
		System.out.println("Marca: " + note2.marca);
		System.out.println("Modelo: " + note2.modelo);
		System.out.println("Tamanho da tela: " + note2.tela + "\"");
		System.out.println("Modelo do Processador: " + note2.processador);
		System.out.println("Quantidade memória RAM: " + note2.ram + " GB");
		System.out.println("Quantidade de Armazenamento: " + note2.armazenamento + " GB");
		
		System.out.println("==============");
		System.out.println("Marca: " + note3.marca);
		System.out.println("Modelo: " + note3.modelo);
		System.out.println("Tamanho da tela: " + note3.tela + "\"");
		System.out.println("Modelo do Processador: " + note3.processador);
		System.out.println("Quantidade memória RAM: " + note3.ram + " GB");
		System.out.println("Quantidade de Armazenamento: " + note3.armazenamento + " GB");
		
	}
}
