package listaexercicios6;

public class Socio extends ClienteLoca {

	private String cpf;
	private Dependente dependente;
	
	public Socio(String nome, String dataNascimento, String cpf, String telefone, Endereco endereco,
			Dependente dependente) {
		
		super(nome, dataNascimento, telefone, endereco);
		this.cpf = cpf;
		this.dependente = dependente;
	}

	public String getCpf() {
		return cpf;
	}

	public void setCpf(String cpf) {
		this.cpf = cpf;
	}

	public Dependente getDependente() {
		return dependente;
	}

	public void setDependente(Dependente dependente) {
		this.dependente = dependente;
	}	
}
