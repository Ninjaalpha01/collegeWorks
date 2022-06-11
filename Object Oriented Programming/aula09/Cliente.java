package aula09;

public class Cliente {

	private Integer codigo;
	private String nome;
	private String dataNascimento;
	private EstadoCivil estadoCivil;
	
	public Cliente(Integer codigo, String nome, String dataNascimento) {
		
		this.codigo = codigo;
		this.nome = nome;
		this.dataNascimento = dataNascimento;
		this.estadoCivil = EstadoCivil.SOLTEIRO;
	}

	public void setEstadoCivil(EstadoCivil estadoCivil) {
		this.estadoCivil = estadoCivil;
	}

	@Override
	public String toString() {
		return "codigo: " + codigo + "\nnome: " + nome + "\ndataNascimento: " + dataNascimento + 
				"\nestadoCivil: " + estadoCivil;
	}
	
	
}
