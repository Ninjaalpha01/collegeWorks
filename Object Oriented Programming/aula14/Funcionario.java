package aula14;

public abstract class Funcionario {

	protected String nome;
	protected Long cpf;
	protected Double salarioBase;
	
	public Funcionario(String nome, Long cpf, Double salarioBase) {
		
		this.nome = nome;
		this.cpf = cpf;
		this.salarioBase = salarioBase;
	}
	
	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public Double getSalarioBase() {
		return salarioBase;
	}

	public void setSalarioBase(Double salarioBase) {
		this.salarioBase = salarioBase;
	}

	public Long getCpf() {
		return cpf;
	}

	public abstract Double calcularSalario();

	@Override
	public String toString() {
		return "Funcionario [nome=" + nome + ", cpf=" + cpf + ", salarioBase=" + salarioBase + "]";
	}
}
