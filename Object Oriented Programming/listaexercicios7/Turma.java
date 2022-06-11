package listaexercicios7;

import java.util.ArrayList;
import java.util.List;

public class Turma {

	private List<Aluno> classe;
	private String nomeTurma;
	
	public Turma(String nomeTurma) {
		
		this.nomeTurma = nomeTurma;
		this.classe = new ArrayList<Aluno>();
	}
	
	public String getNomeTurma() {
		return nomeTurma;
	}

	public void addAluno(Aluno aluno) {
		
		this.classe.add(aluno);
		System.out.println("Aluno " + aluno.getNome() + " adicionado.\n");
	}
	
	public void addClasse(List<Aluno> classe) {
		
		this.classe = classe;
		System.out.println("Classe adicionada.\n");
	}
	
	public Aluno buscarAluno(String nome) {
			
		nome = nome.toLowerCase();
		
		for (Aluno aluno : classe) {
			if (aluno.getNome().toLowerCase().equals(nome))
				return aluno;
		}
		System.out.println("Aluno não encontrado.\n");
		return null;
	}
	
	public void calcularMedAluno(String nome) {
		
		Aluno aluno = this.buscarAluno(nome);
		List<Double> notas = new ArrayList<Double>();
		Double media = 0.0;
		
		if (aluno == null)
			return;
		
		notas = aluno.getNotas();
		
		for (int i = 0; i < notas.size(); i++)
			media += notas.get(i);
		
		media /= notas.size();
		aluno.setMedia(media);
		
		if (media >= 6.0)
			System.out.printf("Nota: %.2f | Aprovado\n", media);
		else
			System.out.printf("Nota: %.2f | Reprovado\n", media);
	}
	
	public void calcularMedTurma() {
		
		Double mediaTurma = 0.0;
		
		for (Aluno aluno : classe) {
			mediaTurma += aluno.getMedia();
		}
		
		mediaTurma /= classe.size();
		
		System.out.println("\nTurma: " + this.nomeTurma);
		System.out.println("Media Geral: " + mediaTurma);
		
		for (Aluno aluno : classe) {
			System.out.print("Aluno: " + aluno.getNome());
			System.out.printf(" | Media: %.2f\n", aluno.getMedia());
		}
	}
}
