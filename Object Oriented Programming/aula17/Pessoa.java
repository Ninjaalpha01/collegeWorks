package aula17;

import java.util.InputMismatchException;

public class Pessoa {

	private String nome;
	private Integer idade;
	private long cpf;
	private String logradouro;
	private Integer num;
	private String bairro;
	private String cidade;
	private String estado;
	private long cep;
	
	public Pessoa(String nome, Integer idade, long cpf, String logradouro, Integer num, String bairro, String cidade,
			String estado, long cep) {
		try {
			this.nome = nome;
			this.idade = idade;
			this.cpf = cpf;
			this.logradouro = logradouro;
			this.num = num;
			this.bairro = bairro;
			this.cidade = cidade;
			this.estado = estado;
			this.cep = cep;
		}
		catch (InputMismatchException ime) {
			System.err.println("Entrada de dados inválida");
		}
		catch (Exception e) {
			System.out.println(e.getMessage());
		}
	}
	
	public Pessoa(String nome, Integer idade, long cpf, long cep) {
		this(nome, idade, cpf, "Vazio", -1, "Vazio", "Vazio", "Vazio", cep);
	}

	@Override
	public String toString() {
		return "Pessoa [nome=" + nome + ", idade=" + idade + ", cpf=" + cpf + ",\n logradouro=" + logradouro + ", num="
				+ num + ", bairro=" + bairro + ",\n cidade=" + cidade + ", estado=" + estado + ", cep=" + cep + "]";
	}
}
