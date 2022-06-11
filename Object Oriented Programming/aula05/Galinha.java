package aula05;

public class Galinha {
	
	String nome;
	int qntdOvos = 0;
	static int qntdOvosGranja = 0;
	
	public void botar() {
		
		qntdOvos++;
		qntdOvosGranja++;
	}
}
