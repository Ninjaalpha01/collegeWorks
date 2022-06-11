package aula13;

public class PessoaJuridica extends Pessoa {

	private Integer numFuncionarios;
	
	public PessoaJuridica(String nome, Double rendaAnual, Integer numFuncionarios) {
		
		super(nome, rendaAnual);
		this.numFuncionarios = numFuncionarios;
	}
	
	@Override
	public void calcularValorPago() {
		
		Double valor;
		
		if(this.numFuncionarios > 15)
			valor = super.rendaAnual*0.13;
		else
			valor = super.rendaAnual*0.18;
		
		System.out.printf("Valor a ser pago: R$%.2f\n", valor);
		super.valorArrecadado += valor;
	}
}
