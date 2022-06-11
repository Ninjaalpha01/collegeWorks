package listaexercicios2;

public class TelevisaoTeste {

	public static void main(String[] args) {
		
		Televisao tv1 = new Televisao();
		
		tv1.marca = "Samsung";
		tv1.polegadas = 40;
		tv1.resolucao = "1920x1080";
		
		tv1.abaixarVolume();
		tv1.ligar();
		tv1.aumentarVolume();
		tv1.abaixarVolume();
		tv1.altCanalBaixo();
		tv1.altCanalCima();
		tv1.desligar();
		tv1.desligar();
		tv1.altCanalBaixo();
	}
}
