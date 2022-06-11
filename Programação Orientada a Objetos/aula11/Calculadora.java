package aula11;

public class Calculadora {
	
	private String modelo;
	
	public Calculadora(String modelo) {
		
		this.modelo = modelo;
	}

	public Double calcularMedia(Double a, Double b) {
		
		Double media = (a+b)/2;
		return media;
	}
	
	public Double calcularMedia(Double a, Double b, Double c) {
		
		Double media = (a+b+c)/3;
		return media;
	}
	
	public Double calcularMedia(Double a, Double b, Double c, Double d) {
		
		Double media = (a+b+c+d)/4;
		return media;
	}
}
