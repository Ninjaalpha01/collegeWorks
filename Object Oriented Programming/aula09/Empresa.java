package aula09;

public class Empresa {

	private String razaoSocial;
	private String cnpj;
	private UnidadeFederativa unidadeFederativa;
	
	public Empresa(String razaoSocial, String cnpj, UnidadeFederativa unidadeFederativa) {
		super();
		this.razaoSocial = razaoSocial;
		this.cnpj = cnpj;
		this.unidadeFederativa = unidadeFederativa;
	}
	
	public void imprimirDados() {
		
		System.out.println("Razão Social: " + razaoSocial);
		System.out.println("CNPJ: " + cnpj);
		System.out.println("Unidade Federativa: " + unidadeFederativa.getNomeEstado());
		System.out.println("Capital: " + unidadeFederativa.getCapital() + "-" + unidadeFederativa.getSigla());
	}
}
