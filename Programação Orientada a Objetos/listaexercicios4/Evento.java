package listaexercicios4;

import java.util.Scanner;

public class Evento {

	private String nomeEvento;
	private Artista artista;
	private String data;
	private Local local;
	private Integer classificacaoEtaria;
	private Integer ingressos;
	private Scanner entrada = new Scanner(System.in);
	
	public Evento(String nomeEvento, Artista artista, String data, Local local, Integer classificacaoEtaria) {
		
		this.nomeEvento = nomeEvento;
		this.artista = artista;
		this.data = data;
		this.local = local;
		this.classificacaoEtaria = classificacaoEtaria;
		this.ingressos = local.getCapacidadeMax();
	}

	public void venderIngressos() {
		
		int qntd;
		System.out.println("Quantos deseja comprar?");
		qntd = entrada.nextInt();
		
		if ((this.ingressos-qntd) > 0) 
		{
			this.ingressos -= qntd;
			System.out.println("Venda efetuada");
		}
		else
			System.out.println("Não temos tantos ingressos disponíveis.");
		
		System.out.println("Ingressos restantes: " + this.ingressos);
		this.entrada.close();
	}
}
