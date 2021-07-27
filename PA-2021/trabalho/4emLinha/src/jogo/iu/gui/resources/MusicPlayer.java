package jogo.iu.gui.resources;

import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.util.Duration;

public class MusicPlayer {
    static MediaPlayer mp;

    private MusicPlayer() {}

    public static void playMusic(String name) {
        String path = Resources.getResourceFileName("sounds/"+name);

        if (path == null || path.isEmpty()) return;

        Media music = new Media(path);
        mp = new MediaPlayer(music);
        mp.setStartTime(Duration.ZERO);
        mp.setStopTime(music.getDuration());
        mp.setAutoPlay(true);
    }
}