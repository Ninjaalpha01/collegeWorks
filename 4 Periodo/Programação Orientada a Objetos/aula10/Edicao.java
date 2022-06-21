package aula10;

public class Edicao {

	private Integer numero;
	private Integer volume;
	private String data;
	private Artigo artigo[];
	private Integer count;
	
	Edicao(Integer numero, Integer volume, String data){
		
		this.numero = numero;
		this.volume = volume;
		this.data = data;
		this.count = 0;
		this.artigo = new Artigo[10];
	}
	
	public Integer getNumero() {
		return numero;
	}

	public void setNumero(Integer numero) {
		this.numero = numero;
	}

	public Integer getVolume() {
		return volume;
	}

	public void setVolume(Integer volume) {
		this.volume = volume;
	}

	public String getData() {
		return data;
	}

	public void setData(String data) {
		this.data = data;
	}

	public void setArtigo(Artigo artigo) {
		this.artigo[count++] = artigo;
	}
	
	public void imprimirArtigos() {
		
		System.out.println("Artigos:");
		
		for(int i=0; i<this.count; i++)
			System.out.println(this.artigo[i].getNome());
	}
}
