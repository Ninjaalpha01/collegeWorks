package listaexercicios3;

public class Funcionario {

	private int numRegistro;
	private String telefone;
	private String nome;
	private String nascimento;
	private String sexo;
	private String setor;
	
	//endereco
	private int numCasa;
	private String rua;
	private String bairro;
	private String cidade;
	private String estado;
	
	public Funcionario(int numRegistro, String nome, String nascimento, String sexo, String setor, String telefone,
			String rua, int numCasa, String bairro, String cidade, String estado) {
		
		this.numRegistro = numRegistro;
		this.nome = nome;
		this.nascimento = nascimento;
		this.sexo = sexo;
		this.setor = setor;
		this.telefone = telefone;
		this.rua = rua;
		this.numCasa = numCasa;
		this.bairro = bairro;
		this.cidade = cidade;
		this.estado = estado;
	}
	
	public void setNascimento(String nascimento) {
		this.nascimento = nascimento;
	}

	public void setSexo(String sexo) {
		this.sexo = sexo;
	}

	public void setSetor(String setor) {
		this.setor = setor;
	}

	public void setNumCasa(int numCasa) {
		this.numCasa = numCasa;
	}

	public void setRua(String rua) {
		this.rua = rua;
	}

	public void setBairro(String bairro) {
		this.bairro = bairro;
	}

	public void setCidade(String cidade) {
		this.cidade = cidade;
	}

	public void setEstado(String estado) {
		this.estado = estado;
	}

	public Funcionario(int numRegistro, String nome, String setor, String cidade) {
		this(numRegistro, nome, "1/1/1990", "nao informado", setor, "(00)00000-0000", "zero", 183, "Vila Palmeiras", cidade, "Sao Paulo");
	}

	public void setTelefone(String telefone) {
		this.telefone = telefone;
	}
	
	public String getTelefone() {
		System.out.println("Numero de telefone alterado.");
		return telefone;
	}

	public int getNumRegistro() {
		return numRegistro;
	}

	public String getNome() {
		return nome;
	}
	
	public String getSetor() {
		return setor;
	}
}
