package gabrielleonardo;

public class Testes {

	public static void main(String[] args) {
		
		Onibus oni = new Onibus("Mercedes", "Escolar", 2018, 40);
		
		oni.ligar();
		oni.realizarTransporte();
		oni.inserirPassageiros(50);
		oni.realizarTransporte();
		oni.retirarPassageiros(15);
		oni.realizarTransporte();
		oni.desligar();
		oni.desligar();
		
		CaminhaoBasculante cam = new CaminhaoBasculante("Scania", "Branco", 2020, 20.0);
		
		cam.ligar();
		cam.realizarTransporte();
		cam.carregarCacamba(0.5);
		System.out.println(cam.getNumToneladas());
		cam.carregarCacamba(21.0);
		System.out.println(cam.getNumToneladas());
		cam.realizarTransporte();
		System.out.println(cam.getNumToneladas());
		cam.desligar();
		cam.desligar();
	}
}
