package listaexercicios5;

public class AlunoTeste {

	public static void main(String[] args) {
		
		Pessoa p1 = new Pessoa("Valéria", "27/02/1987", 712754217, 357498508);
		
		p1.dadosPessoa();
		
		Aluno a1 = new Aluno(p1.getNome(), p1.getNascimento(), p1.getRg(), p1.getCpf(), 2317839);
		
		a1.dadosAluno();
	}
}
