package labirintojfx.logica;

import java.beans.PropertyChangeListener;
import java.beans.PropertyChangeSupport;
import java.util.List;

public class LabirintoGameObs {
    private LabirintoGameFSM game = new LabirintoGameFSM();
    private PropertyChangeSupport props = new PropertyChangeSupport(game);

    private void disparaEventos(List<PropsID> eventos) {
        eventos.forEach((e) -> {
            props.firePropertyChange(e.toString(), null, null);
        });
        //for (var e: eventos)
        //    props.firePropertyChange(e.toString(), null, null);
    }

    public void registaPropertyChangeListener(PropsID prop, PropertyChangeListener listener) {
        props.addPropertyChangeListener(prop.toString(), listener);
    }

    public void configura(String nome, int dif) { disparaEventos(game.configura(nome,dif)); }

    public void up() { disparaEventos(game.up());
        // props.firePropertyChange("prop_move", null, null) ;
         }
    public void down() { disparaEventos(game.down());}
    public void left() { disparaEventos(game.left()); }
    public void right() { disparaEventos(game.right()); }

    public void recomeca() { disparaEventos(game.recomeca()); }

    public List<String> getVisibleMap() { return game.getVisibleMap(); }

    public Situacao getSituacao() { return game.getSituacao(); }
    public String getNomeJogador() { return game.getNomeJogador(); }

}
