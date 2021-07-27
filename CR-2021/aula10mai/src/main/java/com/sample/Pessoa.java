package com.sample;

public class Pessoa {
	private String nome;
	private int idade;
	private String comidaPref;
	private double rendimento;
	
	public Pessoa(String nome, int idade, String comidaPref, double rendimento) {
		super();
		this.nome = nome;
		this.idade = idade;
		this.comidaPref = comidaPref;
		this.rendimento = rendimento;
	}

	public String getNome() {
		return nome;
	}

	public int getIdade() {
		return idade;
	}

	public String getComidaPref() {
		return comidaPref;
	}

	public double getRendimento() {
		return rendimento;
	}
	
}
