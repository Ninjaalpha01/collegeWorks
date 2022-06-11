package aula09;

public class Funcionario {

	private Integer registro;
	private String nome;
	private String cpf;
	private DiaSemana folga;
	
	public Funcionario(Integer registro, String nome, String cpf) {
		
		this.registro = registro;
		this.nome = nome;
		this.cpf = cpf;
	}
	
	public void setFolga(DiaSemana folga) {
		this.folga = folga;
	}
	
	public void imprimirRelatorio() {
		
		System.out.println("Registro: " + registro);
		System.out.println("Nome: " + nome);
		System.out.println("CPF: " + cpf);
		System.out.println("Número do dia da Semana: " + folga.getDia());
		System.out.println("Dia da Semana de Folga: " + folga.getDiaExtenso());
	}
}
