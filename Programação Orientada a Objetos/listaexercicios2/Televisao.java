package listaexercicios2;

public class Televisao {

	String marca;
	String resolucao;
	double polegadas;
	int canal = 15;
	int volume = 50;
	boolean ligado = false;
	
	public void ligar() {
		
		if(!ligado) {
			ligado = true;
			System.out.println(marca + " esta ligando");
		}
		else
			System.out.println(marca + " ja esta ligada");
	}
	
	public void desligar() {
		
		if(ligado) {
			ligado = false;
			System.out.println(marca + " esta desligando");
		}
		else
			System.out.println(marca + " ja esta desligada");
	}
	
	public void altCanalCima() {
		
		if(ligado) {
			if(canal > 0) {
				canal++;
				System.out.println(marca + " canal: " + canal);
			}
			else {
				canal = 50;
				System.out.println(marca + " canal: " + canal);
			}
		}
		else
			System.out.println(marca + " esta desligada");
	}
	
	public void altCanalBaixo() {
	
		if(ligado) {
			if(canal < 50) {
				canal--;
				System.out.println(marca + " canal: " + canal);
			}
			else {
				canal = 1;
				System.out.println(marca + " canal: " + canal);
			}
		}
		else
			System.out.println(marca + " esta desligada");
	}
	
	public void aumentarVolume() {
		
		if(ligado) {
			if(volume < 100) {
				volume++;
				System.out.println(marca + " volume: " + volume);
			}
			else 
				System.out.println(marca + " Volume Maximo");
		}
		else
			System.out.println(marca + " esta desligada");
	}
	
	public void abaixarVolume() {
		
		if(ligado) {
			if(volume > 0) {
				volume--;
				System.out.println(marca + " volume: " + volume);
			}
			else 
				System.out.println(marca + " Volume Minimo");
		}
		else
			System.out.println(marca + " esta desligada");
	}
	
	public void imprimirDados() {
		
		System.out.println("Marca: " + marca);
		System.out.println("Resolucao: " + resolucao);
		System.out.println("Polegadas: " + polegadas);
		System.out.println("Canal: " + canal);
		System.out.println("Volume: " + volume);
		System.out.println("Ligado: " + ligado);
	}
}
