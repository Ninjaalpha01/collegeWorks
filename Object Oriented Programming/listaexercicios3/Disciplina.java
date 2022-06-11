package listaexercicios3;

import java.util.Scanner;

public class Disciplina {

	private Scanner testeMod = new Scanner(System.in);
	private int cargaHoraria;
	private String codigo;
	private String nome;
	private String modalidade;
	private String conteudoProgramatico;
	
	public Disciplina(String codigo, String nome, String modalidade, int cargaHoraria, String conteudoProgramatico) {
		
		this.codigo = codigo;
		this.nome = nome;
		this.cargaHoraria = cargaHoraria;
		this.conteudoProgramatico = conteudoProgramatico;
		
		modalidade = modalidade.toLowerCase();
		
		while (!(modalidade.equals("presencial") | modalidade.equals("a distancia"))) {
			System.out.println("Insira uma modalidade valida para a materia " + nome + "! (presencial ou a distancia)");
			modalidade = testeMod.nextLine();
			modalidade = modalidade.toLowerCase();
		}
		
		this.modalidade = modalidade;
	}
	
	public void imprimirDados() {
		
		System.out.println("Codigo: " + codigo);
		System.out.println("Materia: " + nome);
		System.out.println("Modalidade: " + modalidade);
		System.out.println("Carga Horaria: " + cargaHoraria);
		System.out.println("Conteudo Programatico: " + conteudoProgramatico);
	}
}
