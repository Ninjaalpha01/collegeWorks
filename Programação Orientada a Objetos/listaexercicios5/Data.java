package listaexercicios5;

public class Data {

	protected Integer dia;
	protected Integer mes;
	protected Integer ano;
	
	public Data(Integer dia, Integer mes, Integer ano) {
		
		this.dia = dia;
		this.mes = mes;
		this.ano = ano;
	}
	
	public Data(Integer mes, Integer ano) {
		this(1, mes, ano);
	}
	
	public Data(Integer dia) {
		this(dia, 1, 2019);
	}
	
	public Data() {
		this(1, 1, 2019);
	}

	@Override
	public String toString() {
		return dia + "/" + mes + "/" + ano;
	}
}
