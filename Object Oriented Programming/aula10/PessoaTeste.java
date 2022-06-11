package aula10;

public class PessoaTeste {

	public static void main(String[] args) {
		
		Endereço enderecoP1 = new Endereço("Laurentino Deco Fagundes", 101, "Jardim Carvalho", "Ponta Grossa", "PR");
		Pessoa pessoa1 = new Pessoa("Gabriel Leonardo", "02/11/2001", "Masculino", "gabriel_leonardo@email.com", EstadoCivil.SOLTEIRO, enderecoP1);
		
		pessoa1.imprimirRelatorio();
	}
}
