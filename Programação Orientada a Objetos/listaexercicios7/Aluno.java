package listaexercicios7;

import java.util.ArrayList;
import java.util.List;

public class Aluno {

	private String nome;
	private String ra;
	private List<Double> notas;
	private Double media;
	
	public Aluno(String nome, String ra) {
		
		this.nome = nome;
		this.ra = ra;
		this.notas = new ArrayList<Double>();
		this.media = 0.0;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getRa() {
		return ra;
	}

	public List<Double> getNotas() {
		return notas;
	}
	
	public Double getMedia() {
		return media;
	}
	
	public void setMedia(Double media) {
		this.media = media;
	}
	
	public void addNota(Double nota) {
		notas.add(nota);
	}
	
//	public void imprimirNotas() {
//		
//		for (int i = 0; i < 4; i++)
//			System.out.println("Prova " + i + ": " + this.notas.get(i));
//	}
}
