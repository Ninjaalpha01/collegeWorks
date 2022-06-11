package listaexercicios4;

public class Funcionario {

	private Integer numeroRegistro;
	private String nome;
	private String dataNascimento;
	private String sexo;
	private String setor;
	private String telefone;
	private Endereco endereco;
	
	Funcionario(Integer numeroRegistro, String nome, String dataNascimento, String sexo, String setor, String telefone, Endereco endereco){
		
		this.numeroRegistro = numeroRegistro;
		this.nome = nome;
		this.dataNascimento = dataNascimento;
		this.sexo = sexo;
		this.setor = setor;
		this.telefone = telefone;
		this.endereco = endereco;
	}
	
	Funcionario(Integer numeroRegistro, String nome, String sexo, String setor, Endereco endereco){
		this(numeroRegistro, nome, "01/01/1980", sexo, setor, null, endereco);
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}

	public void setDataNascimento(String dataNascimento) {
		this.dataNascimento = dataNascimento;
	}

	public void setSetor(String setor) {
		this.setor = setor;
	}

	public void setTelefone(String telefone) {
		this.telefone = telefone;
	}
	
	public void setEndereco(Endereco endereco) {
		this.endereco = endereco;
		System.out.println("Endereço atualizado!");
	}

	public Integer getNumeroRegistro() {
		return numeroRegistro;
	}

	public String getNome() {
		return nome;
	}

	public String getDataNascimento() {
		return dataNascimento;
	}

	public String getSexo() {
		return sexo;
	}

	public String getSetor() {
		return setor;
	}

	public String getTelefone() {
		return telefone;
	}

	public void getEndereco() {
		
		System.out.println("-----Endereço-----");
		System.out.println("Logradouro: " + this.endereco.getLogradouro());
		System.out.println("Número: " + this.endereco.getNumero());
		System.out.println("Bairro: " + this.endereco.getBairro());
		System.out.println("Cidade: " + this.endereco.getCidade());
	}

	public void emitirRelatorio(){
		
		System.out.println("Número de Registro: " + this.numeroRegistro);
		System.out.println("Nome: " + this.nome);
		System.out.println("Data de Nascimento: " + this.dataNascimento);
		System.out.println("Sexo: " + this.sexo);
		System.out.println("Setor: " + this.setor);
		System.out.println("Telefone: " + this.telefone);
		System.out.println("-----Endereço-----");
		System.out.println("Logradouro: " + this.endereco.getLogradouro());
		System.out.println("Número: " + this.endereco.getNumero());
		System.out.println("Bairro: " + this.endereco.getBairro());
		System.out.println("Cidade: " + this.endereco.getCidade());
		System.out.println("Unidade Federativa: " + this.endereco.getUnidadeFederativa());
		
	}
}
