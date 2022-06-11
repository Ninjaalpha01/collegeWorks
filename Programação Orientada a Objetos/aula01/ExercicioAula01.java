package aula01;

public class ExercicioAula01 {

	public static void main(String[] args) {
		
		String produto1 = "Notebook";
		String produto2 = "SSD";
		double precoProduto1 = 3500;
		double precoProduto2 = 250;
		
		System.out.println("Produtos:");
		System.out.print(produto1 + " por apenas: R$");
		System.out.printf("%.2f\n", precoProduto1);
		System.out.print(produto2 + " por apenas: R$");
		System.out.printf("%.2f\n", precoProduto2);
	}
}
