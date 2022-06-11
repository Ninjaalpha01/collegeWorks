package aula10;

public class RevistaCientificaTeste {

	public static void main(String[] args) {
		
		Artigo art1 = new Artigo("Relatividade");
		Artigo art2 = new Artigo("Física");
		Artigo art3 = new Artigo("Astronomia");
		
		Edicao edi1 = new Edicao(184, 1, "23/07/2012");
		Edicao edi2 = new Edicao(184, 2, "23/08/2012"); 
		
		RevistaCientifica rev = new RevistaCientifica("Science", "Mensal", 293);
		
		edi1.setArtigo(art1);
		edi1.setArtigo(art3);
		edi2.setArtigo(art2);
		
		rev.setEdicao(edi1);
		rev.setEdicao(edi2);
		
		rev.imprimirDados();
	}
}
