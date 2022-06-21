package listaexercicios3;

public class CarroTeste {

	public static void main(String[] args) {
		
		Carro c1 = new Carro("Carro 1");
		int i;
		
		System.out.println(c1.getNomeCarro());
		
		for(i=0; i < 14; i++) {
			System.out.println("Velocidade: " + c1.getVelocidade() + "Km/h");
			System.out.println("Marcha: " + c1.getMarcha());
			c1.acelerar();
			c1.acelerar();
		}
		
		System.out.println("===============================");
		
		for(i=0; i < 14; i++) {
			System.out.println("Velocidade: " + c1.getVelocidade() + "Km/h");
			System.out.println("Marcha: " + c1.getMarcha());
			c1.frear();
			c1.frear();
		}
	} 
}
