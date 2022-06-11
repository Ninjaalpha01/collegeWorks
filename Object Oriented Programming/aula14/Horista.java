package aula14;

public class Horista extends Funcionario {

	private Double precoHora;
	private Integer horasTrabalhadas;
	
	public Horista(String nome, Long cpf, Double salarioBase, Double precoHora, Integer horasTrabalhadas) {
	
		super(nome, cpf, salarioBase);
		this.precoHora = precoHora;
		this.horasTrabalhadas = horasTrabalhadas;
	}

	public Double getPrecoHora() {
		return precoHora;
	}

	public void setPrecoHora(Double precoHora) {
		this.precoHora = precoHora;
	}

	public Integer getHorasTrabalhadas() {
		return horasTrabalhadas;
	}

	public void setHorasTrabalhadas(Integer horasTrabalhadas) {
		this.horasTrabalhadas = horasTrabalhadas;
	}
	
	@Override
	public Double calcularSalario() {
		
		return super.getSalarioBase() + (this.getPrecoHora() * this.getHorasTrabalhadas());
	}

	@Override
	public String toString() {
		return "Horista [precoHora=" + precoHora + ", horasTrabalhadas=" + horasTrabalhadas + "]";
	}
}
