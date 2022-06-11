package aula10;

public class Pessoa {

	private String nome;
	private String dataNascimento;
	private String sexo;
	private String email;
	private EstadoCivil estadoCivil;
	private Endereço endereco;
	
	public Pessoa(String nome, String dataNascimento, String sexo, String email, EstadoCivil estadoCivil,
			Endereço endereco) {

		this.nome = nome;
		this.dataNascimento = dataNascimento;
		this.sexo = sexo;
		this.email = email;
		this.estadoCivil = estadoCivil;
		this.endereco = endereco;
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

	public String getEmail() {
		return email;
	}

	public EstadoCivil getEstadoCivil() {
		return estadoCivil;
	}

	public Endereço getEndereco() {
		return endereco;
	}

	public void setSexo(String sexo) {
		this.sexo = sexo;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public void setEstadoCivil(EstadoCivil estadoCivil) {
		this.estadoCivil = estadoCivil;
	}

	public void setEndereco(Endereço endereco) {
		this.endereco = endereco;
	}

	public void imprimirRelatorio() {
		
		System.out.println("Nome: " + nome);
		System.out.println("Data de Nascimento: " + dataNascimento);
		System.out.println("Sexo: " + sexo);
		System.out.println("Email: " + email);
		System.out.println("Estado Civil: " + estadoCivil.getEstado());
		System.out.println("Logradouro: " + endereco.getLogradouro());
		System.out.println("Número: " + endereco.getNumero());
		System.out.println("Bairro: " + endereco.getBairro());
		System.out.println("Cidade: " + endereco.getCidade());
		System.out.println("UF: " + endereco.getUnidadeFederativa());
	}
}
