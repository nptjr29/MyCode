package com.tuffstudios.tuffyplusplus.desktop;

import com.badlogic.gdx.backends.lwjgl.LwjglApplication;
import com.badlogic.gdx.backends.lwjgl.LwjglApplicationConfiguration;
import com.tuffstudios.tuffyplusplus.TPPGame;

public class DesktopLauncher {
    public static void main (String[] arg) {
        LwjglApplicationConfiguration config = new LwjglApplicationConfiguration();
        config.title = "Tuffy Plus Plus";
        config.height = 768;
        config.width = 432;
        new LwjglApplication(new TPPGame(), config);
    }
}
