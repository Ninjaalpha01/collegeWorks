package listaexercicios7;

import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

public class Estacionamento {

	private List<Vaga> vagas;
	private Integer duracaoMin;
	private Double taxaMin;
	private Double adicional;
	private Integer duracaoTotal;
	
	public Estacionamento(List<Vaga> vagas, Integer duracaoMin, Double taxaMin, Double adicional) {
		
		this.vagas = vagas;
		this.duracaoMin = duracaoMin;
		this.taxaMin = taxaMin;
		this.adicional = adicional;
		this.duracaoTotal = 0;
	}

	public List<Vaga> getVagas() {
		return vagas;
	}

	public Integer getDuracaoMin() {
		return duracaoMin;
	}

	public Double getTaxaMin() {
		return taxaMin;
	}

	public Double getAdicional() {
		return adicional;
	}
	
	public void estacionar(Integer numVaga, Veiculo veiculo) {
		
		int hora = 0;
		boolean estaciona = true;
		Scanner input = new Scanner(System.in);
		
		System.out.println("Verificando se é possível estacionar o veiculo: " + veiculo.getModelo());
		
		try {
			System.out.print("Horario de entrada: ");
		
			do
			{
				hora = input.nextInt();
				input.nextLine();
				
				if (hora < 0 )
					throw new NumeroNaoPositivo();
			} while(hora < 0);
		}
		catch (InputMismatchException ime) {
			System.err.println("Entrada de Dados Inválida");
			System.out.println("Não foi possível estacionar o veículo: " + veiculo.getModelo() + "\n");
			estaciona = false;
		}
		catch (NumeroNaoPositivo nnp)
		{
			System.err.println("Entrada de Dados não positiva.");
			System.out.println("Não foi possível estacionar o veículo: " + veiculo.getModelo() + "\n");
			estaciona = false;
		}
		finally {
			input.close();
			if (estaciona)
			{
				Vaga vaga = this.buscaVaga(numVaga);
				if (vaga == null) {
					System.out.println("Vaga não encontrada!\n");
					return;
				}
				if (this.verificarDisponibilidade(vaga)) {
					vaga.addVeiculo(veiculo, numVaga);
					vaga.setHoraInicial(hora);
					System.out.println("Veículo : " + vaga.getVeiculo().getModelo() + " estacionado.\n");
					return;
				}
				System.out.println("Já existe um veículo nesta vaga.\n");
			}
		}
	}
	
	public Vaga buscaVaga(Integer numVaga) {
		for (Vaga vaga : vagas) {
			if (vaga.getNumId() == numVaga) {
				return vaga;
			}
		}
		return null;
	}
	
	public boolean verificarDisponibilidade(Vaga vaga) {
		if (vaga.getVeiculo() == null){
			return true;
		}
		return false;
	}
	
	public void retirar(Integer numVaga, Integer hora) {
		
		Double valorTotal;
		Vaga vaga = this.buscaVaga(numVaga);
		
		if (vaga == null) {
			System.out.println("Vaga não encontrada.\n");
			return;
		}
		if (this.verificarDisponibilidade(vaga)) {
			System.out.println("A vaga já se encontra vazia.\n");
			return;
		}
		
		vaga.setHoraFinal(hora);
		
		this.duracaoTotal = vaga.getHoraFinal() - vaga.getHoraInicial();
		
		if (this.duracaoTotal > this.duracaoMin)
			valorTotal = this.taxaMin + ((this.duracaoTotal - this.duracaoMin) * this.adicional);
		else
			valorTotal = this.taxaMin;
		
		System.out.printf("Valor a pagar: R$%.2f\n", valorTotal);
		System.out.println("Veículo: " + vaga.getVeiculo().getModelo() + " foi retirado.\n");
		vaga.retirarVeiculo(numVaga);
	}
}
