package aula02;

public class ExercicioAula02Bhaskara {

	public static void main(String[] args) {
		
		double a, b, c, x1, x2;
		
		a = 3;
		b = 1;
		c = -3;
		
		if ((b*b-4*a*c) < 0)
			System.out.println("Erro, delta negativo");
		else
		{
			x1 = (-b+Math.sqrt(b*b-4*a*c))/2*a;
			x2 = (-b-Math.sqrt(b*b-4*a*c))/2*a;
			System.out.println("x1 = " + x1);
			System.out.println("x2 = " + x2);
		}
	}
}
