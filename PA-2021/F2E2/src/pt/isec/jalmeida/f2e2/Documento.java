package pt.isec.jalmeida.f2e2;

import java.util.*;

public class Documento {
    private static final int INC_AUTORES = 2;
    private String titulo;
    //private String [] autores;
    private StringBuffer texto;
    //private int nAutores;
    private List<String> autores;

    public Documento(String titulo) {
        this.titulo = titulo;
        //autores = new String[INC_AUTORES];
        autores = new ArrayList<>();
        texto = new StringBuffer();
        //nAutores = 0;
    }

    public String getTitulo() {
        return titulo;
    }

    public String[] getAutores() {
        //if (nAutores == 0)
        //    return null;

        //return Arrays.copyOf(autores, nAutores);

        if (autores == null || autores.size() == 0)
            return null;

        return autores.toArray(new String[autores.size()]);
    }

    public String getTexto() {
        return texto == null ? "" : texto.toString();
    }

    public boolean acrescentaAutor(String autor) {
        //for (int i = 0; i < nAutores; i++) {
        for (String au : autores) {
            if (autor.equalsIgnoreCase(au))
                return false;
        }

        //if (nAutores >= autores.length) {
            //String [] novoAutores = new String[autores.length + INC_AUTORES];
            //System.arraycopy(autores, 0, novoAutores, 0, autores.length);
            //autores = novoAutores;

            //autores = Arrays.copyOf(autores, autores.length + INC_AUTORES);
        //}

        //autores[nAutores++] = autor;
        autores.add(autor);
        return true;
    }

    public boolean removeAutor(String autor) {
        /*for (int i = 0; i < nAutores; i++) {
            if (autor.equalsIgnoreCase(autores[i])) {
                for (int j = i; j < nAutores - 1; j++) {
                    autores[j] = autores[j + 1];
                }

                autores[--nAutores] = null;
                break;
            }
        }

        if (autores.length >= nAutores + 2 * INC_AUTORES) {
            autores = Arrays.copyOf(autores, nAutores - INC_AUTORES);
        }

        return false;*/

        autores.remove(autor);
        return autores.contains(autor);
    }

    //public int getTamMaxAutores() {
    //    return autores.length;
    //}

    public void acrescentaTexto(String frase) {
        if (texto == null)
            texto = new StringBuffer();

        texto.append(frase);
    }

    public int contaPalavras() {
        //StringTokenizer st = new StringTokenizer(texto.toString(), " \t\n.,");
        //return st.countTokens();

        //String [] palavras = texto.toString().trim().split("[\\s,.]+");
        //return palavras.length();

        Scanner sc = new Scanner(texto.toString());
        sc.useDelimiter("[\\s,.]+");
        int i = 0;
        while (sc.hasNext()) {
            i++;
            sc.next();
        }

        return i;
    }
}
