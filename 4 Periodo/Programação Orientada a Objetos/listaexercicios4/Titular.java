package listaexercicios4;

public class Titular {

	private String cpf;
	private String rg;
	private String nome;
	private String dataNascimento;
	private String sexo;
	private Double rendaMensal;
	private Endereco endereco;
	
	public Titular(String cpf, String rg, String nome, String dataNascimento, String sexo, Double rendaMensal,
			Endereco endereco) {
		
		this.cpf = cpf;
		this.rg = rg;
		this.nome = nome;
		this.dataNascimento = dataNascimento;
		this.sexo = sexo;
		this.rendaMensal = rendaMensal;
		this.endereco = endereco;
	}

	public Titular(String cpf, String nome, String dataNascimento, Double rendaMensal, Endereco endereco) {
		this(cpf, "00000000-0", nome, dataNascimento, "Indefinido", rendaMensal, endereco);
	}
	
	
	public String getRg() {
		return rg;
	}

	public void setRg(String rg) {
		this.rg = rg;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getSexo() {
		return sexo;
	}

	public void setSexo(String sexo) {
		this.sexo = sexo;
	}

	public void setEndereco(Endereco endereco) {
		this.endereco = endereco;
	}

	public void getEndereco() {
		this.endereco.imprimirEndereco();
	}

	public String getCpf() {
		return cpf;
	}

	public String getDataNascimento() {
		return dataNascimento;
	}

	public Double getRendaMensal() {
		return rendaMensal;
	}

	public void imprimirTitular() {
		
		System.out.println("-----TITULAR-----");
		System.out.println("Nome: " + this.nome);
		System.out.println("CPF: " + this.cpf);
		System.out.println("RG: " + this.rg);
		System.out.println("Data de Nascimento: " + this.dataNascimento);
		System.out.println("Sexo: " + this.sexo);
		System.out.printf("Renda Mensal: R$%.2f\n", this.rendaMensal);
		this.endereco.imprimirEndereco();
	}
}
