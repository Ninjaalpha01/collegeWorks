package listaexercicios6;

public class TecnicoAdiministrativo extends Funcionario {

	private Double adicionalNoturno;
	private ProcessoInstituicao processo;

	public TecnicoAdiministrativo(Integer registro, String nome, String dataAdmissao,
			Double salarioBase, Double adicionalNoturno, ProcessoInstituicao processo) {
		
		super(registro, nome, dataAdmissao, salarioBase);
		this.adicionalNoturno = adicionalNoturno;
		this.processo = processo;
	}
	
	public Double getAdicionalNoturno() {
		return adicionalNoturno;
	}

	public void setAdicionalNoturno(Double adicionalNoturno) {
		this.adicionalNoturno = adicionalNoturno;
	}

	@Override
	public void calcularSalario() {
		
		super.salarioTotal = super.salarioBase + this.adicionalNoturno;
	}

	@Override
	public void exibirRelatorio() {
		
		System.out.println("-------Funcionário------");
		System.out.println("Técnico Adiministrativo");
		super.imprimirGen();
		System.out.println("--------Processo--------");
		System.out.println("Numero: " + this.processo.getNumero());
		System.out.println("Data de Criação: " + this.processo.getDataCriacao());
		System.out.println("Descrição: " + this.processo.getDescricao());
	}
	
	
}
