package listaexercicios6;

public class SessaoTeste {

	public static void main(String[] args) {
		
		Filme fil = new Filme("Vingadores: Ultimato", 220);
		Sala sal = new Sala(1, 120);
		Sessao ses = new Sessao("25/04/19", "20:00", sal, fil);
		
		ses.imprimirRelatorio();
		ses.venderIngresso(15);
		ses.imprimirRelatorio();
		ses.venderIngresso(150);
	}
}
