package listaexercicios1;

public class PessoaTeste {

	public static void main(String[] args) {
		
		Pessoa p1 = new Pessoa();
		Pessoa p2 = new Pessoa();
		Pessoa p3 = new Pessoa();
		
		p1.nome = "Ivania";
		p1.sexo = "Feminino";
		p1.cpf = 323663758;
		p1.idade = 44;
		p1.altura = 1.62;
		p1.peso = 65;
		
		p2.nome = "Gabriel";
		p2.sexo = "Masculino";
		p2.cpf = 468615038;
		p2.idade = 20;
		p2.altura = 1.75;
		p2.peso = 50;
		
		p3.nome = "Thais";
		p3.sexo = "Feminino";
		p3.cpf = 493025834;
		p3.idade = 20;
		p3.altura = 1.67;
		p3.peso = 110;
		
		System.out.println("Pessoas:");
		System.out.println("Nome: " + p1.nome);
		System.out.println("Sexo: " + p1.sexo);
		System.out.println("CPF: " + p1.cpf);
		System.out.println("Idade: " + p1.idade);
		System.out.println("Altura: " + p1.altura);
		System.out.println("Peso: " + p1.peso);
		
		System.out.println("=============");
		System.out.println("Nome: " + p2.nome);
		System.out.println("Sexo: " + p2.sexo);
		System.out.println("CPF: " + p2.cpf);
		System.out.println("Idade: " + p2.idade);
		System.out.println("Altura: " + p2.altura);
		System.out.println("Peso: " + p2.peso);
		
		System.out.println("=============");
		System.out.println("Nome: " + p3.nome);
		System.out.println("Sexo: " + p3.sexo);
		System.out.println("CPF: " + p3.cpf);
		System.out.println("Idade: " + p3.idade);
		System.out.println("Altura: " + p3.altura);
		System.out.println("Peso: " + p3.peso);
	}
}
