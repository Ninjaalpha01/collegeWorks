package listaexercicios4;

public class EventoTeste {

	public static void main(String[] args) {
		
		Endereco end = new Endereco(184, "av. P33", "Vila Paulista", "Rio Claro", "São Paulo");
		Local loc = new Local("Praça boa", end, 100);
		Artista art = new Artista("Luan Santana", "Brasileiro", "Cantor");
		Evento even = new Evento("Arranca Toco", art, "28/05/2022", loc, 18);
		
		even.venderIngressos();
	}
}
