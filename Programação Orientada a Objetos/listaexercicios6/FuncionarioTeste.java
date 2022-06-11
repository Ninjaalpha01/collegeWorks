package listaexercicios6;

public class FuncionarioTeste {

	public static void main(String[] args) {
		
		Disciplina disc = new Disciplina("CC54D", "Programação Orientada a Objetos", "Java", 60);
		ProcessoInstituicao proc = new ProcessoInstituicao(2304, "Internet", "30/11/2020");
		
		Funcionario prof = new Professor(1234, "Jhon", "19/08/2010", 3000.0, "doutor", disc);		
		Funcionario tec = new TecnicoAdiministrativo(4321, "Cleide", "21/03/2018", 4500.0, 500.0, proc);
		
		prof.exibirRelatorio();
		tec.exibirRelatorio();
	}
}
