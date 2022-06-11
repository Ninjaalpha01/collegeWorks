package listaexercicios4;

public class Animal {

	private String nome;
	private String sexo;
	private Integer idade;
	private Dono dono;
	private Boolean tratado;
	private String descricaoTratamento;
	private String dataInicio;
	private String dataFinal;
	
	public Animal(String nome, String sexo, Integer idade, Dono dono) {
		
		this.nome = nome;
		this.sexo = sexo;
		this.idade = idade;
		this.dono = dono;
		this.tratado = false;
	}
	
	public String getNome() {
		return nome;
	}

	public String getSexo() {
		return sexo;
	}

	public Integer getIdade() {
		return idade;
	}

	public Boolean getTratado() {
		return tratado;
	}

	public String getDescricaoTratamento() {
		return descricaoTratamento;
	}

	public String getDataInicio() {
		return dataInicio;
	}

	public String getDataFinal() {
		return dataFinal;
	}

	public void tratarAnimal(String descricao, String dataInicio) {
		
		this.descricaoTratamento = descricao;
		this.dataInicio = dataInicio;
	}
	
	public void acabarTratamento(String dataFinal) {
		
		this.dataFinal = dataFinal;
		this.tratado = true;
	}

	public void imprimirDados() {
		
		System.out.println("-----ANIMAL-----");
		System.out.println("Nome: " + this.nome);
		System.out.println("Sexo: " + this.sexo);
		System.out.println("Idade: " + this.idade + " anos");
		System.out.println("Tratado: " + this.tratado);
		System.out.println("Data de Inicio: " + this.dataInicio);
		System.out.println("Data Final: " + this.dataFinal);
		this.dono.imprimirDados();
	}
}
