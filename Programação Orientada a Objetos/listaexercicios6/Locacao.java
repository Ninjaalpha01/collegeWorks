package listaexercicios6;

public class Locacao {

	private Integer diaLocacao;
	private Integer diaPrevisto;
	private Integer diaDevolucao;
	private FilmeLoca filme;
	private ClienteLoca cliente;
	private Double valorLocacao;
	private Double valorMulta;
	
	public Locacao(FilmeLoca filme, Double valorMulta) {
		
		this.filme = filme;
		this.valorMulta = valorMulta;
	}

	public Integer getDiaLocacao() {
		return diaLocacao;
	}

	public void setDiaLocacao(Integer diaLocacao) {
		this.diaLocacao = diaLocacao;
	}

	public Integer getDiaPrevisto() {
		return diaPrevisto;
	}

	public void setDiaPrevisto(Integer diaPrevisto) {
		this.diaPrevisto = diaPrevisto;
	}

	public Integer getDiaDevolucao() {
		return diaDevolucao;
	}

	public void setDiaDevolucao(Integer diaDevolucao) {
		this.diaDevolucao = diaDevolucao;
	}

	public FilmeLoca getFilme() {
		return filme;
	}

	public void setFilme(FilmeLoca filme) {
		this.filme = filme;
	}

	public ClienteLoca getCliente() {
		return cliente;
	}

	public Double getValorLocacao() {
		return valorLocacao;
	}

	public Double getValorMulta() {
		return valorMulta;
	}
	
	public void locarFilme(ClienteLoca cliente, FilmeLoca filme, Integer diaLocacao) {
		
		if (this.filme == filme) {
			
			if (this.filme.isDisponivel()) {
				
				this.cliente = cliente;
				this.diaLocacao = diaLocacao;
				this.diaPrevisto = this.diaLocacao + 14;
				
				if (this.diaPrevisto > 30)
					this.diaPrevisto -= 30;
				
				this.filme.setDisponivel(false);
			}
			else
				System.out.println("Filme não disponível para locação!");
		}
	}
	
	public void devolverFilme(FilmeLoca filme, Integer diaDevolucao) {
		
		this.diaDevolucao = diaDevolucao;
		
		if (this.diaDevolucao - this.diaPrevisto > 0) {
			this.valorMulta *= this.diaDevolucao - this.diaPrevisto;
			this.valorLocacao = this.filme.getPreco() + this.valorMulta;
		}
		else
			this.valorLocacao = this.filme.getPreco();
		
		this.filme.setDisponivel(true);
	}
}
