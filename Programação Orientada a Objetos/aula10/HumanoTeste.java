package aula10;

public class HumanoTeste {

	public static void main(String[] args) {
		
		Professor prof = new Professor("Cláudio", 29, "Av P214", 3500.0);
		Aluno aluno = new Aluno("Adalberto", 20, "Deco Gomes", "Ciência da Computação");
		
		prof.calcularSalario();
		aluno.realizarMatricula();
	}
}
