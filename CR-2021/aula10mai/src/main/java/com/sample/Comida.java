package com.sample;

public class Comida {
	private String comida;
	private int calorias;
	
	public Comida(String comida, int calorias) {
		super();
		this.comida = comida;
		this.calorias = calorias;
	}

	public String getComida() {
		return comida;
	}

	public void setComida(String comida) {
		this.comida = comida;
	}

	public int getCalorias() {
		return calorias;
	}

	public void setCalorias(int calorias) {
		this.calorias = calorias;
	}
	
	
}
