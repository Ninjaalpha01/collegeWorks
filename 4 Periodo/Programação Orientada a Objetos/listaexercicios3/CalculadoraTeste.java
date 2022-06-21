package listaexercicios3;

public class CalculadoraTeste {

	public static void main(String[] args) {
		
		Calculadora c1 = new Calculadora("Casio", "Preto", "Basica", 256);
		
		c1.somar(23.8, 42.93);
		c1.subtrair(10.2, 9.43);
		c1.multiplicar(4, 3.5);
		c1.dividir(9, 4);
	}
}
