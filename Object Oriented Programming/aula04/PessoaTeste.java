package aula04;

public class PessoaTeste {

	public static void main(String[] args) {
		
		Pessoa p1 = new Pessoa();
		Pessoa p2 = new Pessoa();
		Pessoa p3 = new Pessoa();
		
		p1.nome = "João";
		p1.idade = 25;
		p1.peso = 68.5;
		
		p2.nome = "Maria";
		p2.idade = 30;
		p2.peso = 55.6;
		
		p3.nome = "Arthur";
		p3.idade = 32;
		p3.peso = 62.4;
		
		System.out.println(p1);
		System.out.println("==================");
		System.out.println(p2);
		System.out.println("==================");
		System.out.println(p3);
		System.out.println("==================");
		
		p1.andar();
		p2.correr();
		p3.falar();
	}
}
