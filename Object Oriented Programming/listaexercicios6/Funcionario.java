package listaexercicios6;

public abstract class Funcionario {

	protected Integer registro;
	protected String nome;
	protected String dataAdmissao;
	protected Double salarioBase;
	protected Double salarioTotal;
	
	public Funcionario(Integer registro, String nome, String dataAdmissao, Double salarioBase) {
	
		this.registro = registro;
		this.nome = nome;
		this.dataAdmissao = dataAdmissao;
		this.salarioBase = salarioBase;
	}
	
	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}
	public String getDataAdmissao() {
		return dataAdmissao;
	}

	public void setDataAdmissao(String dataAdmissao) {
		this.dataAdmissao = dataAdmissao;
	}

	public Double getSalarioBase() {
		return salarioBase;
	}

	public void setSalarioBase(Double salarioBase) {
		this.salarioBase = salarioBase;
	}

	public Integer getRegistro() {
		return registro;
	}

	public Double getSalarioTotal() {
		return salarioTotal;
	}

	public abstract void calcularSalario();
	
	public abstract void exibirRelatorio();
	
	public void imprimirGen() {
		
		this.calcularSalario();
		System.out.println("Registro: " + this.getRegistro());
		System.out.println("Nome: " + this.getNome());
		System.out.println("Data de Admissão: " + this.getDataAdmissao());
		System.out.printf("Salario: R$%.2f\n", this.getSalarioTotal());
	}
}
