package aula10;

public enum EstadoCivil {

	SOLTEIRO("Solteiro"),
	CASADO("Casado"),
	DIVORCIADO("Divorciado"),
	VIUVO("Viuvo");
	
	private String estado;
	
	private EstadoCivil(String estado) {
		this.estado = estado;
	}

	public String getEstado() {
		return estado;
	}

	public void setEstado(String estado) {
		this.estado = estado;
	}
}
