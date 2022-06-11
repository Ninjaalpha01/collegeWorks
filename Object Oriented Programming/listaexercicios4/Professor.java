package listaexercicios4;

public class Professor {

	private Integer registro;
	private String nome;
	private String dataNascimento;
	private Double salario;
	
	Professor(Integer registro, String nome, String dataNascimento, Double salario) {
		
		this.registro = registro;
		this.nome = nome;
		this.dataNascimento = dataNascimento;
		this.salario = salario;
	}
	
	public void imprimirDados() {
		
		System.out.println("------Professor------");
		System.out.println("Nome: " + this.nome);
		System.out.println("Registro: " + this.registro);
		System.out.println("Data de Nascimento: " + this.dataNascimento);
		System.out.printf("Salário: R$%.2f", this.salario);
	}
}
