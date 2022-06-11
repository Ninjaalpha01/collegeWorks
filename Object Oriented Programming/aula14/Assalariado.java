package aula14;

public class Assalariado extends Funcionario {

	private Double adicional;
	
	public Assalariado(String nome, Long cpf, Double salarioBase, Double adicional) {
		
		super(nome, cpf, salarioBase);
		this.adicional = adicional;
	}
	
	public Double getAdicional() {
		return adicional;
	}

	public void setAdicional(Double adicional) {
		this.adicional = adicional;
	}

	@Override
	public Double calcularSalario() {
		return super.getSalarioBase()+this.getAdicional();
	}

	@Override
	public String toString() {
		return "Assalariado [adicional=" + adicional + "]";
	}
}
