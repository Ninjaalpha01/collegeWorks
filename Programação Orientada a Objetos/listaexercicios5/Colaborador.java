package listaexercicios5;

public class Colaborador {

	protected String nome;
	protected String endereco;
	protected String dataInicio;
	
	public Colaborador(String nome, String endereco, String dataInicio) {
		
		this.nome = nome;
		this.endereco = endereco;
		this.dataInicio = dataInicio;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getEndereco() {
		return endereco;
	}

	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}

	public String getDataInicio() {
		return dataInicio;
	}

	public void setDataInicio(String dataInicio) {
		this.dataInicio = dataInicio;
	}

	@Override
	public String toString() {
		return "Colaborador [nome=" + nome + ", endereco=" + endereco + ", dataInicio=" + dataInicio + "]";
	}
	
	public void imprimirDados() {
		
		System.out.println("-----Colaborador-----");
		System.out.println("Nome: " + this.nome);
		System.out.println("Endereco: " + this.endereco);
		System.out.println("Data de Inicio: " + this.dataInicio);
	}
}
