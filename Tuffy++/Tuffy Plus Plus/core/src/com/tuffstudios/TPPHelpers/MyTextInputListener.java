package com.tuffstudios.TPPHelpers;

import com.badlogic.gdx.Input.TextInputListener;

public class MyTextInputListener  implements TextInputListener {
    @Override
    public void input (String text) {
        AssetLoader.setPlayerName(text);
    }
    @Override
    public void canceled(){
        AssetLoader.setPlayerName("Tuffy");
    }
}
