package aula18;

import java.util.InputMismatchException;
import java.util.Scanner;

public class CalculadoraIU {

	private	Scanner input;
	private Calculadora calc;
	
	public CalculadoraIU() {
		
		this.input = new Scanner(System.in);
		this.calc = new Calculadora();
	}
	public void escolherOperacao() {
		
		try {
			System.out.print("Insira x: ");
			int x = input.nextInt();
			System.out.print("Insira y: ");
			int y = input.nextInt();
			
			System.out.println("Escolha uma operação: ");
			System.out.println("1 - Soma");
			System.out.println("2 - Subtração");
			System.out.println("3 - Multiplicação");
			System.out.println("4 - Divisão");
			System.out.println("5 - Potenciação");
			System.out.println("6 - Raiz Quadrada");
			System.out.println("7 - Inverso");
			System.out.print("Opção: ");
			
			int opc = input.nextInt();
			double resultado = 0;
			
			switch (opc)
			{
				case 1:
					resultado = calc.adicao(x, y);
					break;
				case 2:
					resultado = calc.subtracao(x, y);
					break;
				case 3:
					resultado = calc.multiplicacao(x, y);
					break;
				case 4:
					resultado = calc.divisao(x, y);
					break;
				case 5:
					resultado = calc.potenciacao(x, y);
					break;
				case 6:
					resultado = calc.raizQuadrada(x);
					break;
				case 7:
					resultado = calc.inverso(x);
					break;
				default:
					System.out.println("Nenhuma operação válida escolhida.");
					break;
			}
			System.out.println("Resultado: " + resultado);
		}
		catch (ArithmeticException ae) {
			System.err.println("Não é possível dividir por 0.");
		}
		catch (InputMismatchException ime) {
			System.err.println("Entre apenas com valores inteiros.");
		}
		catch (NumeroNaoNaturalException nnne) {
			System.err.println("Número não natural.");
		}
		catch (Exception e) {
			System.err.println("Uma exceção ocorreu.");
		}
	}
}
