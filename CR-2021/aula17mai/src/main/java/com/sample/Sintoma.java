package com.sample;

public class Sintoma {
	private String idPaciente;
	private String sintoma;
	
	public Sintoma(String idPaciente, String sintoma) {
		super();
		this.idPaciente = idPaciente;
		this.sintoma = sintoma;
	}

	public String getIdPaciente() {
		return idPaciente;
	}
	
	public void setIdPaciente(String idPaciente) {
		this.idPaciente = idPaciente;
	}
	
	public String getSintoma() {
		return sintoma;
	}
	
	public void setSintoma(String sintoma) {
		this.sintoma = sintoma;
	}
	
}
