package aula09;

public enum DiaSemana {

	DOMINGO(1, "domingo"),
	SEGUNDA(2, "segunda-feira"),
	TERCA(3, "terça-feira"),
	QUARTA(4, "quarta-feira"),
	QUINTA(5, "quinta-feira"),
	SEXTA(6, "sexta-feira"),
	SABADO(7, "sábado");
	
	private Integer dia;
	private String diaExtenso;
	
	private DiaSemana(Integer dia, String diaExtenso) {
		
		this.dia = dia;
		this.diaExtenso = diaExtenso;
	}

	public Integer getDia() {
		return dia;
	}

	public String getDiaExtenso() {
		return diaExtenso;
	}
}
