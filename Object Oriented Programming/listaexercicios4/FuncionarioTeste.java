package listaexercicios4;

public class FuncionarioTeste {

	public static void main(String[] args) {
		
		Endereco end = new Endereco(101, "Laurentino Deco Fagundes", "Jardim Carvalho", "Ponta Grossa");
		Funcionario func = new Funcionario(2301, "Gleison", "Masculino", "TI", end);
		
		func.emitirRelatorio();
		
		Endereco end1 = new Endereco(184, "Av. P33", "Vila Paulista", "Rio Claro", "São Paulo");
		func.setEndereco(end1);
		
		func.getEndereco();
	}
}
