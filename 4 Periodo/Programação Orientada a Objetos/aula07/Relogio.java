package aula07;

public class Relogio {

	private String marca;
	private int hora;
	private int minutos;
	
	public Relogio(String marca, int hora, int minutos) {
		
		this.marca = marca;
		setHora(hora);
		setMinutos(minutos);
	}

	public int getHora() {
		return hora;
	}

	public void setHora(int hora) {
		
		if (hora >= 0 & hora <= 23)
			this.hora = hora;
		else
			System.out.println("Hora inválida.");
	}

	public int getMinutos() {
		return minutos;
	}

	public void setMinutos(int minutos) {
		
		if (minutos >= 0 & minutos <= 59)
			this.minutos = minutos;
		else
			System.out.println("Minutos inválidos.");
	}
	
	public String getMarca() {
		return this.marca;
	}
}
