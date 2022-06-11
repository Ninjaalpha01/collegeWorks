package aula13;

public class Pessoa {

	protected String nome;
	protected Double rendaAnual;
	static Double valorArrecadado;
	
	public Pessoa(String nome, Double rendaAnual) {
		
		this.nome = nome;
		this.rendaAnual = rendaAnual;
		this.valorArrecadado = 0.0;
	}
	
	public void calcularValorPago() {
		
	}
}