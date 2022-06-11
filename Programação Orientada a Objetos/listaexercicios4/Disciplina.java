package listaexercicios4;

public class Disciplina {

	private Integer codigo;
	private Integer cargaHoraria;
	private String nome;
	private String modalidade; //presencial ou a distancia
	private Professor professor;
	
	public Disciplina(Integer codigo, String nome, String modalidade, Integer cargaHoraria, Professor professor) {
		
		this.codigo = codigo;
		this.nome = nome;
		this.modalidade = modalidade;
		this.cargaHoraria = cargaHoraria;
		this.professor = professor;
	}
	
	public Disciplina(String nome, Integer cargaHoraria, Professor professor) {
		this(10, nome, "Presencial", cargaHoraria, professor);
	}
	
	public void imprimirRelatorio() {
		
		System.out.println("-----Disciplina-----");
		System.out.println("Código: " + this.codigo);
		System.out.println("Nome: " + this.nome);
		System.out.println("Modalidade: " + this.modalidade);
		System.out.println("Carga Horária: " + this.cargaHoraria + "h");
		professor.imprimirDados();
	}
}
