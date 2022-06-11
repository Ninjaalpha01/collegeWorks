package aula10;

public class RevistaCientifica {

	private String titulo;
	private String periodicidade;
	private Integer issn;
	private Edicao edicao[];
	private Integer count;
	
	RevistaCientifica (String titulo, String periodicidade, Integer issn){
		
		this.titulo = titulo;
		this.periodicidade = periodicidade;
		this.issn = issn;
		this.count = 0;
		this.edicao = new Edicao[5];
	}
	
	public String getTitulo() {
		return titulo;
	}

	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}

	public Integer getIssn() {
		return issn;
	}

	public void setIssn(Integer issn) {
		this.issn = issn;
	}

	public Edicao[] getEdicao() {
		return edicao;
	}

	public String getPeriodicidade() {
		return periodicidade;
	}

	public void setEdicao(Edicao edicao) {
		this.edicao[count++] = edicao;
	}
	
	public void setPeriodicidade(String periodicidade) {
		this.periodicidade = periodicidade;
	}
	
	public void imprimirDados() {
		
		System.out.println("Título: " + this.titulo);
		System.out.println("Periodicidade: " + this.periodicidade);
		System.out.println("ISSN: " + this.issn);
		System.out.println("------------");
		System.out.println("Ediçôes: \n");
		
		for(int i=0; i < this.count; i++)
		{
			System.out.println("Numero: " + this.edicao[i].getNumero());
			System.out.println("Volume: " + this.edicao[i].getVolume());
			System.out.println("Data: " + this.edicao[i].getData());
			this.edicao[i].imprimirArtigos();
			System.out.println("===================");
		}
	}
}
