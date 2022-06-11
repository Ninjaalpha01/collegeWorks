package listaexercicios5;

public class Estagiario extends Funcionario {

	private int ciee;

	public Estagiario(String nome, String endereco, String dataInicio, String funcao, double salario, int ciee) {
		
		super(nome, endereco, dataInicio, funcao, salario);
		this.ciee = ciee;
	}

	public int getCiee() {
		return ciee;
	}

	public void setCiee(int ciee) {
		this.ciee = ciee;
	}

	@Override
	public String toString() {
		return "Estagiario [ciee=" + ciee + "]";
	}
	
	public void imprimirDados() {
		
		super.imprimirDados();
		System.out.println("-----Estagiario-----");
		System.out.println("CIEE: " + this.ciee);
	}
}
