package jogo.logica.estados;

import jogo.logica.dados.QuatroEmLinhaGestor;
import jogo.utils.Constantes;
import jogo.utils.Utils;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.List;

public class FimJogo extends EstadoAdapter {

    protected FimJogo(QuatroEmLinhaGestor quatroEmLinhaGestor) {
        super(quatroEmLinhaGestor);

        if (quatroEmLinhaGestor.isReplayAtivo()) return;

        gravarReplay(quatroEmLinhaGestor);
    }

    private void gravarReplay(QuatroEmLinhaGestor quatroEmLinhaGestor) {
        List<String> replaysExistentes = Utils.getFicheirosNoDiretorio(Constantes.REPLAY_PATH);
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy.MM.dd-HH.mm.ss");
        LocalDateTime ldt = LocalDateTime.now();
        String nomeNovoFicheiro = Constantes.REPLAY_PATH + dtf.format(ldt);

        if (replaysExistentes.size() < Constantes.NUM_MAX_REPLAYS) {
            Utils.gravarObjeto(nomeNovoFicheiro, quatroEmLinhaGestor);
            return;
        }

        String oldest = null;
        long oldestData = 0;
        for (var replay : replaysExistentes) {

            File replayFicheiro = new File(replay);

            if (oldest == null) {
                oldest = replay;
                oldestData = replayFicheiro.lastModified();
                continue;
            }

            if (replayFicheiro.lastModified() < oldestData) {
                oldest = replay;
                oldestData = replayFicheiro.lastModified();
            }
        }

        try {
            Files.delete(Path.of(Constantes.REPLAY_PATH + oldest));
        } catch (IOException ioe) { /* ignored */ }

        Utils.gravarObjeto(nomeNovoFicheiro, quatroEmLinhaGestor);
    }

    @Override
    public Estado iniciarJogo() {
        quatroEmLinhaGestor.resetTotal();
        return new PedeConfiguracao(quatroEmLinhaGestor);
    }

    @Override
    public Estado continuarJogo(QuatroEmLinhaGestor quatroEmLinhaGestor) {
        this.quatroEmLinhaGestor = quatroEmLinhaGestor;
        return new PedeDecisaoJogada(quatroEmLinhaGestor);
    }

    @Override
    public Estado verReplay(QuatroEmLinhaGestor quatroEmLinhaGestor) {
        this.quatroEmLinhaGestor = quatroEmLinhaGestor;
        return new AssisteJogada(quatroEmLinhaGestor);
    }

    @Override
    public Estado voltar() {
        quatroEmLinhaGestor.resetTotal();
        return new PedeDecisaoInicio(quatroEmLinhaGestor);
    }

    @Override
    public Situacao getSituacao() { return Situacao.FimJogo; }
}
