package aula10;

public class Professor extends Humano {

	private Double salario;
	
	public Professor(String nome, Integer idade, String endereco, Double salario) {
	
		super(nome, idade, endereco);
		this.salario = salario;
	}

	public void calcularSalario() {
		System.out.println(this.nome + " está calculando o salario");
	}
}
