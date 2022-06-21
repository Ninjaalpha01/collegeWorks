package aula09;

public class FuncionarioTeste {

	public static void main(String[] args) {
		
		Funcionario func1 = new Funcionario(3432, "Gabriel Leonardo", "468103886");
		func1.setFolga(DiaSemana.QUINTA);
		
		func1.imprimirRelatorio();
	}
}
