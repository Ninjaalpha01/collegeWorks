package listaexercicios4;

public class Dono {

	private String nome;
	private String cpf;
	private String telefone;
	private String email;
	private Endereco endereco;
	
	public Dono(String nome, String cpf, String telefone, String email, Endereco endereco) {
		
		this.nome = nome;
		this.cpf = cpf;
		this.telefone = telefone;
		this.email = email;
		this.endereco = endereco;
	}
	
	public Dono(String nome, String cpf, String telefone, Endereco endereco) {
		this(nome, cpf, telefone, null, endereco);
	}

	public String getTelefone() {
		return telefone;
	}

	public void setTelefone(String telefone) {
		this.telefone = telefone;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public Endereco getEndereco() {
		return endereco;
	}

	public void setEndereco(Endereco endereco) {
		this.endereco = endereco;
	}

	public String getNome() {
		return nome;
	}

	public String getCpf() {
		return cpf;
	}
	
	public void imprimirDados() {
		
		System.out.println("-----DONO-----");
		System.out.println("Nome: " + this.nome);
		System.out.println("CPF: " + this.cpf);
		System.out.println("Telefone: " + this.telefone);
		System.out.println("Email: " + this.email);
		this.endereco.imprimirEndereco();
	}
}
