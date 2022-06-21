package listaexercicios6;

import java.util.Scanner;

public class ContaTeste {

	public static void main(String[] args) {
	
		Cliente cli = new Cliente("Gabriel", "34965201");
		Conta con = new Conta(cli);
		Scanner input = new Scanner(System.in);
		int opc;
		
		for (int i=0; i<3; i++)
		{
			System.out.println("Deseja adicionar um prato? (1 - Sim / 2 - Não)");
			opc = input.nextInt();
			
			if (opc == 1)
				con.adicionarPrato();
			else
				if(opc == 2)
					break;
				else
					System.out.println("Opção inválida.");
		}

		System.out.println("Fechando a conta... \n================");
		
		con.imprimirConta();
		
		input.close();
	}
}
