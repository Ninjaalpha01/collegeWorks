package listaexercicios4;

public class Local {

	private String nomeLocal;
	private Endereco endereco;
	private Integer capacidadeMax;
	
	public Local(String nomeLocal, Endereco endereco, Integer capacidadeMax) {
		
		this.nomeLocal = nomeLocal;
		this.endereco = endereco;
		this.capacidadeMax = capacidadeMax;
	}
	
	public String getNomeLocal() {
		return nomeLocal;
	}
	
	public Integer getCapacidadeMax() {
		return capacidadeMax;
	}
	
	
}
