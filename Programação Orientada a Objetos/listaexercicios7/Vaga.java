package listaexercicios7;

public class Vaga {

	private Integer numId;
	private Veiculo veiculo;
	private Integer horaInicial;
	private Integer horaFinal;
	
	public Vaga(Integer numId) {
	
		this.numId = numId;
	}
	
	public Integer getNumId() {
		return numId;
	}

	public Veiculo getVeiculo() {
		return veiculo;
	}

	public Integer getHoraInicial() {
		return horaInicial;
	}

	public Integer getHoraFinal() {
		return horaFinal;
	}
	
	public void setHoraInicial(Integer horaInicial) {
		this.horaInicial = horaInicial;
	}
	
	public void setHoraFinal(Integer horaFinal) {
		this.horaFinal = horaFinal;
	}

	public void addVeiculo(Veiculo veiculo, Integer hora) {
		
		if (this.veiculo == null) {
			this.veiculo = veiculo;
			this.horaInicial = hora;
		}
		else
			System.err.println("Não é possível estacionar, já há um carro na vaga!");
	}
	
	public void retirarVeiculo(Integer hora) {
		this.veiculo = null;
		this.horaFinal = hora;
	}
}
