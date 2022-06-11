package listaexercicios2;

public class PessoasTeste {

	public static void main(String[] args) {
		
		Pessoas p1 = new Pessoas();
		Pessoas p2 = new Pessoas();
		
		p1.nome = "Maria";
		p1.sexo = "Feminino";
		p1.cpf = 366375843;
		p1.idade = 20;
		p1.altura = 1.83;
		p1.peso = 78;
		
		p2.nome = "Gustavo";
		p2.sexo = "Masculino";
		p2.cpf = 2132289323;
		p2.idade = 32;
		p2.altura = 1.68;
		p2.peso = 76;
		
		p1.andar();
		p2.correr();
		p1.falar();
		p2.dormir();
	}
}
