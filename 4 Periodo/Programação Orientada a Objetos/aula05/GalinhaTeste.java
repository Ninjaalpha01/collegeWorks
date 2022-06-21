package aula05;

public class GalinhaTeste {

	public static void main(String[] args) {
		
		Galinha galinha1 = new Galinha();
		Galinha galinha2 = new Galinha();
		Galinha galinha3 = new Galinha();
		
		galinha1.nome = "Matilde";
		galinha2.nome = "Giselda";
		galinha3.nome = "Clotilde";
		
		galinha1.botar();
		galinha1.botar();
		galinha1.botar();
		galinha1.botar();
		galinha2.botar();
		galinha2.botar();
		galinha2.botar();
		galinha3.botar();
		
		System.out.println(galinha1.nome + " botou " + galinha1.qntdOvos + " ovos.");
		System.out.println(galinha2.nome + " botou " + galinha2.qntdOvos + " ovos.");
		System.out.println(galinha3.nome + " botou " + galinha3.qntdOvos + " ovos.");
		System.out.println("Quantidade total de ovos: " + Galinha.qntdOvosGranja);
	}
}
