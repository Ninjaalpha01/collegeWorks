package listaexercicios1;

public class CalculadoraTeste {

	public static void main(String[] args) {
		
		Calculadora c1 = new Calculadora();
		Calculadora c2 = new Calculadora();
		Calculadora c3 = new Calculadora();
		
		c1.marca = "Cesio";
		c1.modelo = "32";
		c1.tipo = "16 teclas";
		c1.memoriaInterna = "4 mb";
		
		c2.marca = "Aumer";
		c2.modelo = "a293";
		c2.tipo = "16 teclas";
		c2.memoriaInterna = "10 mb";
		
		c3.marca = "Multilaser";
		c3.modelo = "m493";
		c3.tipo = "10 teclas";
		c3.memoriaInterna = "2 mb";
		
		System.out.println("Calculadoras:");
		System.out.println("Marca: " + c1.marca);
		System.out.println("Modelo: " + c1.modelo);
		System.out.println("Tipo: " + c1.tipo);
		System.out.println("Memória Interna: " + c1.memoriaInterna);
		
		System.out.println("=============");
		System.out.println("Marca: " + c2.marca);
		System.out.println("Modelo: " + c2.modelo);
		System.out.println("Tipo: " + c2.tipo);
		System.out.println("Memória Interna: " + c2.memoriaInterna);
		
		System.out.println("=============");
		System.out.println("Marca: " + c3.marca);
		System.out.println("Modelo: " + c3.modelo);
		System.out.println("Tipo: " + c3.tipo);
		System.out.println("Memória Interna: " + c3.memoriaInterna);
	}
}
