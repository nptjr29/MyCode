package com.google.engedu.puzzle8;

import android.graphics.Bitmap;
import android.graphics.Canvas;


public class PuzzleTile {

    private Bitmap bitmap;
    private int number;

    //Simple constructor that stores the given index and bitmap.
    public PuzzleTile(Bitmap bitmap, int number){
        this.bitmap = bitmap;
        this.number = number;
    }

    //Getter for the tile index.
    public int getNumber() {
        return number;
    }

    public void draw(Canvas canvas, int x, int y) {
        //Draws the bitmap on the given canvas at the given location.
        canvas.drawBitmap(bitmap, x * bitmap.getWidth(), y * bitmap.getHeight(), null);
    }

    //Determines whether the touch location falls within the tile.
    public boolean isClicked(float clickX, float clickY, int tileX, int tileY) {
        int tileX0 = tileX * bitmap.getWidth();
        int tileX1 = (tileX + 1) * bitmap.getWidth();
        int tileY0 = tileY * bitmap.getWidth();
        int tileY1 = (tileY + 1) * bitmap.getWidth();
        return (clickX >= tileX0) && (clickX < tileX1) && (clickY >= tileY0) && (clickY < tileY1);
    }
}
