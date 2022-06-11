package listaexercicios5;

public class ColaboradorTeste {

	public static void main(String[] args) {
		
		Empregado emp = new Empregado("Cristaldo", "PG", "22/04/2018", "Operador de Linha de Produção",
						1750.0, 3892045);
		Estagiario est = new Estagiario("Zelda", "PG", "15/05/2017", "Assistente de Limpeza",
						1750.0, 3092344);
		Empresa empresa = new Empresa("GELD - S.A.", "Santo Antonio", "5/09/2015", 20.0, "Manutenção", 93028503);
		Autonomo auto = new Autonomo("Duani de Oliveira", "Rio Claro", "11/03/2020", 150.0,
						"Manutenção de Infraestrutura", 232019532);
		
		emp.imprimirDados();
		System.out.println("===================");
		est.imprimirDados();
		System.out.println("===================");
		empresa.imprimirDados();
		System.out.println("===================");
		auto.imprimirDados();
	}
}
