package listaexercicios6;

public class Sala {

	private Integer id;
	private Integer capacidadeMax;
	
	public Sala(Integer id, Integer capacidadeMax) {
		
		this.id = id;
		this.capacidadeMax = capacidadeMax;
	}

	public Integer getId() {
		return id;
	}

	public void setId(Integer id) {
		this.id = id;
	}

	public Integer getCapacidadeMax() {
		return capacidadeMax;
	}

	public void setCapacidadeMax(Integer capacidadeMax) {
		this.capacidadeMax = capacidadeMax;
	}
}
