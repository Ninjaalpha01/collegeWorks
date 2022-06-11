package listaexercicios4;

public class DisciplinaTeste {

	public static void main(String[] args) {
		
		Professor prof = new Professor(20, "Vinicius de Andrade", "23/08/1996", 3560.90);
		Disciplina materia = new Disciplina("Programação Orientada a Objetos", 60, prof);
		
		materia.imprimirRelatorio();
	}
}
