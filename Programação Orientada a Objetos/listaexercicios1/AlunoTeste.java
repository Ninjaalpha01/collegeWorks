package listaexercicios1;

public class AlunoTeste {

	public static void main(String[] args) {
		
		Aluno a1 = new Aluno();
		Aluno a2 = new Aluno();
		Aluno a3 = new Aluno();
		
		a1.ra = 2317940;
		a1.nome = "Gabriel Leonardo";
		a1.curso = "Ciência da Computação";
		a1.turno = "Integral";
		a1.periodo = 4;
		a1.coeficiente = 0.86;
		a1.situacao = "Regular";
		
		a2.ra = 2290832;
		a2.nome = "Thais Boschini";
		a2.curso = "Engenharia de Produção";
		a2.turno = "Integral";
		a2.periodo = 4;
		a2.coeficiente = 0.83;
		a2.situacao = "Regular";
		
		a3.ra = 2378032;
		a3.nome = "Giovana Oliveira";
		a3.curso = "Análise e Desenvolvimento de Software";
		a3.turno = "Noturno";
		a3.periodo = 5;
		a3.coeficiente = 0.90;
		a3.situacao = "Retido no 5° Período";
		
		System.out.println("Alunos:");
		System.out.println("RA: " + a1.ra);
		System.out.println("Nome: " + a1.nome);
		System.out.println("Curso: " + a1.curso);
		System.out.println("Turno: " + a1.turno);
		System.out.println("Período: " + a1.periodo);
		System.out.println("Coeficiente: " + a1.coeficiente);
		System.out.println("Situação: " + a1.situacao);
		
		System.out.println("=============");
		System.out.println("RA: " + a2.ra);
		System.out.println("Nome: " + a2.nome);
		System.out.println("Curso: " + a2.curso);
		System.out.println("Turno: " + a2.turno);
		System.out.println("Período: " + a2.periodo);
		System.out.println("Coeficiente: " + a2.coeficiente);
		System.out.println("Situação: " + a2.situacao);
		
		System.out.println("=============");
		System.out.println("RA: " + a3.ra);
		System.out.println("Nome: " + a3.nome);
		System.out.println("Curso: " + a3.curso);
		System.out.println("Turno: " + a3.turno);
		System.out.println("Período: " + a3.periodo);
		System.out.println("Coeficiente: " + a3.coeficiente);
		System.out.println("Situação: " + a3.situacao);
	}
}
