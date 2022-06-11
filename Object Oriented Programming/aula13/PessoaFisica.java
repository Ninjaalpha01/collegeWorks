package aula13;

public class PessoaFisica extends Pessoa {

	private Double gastoSaude;
	
	public PessoaFisica(String nome, Double rendaAnual, Double gastoSaude) {
		
		super(nome, rendaAnual);
		this.gastoSaude = gastoSaude;
	}
	
	@Override
	public void calcularValorPago() {
		
		Double valor;
		
		if(super.rendaAnual < 20000.0)
			valor = super.rendaAnual*0.15;
		
		else
			valor = super.rendaAnual*0.25;
		
		if(this.gastoSaude > 0)
			valor -= this.gastoSaude/2;
		
		System.out.printf("Valor a ser pago: R$%.2f", valor);
		super.valorArrecadado += valor;
	}
}
