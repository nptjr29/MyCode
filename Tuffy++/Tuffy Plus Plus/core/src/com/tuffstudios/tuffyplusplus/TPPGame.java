package com.tuffstudios.tuffyplusplus;
import com.badlogic.gdx.Game;
import com.badlogic.gdx.Gdx;
import com.tuffstudios.Screens.SplashScreen;
import com.tuffstudios.TPPHelpers.AssetLoader;

import static com.tuffstudios.TPPHelpers.AssetLoader.bgmusic;

//private Music music_level1;
public class TPPGame extends Game {
    @Override
    public void create() {
        AssetLoader.load();
        setScreen(new SplashScreen(this));
        //music_level1 = Gdx.audio.newMusic(Gdx.files.internal("level1.ogg"));

    }

    @Override
    public void dispose() {
        super.dispose();
        AssetLoader.dispose();
    }
}