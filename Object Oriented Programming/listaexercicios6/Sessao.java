package listaexercicios6;

public class Sessao {

	private String data;
	private String horario;
	private Integer numIngressos;
	private Sala sala;
	private Filme filme;
	
	public Sessao(String data, String horario, Sala sala, Filme filme) {
		
		this.data = data;
		this.horario = horario;
		this.sala = sala;
		this.filme = filme;
		this.numIngressos = this.sala.getCapacidadeMax();
	}

	public String getData() {
		return data;
	}

	public void setData(String data) {
		this.data = data;
	}

	public String getHorario() {
		return horario;
	}

	public void setHorario(String horario) {
		this.horario = horario;
	}

	public Integer getNumIngressos() {
		return numIngressos;
	}

	public void setNumIngressos(Integer numIngressos) {
		this.numIngressos = numIngressos;
	}

	public Sala getSala() {
		return sala;
	}

	public void setSala(Sala sala) {
		this.sala = sala;
	}
	
	public Filme getFilme() {
		return filme;
	}

	public void setFilme(Filme filme) {
		this.filme = filme;
	}

	public void venderIngresso(Integer ingressos) {
		
		if(this.numIngressos >= ingressos) {
			this.numIngressos -= ingressos;
			System.out.println("Venda efetuada.");
		}
		
		else
			System.out.println("Não está disponível essa quantidade de ingressos");
	}
	
	public void imprimirRelatorio() {
		
		System.out.println("Sessão: ");
		System.out.println("Data: " + this.data);
		System.out.println("Horário: " + this.horario);
		System.out.printf("Ingressos vendidos: %d\n", this.sala.getCapacidadeMax() - this.numIngressos);
		System.out.println("Número da Sala: " + this.sala.getId());
		System.out.println("Filme: " + this.filme.getTitulo());
		System.out.println("Duração: " + this.filme.getDuracao() + "min");
		System.out.println("======================");
	}
}
