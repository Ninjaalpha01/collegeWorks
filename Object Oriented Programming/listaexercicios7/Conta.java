package listaexercicios7;

public class Conta {

	private Integer numConta;
	private Double saldo;
	private Cliente titular;
	
	public Conta(Integer numConta, Cliente titular) {
	
		this.numConta = numConta;
		this.titular = titular;
		this.saldo = 0.00;
	}

	public Integer getNumConta() {
		return numConta;
	}
	
	public Double getSaldo() {
		return saldo;
	}
	
	public void setSaldo(Double saldo) {
		this.saldo = saldo;
	}

	public Cliente getTitular() {
		return titular;
	}

	@Override
	public String toString() {
		return "Conta [numConta=" + numConta + ", saldo=" + saldo + ", titular=" + titular + "]";
	}
}
