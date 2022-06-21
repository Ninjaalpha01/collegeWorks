package listaexercicios7;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class EstacionamentoTeste {

	public static void main(String[] args) {
		
		Veiculo carro1 = new Veiculo("Celta", "DEG-9034");
		Veiculo carro2 = new Veiculo("Corsa", "REO-3419");
		
		List<Vaga>vagas = new ArrayList<Vaga>();
		Vaga vaga = null;
		
		for (int i=0; i<10; i++) {
			vaga = new Vaga(i);
			vagas.add(vaga);
		}
		
		Estacionamento estaciona = new Estacionamento(vagas, 3, 2.0, 0.5);
		Scanner input = new Scanner(System.in);
		boolean x = true;
		
		do
		{
			System.out.println("1 - Estacionar");
			System.out.println("2 - Retirar");
			System.out.println("Escolha uma opcão:");
			int opc = input.nextInt();
			
			switch(opc) {
				case 1:
					System.out.print("Qual carro deseja estacionar? ");
					opc = input.nextInt();
					
					System.out.print("Em qual vaga: ");
					int numVaga = input.nextInt();
					
					if (opc == 1) 
						estaciona.estacionar(numVaga, carro1);
					if (opc == 2)
						estaciona.estacionar(numVaga, carro2);
					break;
				
				case 2:
					System.out.print("Qual vaga seu carro se encontra? ");
					numVaga = input.nextInt();
					
					System.out.print("Qual o horário de retirada: ");
					opc = input.nextInt();
					
					estaciona.retirar(numVaga, opc);
					break;
				
				default:
					x = false;
			}
		} while (x);
		input.close();
	}
}
