package com.google.engedu.puzzle8;

import android.graphics.Bitmap;
import android.graphics.Canvas;

import java.util.ArrayList;


public class PuzzleBoard {

    //int to represent the number of steps required to reach the given state
    private int steps = 0;
    //A PuzzleBoard object called previousBoard referring to the previous
    //state of the board before reaching the current state
    private PuzzleBoard previousBoard;

    private static final int NUM_TILES = 3;
    //a constant array storing the relative coords of all the neighbors of one tile.
    //This will make possible to check neighbors with a for-loop rather than 4 if-statements.
    private static final int[][] NEIGHBOUR_COORDS = {
            { -1, 0 },  //left
            { 1, 0 },   //right
            { 0, -1 },  //down
            { 0, 1 }    //up
    };
    private ArrayList<PuzzleTile> tiles;

    //Constructor. This should handle breaking up the given image into tile-sized chunks.
    PuzzleBoard(Bitmap bitmap, int parentWidth) {
        int count = 0;
        tiles = new ArrayList<>();
        //Scaled the picture to a square
        Bitmap scaledPic = bitmap.createScaledBitmap(bitmap, parentWidth, parentWidth, false);
        for(int i = 0; i < NUM_TILES; ++i)
        {
            for(int j = 0; j < NUM_TILES; ++j)
            {
                //make a slice of the scaled picture (slicing to get NUM_TILES x NUM_TILES board)
                int width = parentWidth/NUM_TILES;
                int x = i * width;
                int y = j * width;
                Bitmap slice = bitmap.createBitmap(scaledPic, x, y, width, width);
                //create a new tile using that slice
                PuzzleTile newTile = new PuzzleTile(slice, count);
                //add the new tile to the tiles array
                tiles.add(newTile);
                count++;
            }
        }
        tiles.set((NUM_TILES*NUM_TILES) - 1, null);
    }

    //Copy constructor. This constructor creates a puzzle board that copies the
    //state of another puzzle board. This will be handy when implementing neighbors below.
    PuzzleBoard(PuzzleBoard otherBoard) {
        tiles = (ArrayList<PuzzleTile>) otherBoard.tiles.clone();
        steps = 1 + otherBoard.steps;
        previousBoard = otherBoard;
    }

    //Part of the solver functionality
    public void reset() {
        // Nothing for now but you may have things to reset once you implement the solver.
    }

    //Tests whether two boards are equal by checking whether their tile configuration is the same.
    @Override
    public boolean equals(Object o) {
        if (o == null)
            return false;
        return tiles.equals(((PuzzleBoard) o).tiles);
    }

    //Called by PuzzleBoardView's onDraw. Makes each tile draw itself.
    public void draw(Canvas canvas) {
        if (tiles == null) {
            return;
        }
        for (int i = 0; i < NUM_TILES * NUM_TILES; i++) {
            PuzzleTile tile = tiles.get(i);
            if (tile != null) {
                tile.draw(canvas, i % NUM_TILES, i / NUM_TILES);
            }
        }
    }

    //Called by PuzzleBoardView's onTouchEvent. Determines which tile was clicked and attempts to move it.
    public boolean click(float x, float y) {
        for (int i = 0; i < NUM_TILES * NUM_TILES; i++) {
            PuzzleTile tile = tiles.get(i);
            if (tile != null) {
                if (tile.isClicked(x, y, i % NUM_TILES, i / NUM_TILES)) {
                    return tryMoving(i % NUM_TILES, i / NUM_TILES);
                }
            }
        }
        return false;
    }

    //helper for click.
    private boolean tryMoving(int tileX, int tileY) {
        for (int[] delta : NEIGHBOUR_COORDS) {
            int nullX = tileX + delta[0];
            int nullY = tileY + delta[1];
            if (nullX >= 0 && nullX < NUM_TILES && nullY >= 0 && nullY < NUM_TILES &&
                    tiles.get(XYtoIndex(nullX, nullY)) == null) {
                swapTiles(XYtoIndex(nullX, nullY), XYtoIndex(tileX, tileY));
                return true;
            }

        }
        return false;
    }

    //Checks whether the current board is solved. This is the reason why we store indexes in each tile.
    public boolean resolved() {
        for (int i = 0; i < NUM_TILES * NUM_TILES - 1; i++) {
            PuzzleTile tile = tiles.get(i);
            if (tile == null || tile.getNumber() != i)
                return false;
        }
        return true;
    }

    //helper method to convert between two-dimensional coordinates and positions in the ArrayList.
    private int XYtoIndex(int x, int y) {
        return x + y * NUM_TILES;
    }

    //private helper to swap between 2 tiles
    protected void swapTiles(int i, int j) {
        PuzzleTile temp = tiles.get(i);
        tiles.set(i, tiles.get(j));
        tiles.set(j, temp);
    }

    //will create a list of all board configurations that can be reached by moving a single tile in the current board.
    public ArrayList<PuzzleBoard> neighbours()
    {
        ArrayList<PuzzleBoard> results = new ArrayList<>();
        PuzzleBoard newBoard;
        PuzzleTile nullTile = null;

        int nullTileIndex = 0;

        for (int i = 0; i < tiles.size(); i++) {
            if(tiles.get(i) == null) {
                nullTileIndex = i;
                break;
            }
        }

        int tileX = nullTileIndex / NUM_TILES;
        int tileY = nullTileIndex % NUM_TILES;

        for (int[] delta : NEIGHBOUR_COORDS)
        {
            int nullX = tileX + delta[0];
            int nullY = tileY + delta[1];
            if (nullX >= 0 && nullX < NUM_TILES && nullY >= 0 && nullY < NUM_TILES)
            {
                newBoard = new PuzzleBoard(this);
                newBoard.tryMoving(nullX, nullY);
                results.add(newBoard);
            }
        }
        return results;
    }

    //computes the priority of the current board. This will be explained as part of the instructions for the solver.
    public int priority()
    {
        int manhatDist = 0;
        int xDiff = 0;
        int yDiff = 0;

        for (int i = 0; i < NUM_TILES; i++ )
        {
            for(int j = 0; j < tiles.size(); j++)
            {
                xDiff = Math.abs((tiles.get(j).getNumber() % NUM_TILES) - i);
                yDiff = Math.abs((tiles.get(j).getNumber() / NUM_TILES) - i);
                manhatDist += xDiff;
                manhatDist += yDiff;
            }
        }

        return manhatDist;
    }



}
