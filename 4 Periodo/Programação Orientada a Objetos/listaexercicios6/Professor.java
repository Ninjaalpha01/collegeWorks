package listaexercicios6;

public class Professor extends Funcionario {

	private Double gratificacao;
	protected String titulacao;
	private Disciplina disciplina;

	public Professor(Integer registro, String nome, String dataAdmissao, Double salarioBase, String titulacao,
			Disciplina disciplina) {
		
		super(registro, nome, dataAdmissao, salarioBase);
		this.disciplina = disciplina;
		this.titulacao = titulacao;
		
		if (this.titulacao.equals("Mestre") || this.titulacao.equals("mestre"))
			this.gratificacao = 1000.0;
		else
			if (this.titulacao.equals("Doutor") || this.titulacao.equals("doutor"))
				this.gratificacao = 2000.0;
			else
				this.gratificacao = 0.0;
	}

	public Double getGratificacao() {
		return gratificacao;
	}

	public Disciplina getDisciplina() {
		return disciplina;
	}

	public void setDisciplina(Disciplina disciplina) {
		this.disciplina = disciplina;
	}
	
	public String getTitulacao() {
		return this.titulacao;
	}
	
	public void setTitulacao(String titulacao) {
		this.titulacao = titulacao;
	}

	@Override
	public void calcularSalario() {
		super.salarioTotal = super.salarioBase + this.gratificacao;
	}
	
	@Override
	public void exibirRelatorio() {
		
		System.out.println("-------Funcionário------");
		System.out.println("Professor");
		super.imprimirGen();
		System.out.println("Titulação: " + this.getTitulacao());
		System.out.println("-------Disciplina-------");
		System.out.println("Código: " + this.disciplina.getCodigo());
		System.out.println("Nome: " + this.disciplina.getNome());
		System.out.println("Ementa: " + this.disciplina.getEmenta());
		System.out.println("Carga Horaria: " + this.disciplina.getCargaHoraria());
	}
	
}
