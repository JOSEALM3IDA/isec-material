package labirintojfx.logica;



// Esta é a classe contexto da FSM
// AKA "Casca" e "Dispositivo" e "state machine"

// tem a máquina de estados + dados
// save/load (Se houver) actuam sobre e apenas um objecto desta classe
// save/load são funções que transcendem esta classe e não constam aqui
// - actuam *sobre* esta classe a partir do exteriror dela

import labirintojfx.logica.estados.AguardaConfig;
import labirintojfx.logica.estados.ILabEstado;
import labirintojfx.logica.modelo.LabirintoGameData;

import java.util.ArrayList;
import java.util.List;

public class LabirintoGameFSM {
    private ILabEstado estado;
    private final LabirintoGameData gameData;
    List<PropsID> eventos = new ArrayList<>();

    private boolean defineEstado(ILabEstado prox) {
        ILabEstado anterior = estado;
        estado = prox;
        if (anterior != prox) {
            eventos.add(PropsID.PROP_ESTADO);
            return true;
        }
        return false;
    }

    // --------------------
    public LabirintoGameFSM() {
        gameData = new LabirintoGameData();
        estado = new AguardaConfig(gameData);
    }

    // --------------------
    public List<PropsID> configura(String nome, int dificuldade) {
        eventos.clear();
        defineEstado(estado.configura(nome, dificuldade));
        return eventos;
    }

    public List<PropsID> up() {
        eventos.clear();
        if (!defineEstado(estado.up()))
            eventos.add(PropsID.PROP_MOVE);
        return eventos;
    }

    public List<PropsID> down() {
        eventos.clear();
        if (!defineEstado(estado.down()))
            eventos.add(PropsID.PROP_MOVE);
        return eventos;
    }

    public List<PropsID> left() {
        eventos.clear();
        if (!defineEstado(estado.left()))
            eventos.add(PropsID.PROP_MOVE);
        return eventos;
    }

    public List<PropsID> right() {
        eventos.clear();
        if (!defineEstado(estado.right()))
            eventos.add(PropsID.PROP_MOVE);
        return eventos;
    }

    public List<PropsID> recomeca() {
        eventos.clear();
        defineEstado(estado.recomeca());
        return eventos;
    }

    public List<String> getVisibleMap() { return gameData.getVisibleMap(); }

    public Situacao getSituacao() { return estado.getSituacao(); }
    public String getNomeJogador() { return gameData.getNomeJogador(); }

}
