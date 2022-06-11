package listaexercicios5;

public class Funcionario extends Colaborador {

	protected String funcao;
	protected double salario;
	
	public Funcionario(String nome, String endereco, String dataInicio, String funcao, double salario) {
		
		super(nome, endereco, dataInicio);
		this.funcao = funcao;
		this.salario = salario;
	}

	public String getFuncao() {
		return funcao;
	}

	public void setFuncao(String funcao) {
		this.funcao = funcao;
	}

	public double getSalario() {
		return salario;
	}

	public void setSalario(Double salario) {
		this.salario = salario;
	}

	@Override
	public String toString() {
		return "Funcionario [funcao=" + funcao + ", salario=" + salario + "]";
	}
	
	public void imprimirDados() {
		
		super.imprimirDados();
		System.out.println("-----Funcionario-----");
		System.out.println("Função: " + this.funcao);
		System.out.printf("Salario: R$%.2f\n", this.salario);
	}
}
