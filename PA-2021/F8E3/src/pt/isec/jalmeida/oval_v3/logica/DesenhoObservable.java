package pt.isec.jalmeida.oval_v3.logica;

import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeSupport;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.List;

public class DesenhoObservable {

    public static final String DESENHO = "Desenho";
    public static final String TIPO_FIGURA = "TipoFigura";
    public static final String COR = "Cor";

    private Desenho desenho;
    private final PropertyChangeSupport pcs;

    public DesenhoObservable() {
        desenho = new Desenho();
        pcs = new PropertyChangeSupport(this);
    }

    public void addObserver(String property, PropertyChangeListener listener) {
        pcs.addPropertyChangeListener(property, listener);
    }


    public void setRGB(double r, double g, double b) {
        desenho.setRGB(r, g, b);
        pcs.firePropertyChange(COR, 0, 1);
    }

    public void setTipo(Figura.TipoFigura tipo) {
        desenho.setTipo(tipo);
        pcs.firePropertyChange(TIPO_FIGURA, 0, 1);
    }

    public Figura.TipoFigura getTipo() { return desenho.getTipo(); }
    public double getR() { return desenho.getR(); }
    public double getG() { return desenho.getG(); }
    public double getB() { return desenho.getB(); }

    public void inicia(double x, double y) {
        desenho.inicia(x, y);
        pcs.firePropertyChange(DESENHO, 0, 1);
    }
    public void altera(double x, double y) {
        desenho.altera(x, y);
        pcs.firePropertyChange(DESENHO, 0, 1);
    }

    public void termina(double x, double y) {
        desenho.termina(x, y);
        pcs.firePropertyChange(DESENHO, 0, 1);
    }

    public void apagaUltima() {
        desenho.apagaUltima();
        pcs.firePropertyChange(DESENHO, 0, 1);
    }

    public void apagaTudo() {
        desenho.apagaTudo();
        pcs.firePropertyChange(DESENHO, 0, 1);
    }
    public List<Figura> getLista() { return desenho.getLista(); }
    public Figura getAtual() { return desenho.getAtual(); }

    // Esta é das funções que se deve evitar fazer
    // Só está aqui pq o código está mal feito
    public void atualizaTudo() {
        pcs.firePropertyChange(DESENHO, null, null);
        pcs.firePropertyChange(COR, null, null);
        pcs.firePropertyChange(TIPO_FIGURA, null, null);
    }

    private static final String FILENAME = "desenho.dat";

    public void ler() {
        try {
            ObjectInputStream ois = new ObjectInputStream(new FileInputStream(FILENAME));
            desenho = (Desenho) ois.readObject();
            ois.close();
        } catch (Exception e) {
            desenho = new Desenho();
        }
        //pcs.firePropertyChange(DESENHO,null,null);
        atualizaTudo();
    }

    public void gravar() {
        try {
            ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(FILENAME));
            oos.writeObject(desenho);
            oos.close();
        } catch (Exception ignored) {}
    }
}
