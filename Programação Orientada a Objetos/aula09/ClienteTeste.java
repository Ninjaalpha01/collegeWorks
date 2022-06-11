package aula09;

public class ClienteTeste {

	public static void main(String[] args) {
		
		Cliente cliente1 = new Cliente(35, "João" , "18/04/1994");
		
		System.out.println(cliente1);
		
		cliente1.setEstadoCivil(EstadoCivil.CASADO);
		
		System.out.println("======================");
		System.out.println(cliente1);
	}
}
