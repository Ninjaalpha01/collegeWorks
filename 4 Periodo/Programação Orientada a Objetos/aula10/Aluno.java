package aula10;

public class Aluno extends Humano {

	private String curso;
	
	public Aluno(String nome, Integer idade, String endereco, String curso) {
		super(nome, idade, endereco);
		this.curso = curso;
	}

	public void realizarMatricula() {
		System.out.println(this.nome + " está realizando a matricula");
	}
}
