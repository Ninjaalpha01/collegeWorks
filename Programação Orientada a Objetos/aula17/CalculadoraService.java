package aula17;

import java.util.InputMismatchException;
import java.util.Scanner;

public class CalculadoraService {

	private Scanner input;

	public CalculadoraService() {
		super();
		this.input = new Scanner(System.in);
	}
	
	public void dividir() {
		System.out.println("Informe o valor de x: ");
		try {
			int x = this.input.nextInt();
			
			System.out.println("Informe o valor de y: ");
			int y = this.input.nextInt();
			
			double resultado = x / y;
			System.out.println("Resultado: " + x + "/" + y + " = " + resultado);
		}
		catch (ArithmeticException ae) {
			System.out.println("Não é possível dividir por 0.");
			this.dividir();
		}
		catch (InputMismatchException ime) {
			System.out.println("Entrada de dados inválida.");
			input.nextLine();
			this.dividir();
		}
		finally {
			input.close();
		}
	}
}
