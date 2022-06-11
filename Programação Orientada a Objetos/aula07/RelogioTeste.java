package aula07;

public class RelogioTeste {

	public static void main(String[] args) {

		Relogio r1 = new Relogio("Philips", 11, 59);
		Relogio r2 = new Relogio("Xiaomi", 12, 40);
		
		System.out.println("Relogio: " + r1.getMarca());
		System.out.println("Tempo: " + r1.getHora() + ":" + r1.getMinutos());
		
		System.out.println("Relogio: " + r2.getMarca());
		System.out.println("Tempo: " + r2.getHora() + ":" + r2.getMinutos());
		
		r1.setHora(23);
		r1.setMinutos(22);
		
		System.out.println("Relogio: " + r1.getMarca());
		System.out.println("Tempo: " + r1.getHora() + ":" + r1.getMinutos());
	}
}
