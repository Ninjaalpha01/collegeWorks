package listaexercicios4;

public class AnimalTeste {

	public static void main(String[] args) {
		
		Endereco end = new Endereco(183, "Av. P33", "Nova Russia", "Ponta Grossa");
		Dono dono = new Dono("Ricardo", "232100342-01", "993943285", end);
		Animal animal1 = new Animal("Fluffy", "Macho", 3, dono);
		
		animal1.imprimirDados();
	}
}
