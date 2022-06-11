package listaexercicios5;

public class Pessoa {
	
	protected String nome;
	protected String nascimento;
	protected long rg;
	protected long cpf;
	
	public Pessoa(String nome, String nascimento, long rg, long cpf) {
		
		this.nome = nome;
		this.nascimento = nascimento;
		this.rg = rg;
		this.cpf = cpf;
	}
	
	public String getNome() {
		return nome;
	}

	public String getNascimento() {
		return nascimento;
	}

	public long getRg() {
		return rg;
	}

	public long getCpf() {
		return cpf;
	}

	public void dadosPessoa() {
		
		System.out.println("Nome: " + this.nome);
		System.out.println("Nascimento: " + this.nascimento);
		System.out.println("RG: " + this.rg);
		System.out.println("CPF: " + this.cpf);
	}
}
