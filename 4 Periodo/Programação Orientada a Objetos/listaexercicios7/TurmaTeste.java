package listaexercicios7;

import java.util.ArrayList;
import java.util.List;

public class TurmaTeste {

	public static void main(String[] args) {
		
		Aluno alu1 = new Aluno("Gabriel", "2317940");
		Aluno alu2 = new Aluno("Eduardo", "2348654");
		Aluno alu3 = new Aluno("Lukas", "2365489");
		Aluno alu4 = new Aluno("Guilherme", "2259841");
		Aluno alu5 = new Aluno("Matheus", "2178662");
		
		List<Aluno> classe = new ArrayList<Aluno>();
		
		classe.add(alu1);
		classe.add(alu2);
		classe.add(alu3);
		classe.add(alu4);
		
		Turma turma = new Turma("CC54D");
		turma.addClasse(classe);
		turma.addAluno(alu5);
		
		alu1.addNota(10.0);
		alu1.addNota(9.98);
		alu1.addNota(10.0);
		alu1.addNota(9.5);
		
		alu2.addNota(10.0);
		alu2.addNota(7.5);
		alu2.addNota(4.0);
		alu2.addNota(3.0);
		
		alu3.addNota(10.0);
		alu3.addNota(9.8);
		alu3.addNota(8.5);
		alu3.addNota(9.0);

		alu4.addNota(10.0);
		alu4.addNota(1.5);
		alu4.addNota(3.5);
		alu4.addNota(2.0);
		
		alu5.addNota(10.0);
		alu5.addNota(10.0);
		alu5.addNota(10.0);
		alu5.addNota(10.0);
		System.out.println();
		
		turma.calcularMedAluno("gabriel");
		turma.calcularMedAluno("eduardo");
		turma.calcularMedAluno("lukas");
		turma.calcularMedAluno("guilherme");
		turma.calcularMedAluno("MATHEUS");
		
		turma.calcularMedTurma();
	}
}
