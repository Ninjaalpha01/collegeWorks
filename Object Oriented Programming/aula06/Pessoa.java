package aula06;

public class Pessoa {

	String nome;
	int idade;
	int qntdFilhos;
	double peso;
	
	public Pessoa(String nome, int idade, double peso, int qntdFilhos) {
		
		this.nome = nome;
		this.idade = idade;
		this.peso = peso;
		this.qntdFilhos = qntdFilhos;
	}
	
	public Pessoa(String nome, int idade, double peso) {
		this(nome, idade, peso, 0);
	}
	
	public Pessoa(String nome, double peso) {
		this(nome, 20, peso, 0);
	}
	
	public Pessoa(String nome, int idade) {
		this(nome, idade, 70.0, 0);
	}
	
	public Pessoa(String nome) {
		this(nome, 20, 70.0, 0);
	}

	@Override
	public String toString() {
		return "Pessoa [nome=" + nome + ", idade=" + idade + ", qntdFilhos=" + qntdFilhos + ", peso=" + peso + "]";
	}
}
