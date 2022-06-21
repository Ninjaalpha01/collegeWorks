package listaexercicios5;

public class Aluno extends Pessoa {

	private Integer numMatricula;

	public Aluno(String nome, String nascimento, long rg, long cpf, Integer numMatricula) {
		
		super(nome, nascimento, rg, cpf);
		this.numMatricula = numMatricula;
	}
	
	public void dadosAluno() {
		
		System.out.println("========ALUNO========");
		super.dadosPessoa();
		System.out.println("Número de Matrícula: " + this.numMatricula);
	}

	public Integer getNumMatricula() {
		return numMatricula;
	}
}
