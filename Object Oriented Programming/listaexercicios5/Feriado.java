package listaexercicios5;

public class Feriado extends Data {

	private String descricao;
	
	public Feriado(Integer dia, Integer mes, Integer ano, String descricao) {
		
		super(dia, mes, ano);
		this.descricao = descricao;
	}
	
	public Feriado(String descricao) {
		
		super();
		this.descricao = descricao;
	}
	
	public Feriado() {
		
		super();
		this.descricao = "Feriado";
	}

	@Override
	public String toString() {
		return super.toString() + " - " + descricao;
	}
}
