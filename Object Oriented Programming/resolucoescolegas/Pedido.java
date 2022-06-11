package resolucoescolegas;

public class Pedido {
  public static void main(String[] args) {
	  
	 PratoEntrada comida1 =null;
	 PratoPrincipal comida2=null;
	 PratoSobremesa comida3=null;
	 
	Conta conta1=new Conta("Jose",887909123,comida1,comida2,comida3);
	conta1.entrada(1);
	System.out.println("\n====================");
	conta1.principal(1);
	System.out.println("===================");
	
	conta1.fecharConta();
  }	
}
