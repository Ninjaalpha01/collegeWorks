package listaexercicios3;

public class FuncionarioTeste {

	public static void main(String[] args) {
		
		Funcionario f1 = new Funcionario(231, "Gabriel Leonardo", "TI", "Ponta Grossa");
		Funcionario f2 = new Funcionario(195, "Samuel Prado", "Analista de Testes", "Rio Claro");
		
		System.out.println("Funcionario 1:");
		System.out.println("Nome: " + f1.getNome());
		System.out.println("Numero de registro: " + f1.getNumRegistro());
		System.out.println("Setor: " + f1.getSetor());
		f1.setTelefone("(19)99619-0935");
		System.out.println("Numero de telefone: " + f1.getTelefone());
		
		System.out.println("\nFuncionario 2:");
		System.out.println("Nome: " + f2.getNome());
		System.out.println("Numero de registro: " + f2.getNumRegistro());
		System.out.println("Setor: " + f2.getSetor());
		System.out.println("Numero de telefone: " + f2.getTelefone());
	}
}
