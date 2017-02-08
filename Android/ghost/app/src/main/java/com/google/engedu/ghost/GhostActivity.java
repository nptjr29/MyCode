package com.google.engedu.ghost;

import android.content.res.AssetManager;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.io.IOException;
import java.io.InputStream;
import java.util.Random;


public class GhostActivity extends AppCompatActivity {
    private static final String COMPUTER_TURN = "Computer's turn";
    private static final String USER_TURN = "Your turn";
    private GhostDictionary dictionary;
    private boolean userTurn = false;
    private String wordFrag = "";
    Button resetButton;
    Button challengeButton;
    private boolean compChallenge = false;

    private Random random = new Random();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_ghost);
        resetButton = (Button) findViewById(R.id.resetButton);
        challengeButton = (Button) findViewById(R.id.challengeButton);
        AssetManager assetManager = getAssets();
        try {
            InputStream inputStream = assetManager.open("example.txt");
            dictionary = new FastDictionary(inputStream);
        } catch (IOException e) {
            Toast toast = Toast.makeText(this, "Could not load dictionary", Toast.LENGTH_LONG);
            toast.show();
        }
        onStart(null);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_ghost, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    @Override
    public boolean onKeyUp(int keyCode, KeyEvent event)
    {
        userTurn = true;
        if(compChallenge)
            challengeButton.setClickable(false);

        TextView text = (TextView) findViewById(R.id.ghostText);
//        TextView test = (TextView) findViewById(R.id.testStatus);
        TextView status = (TextView) findViewById(R.id.gameStatus);
        char pressedKey = (char) event.getDisplayLabel();
        if(keyCode >= KeyEvent.KEYCODE_A && keyCode <= KeyEvent.KEYCODE_Z){
            wordFrag += Character.toString(pressedKey);
            text.setText(wordFrag);
//            if(dictionary.isWord(wordFrag.toLowerCase()))
//                status.setText("This is a valid word.");
//            else
//                status.setText("This is not a valid word.");

//            if(wordFrag.equalsIgnoreCase("BONE"))
//                test.setText("True");
            userTurn = false;
            computerTurn();
            return super.onKeyUp(keyCode, event);
        }
        else
            return super.onKeyUp(keyCode, event);
    }


        /**
         * Handler for the "Reset" button.
         * Randomly determines whether the game starts with a user turn or a computer turn.
         * @param view
         * @return true
         */
    public boolean onStart(View view) {
        userTurn = random.nextBoolean();
//        userTurn = true;
        compChallenge = false;
        TextView text = (TextView) findViewById(R.id.ghostText);
        text.setText(wordFrag);
        TextView label = (TextView) findViewById(R.id.gameStatus);
        if (userTurn) {
            label.setText(USER_TURN);
        } else {
            label.setText(COMPUTER_TURN);
            computerTurn();
        }
        return true;
    }

    public void resetGame(View v)
    {
        onStart(v);
        wordFrag = "";
        TextView text = (TextView) findViewById(R.id.ghostText);
        text.setText(wordFrag);
        compChallenge = false;
        challengeButton.setClickable(true);

    }

    public void challengeComputer(View v) {
        TextView label = (TextView) findViewById(R.id.gameStatus);
        TextView ghost = (TextView) findViewById(R.id.ghostText);
        if (wordFrag.length() >= 4 && dictionary.isWord(wordFrag.toLowerCase()))
            label.setText("User Wins");
        else if(dictionary.getAnyWordStartingWith(wordFrag) != null)
        {
            label.setText("Computer Wins");
            String result = dictionary.getAnyWordStartingWith(wordFrag);
            ghost.setText(result);
        }
        else
        {
            label.setText("User Wins");
        }

    }

    private void computerTurn() {
        TextView label = (TextView) findViewById(R.id.gameStatus);
        TextView compTurn = (TextView) findViewById(R.id.ghostText);
        userTurn = false;
        // Do computer turn stuff then make it the user's turn again
        if(wordFrag.length() >= 4 && label.getText() == "Computer Challenged the Player." && !dictionary.isWord(wordFrag.toLowerCase()))
        {
            label.setText("Computer Wins");
            userTurn = true;
        }

        if(!userTurn && wordFrag.length() >= 4 && dictionary.isWord(wordFrag.toLowerCase())) {
            label.setText("Computer Wins");
            userTurn = true;
            label.setText(USER_TURN);
        }
        else
        {
            if(!userTurn && wordFrag.length() >= 4 && dictionary.getAnyWordStartingWith(wordFrag) == null)
            {
                label.setText("Computer Challenged the Player.");
                userTurn = true;
            }
            else if(!userTurn)
            {
                Integer length = wordFrag.length();
                String nextLetter = (dictionary.getAnyWordStartingWith(wordFrag.toLowerCase()).substring(length, length + 1));
                wordFrag += nextLetter.toUpperCase();
                compTurn.setText(wordFrag);
                userTurn = true;
                label.setText(USER_TURN);
            }

        }



//        if (wordFrag.isEmpty() && !userTurn)
//        {
//            wordFrag = "A";
//            compTurn.setText(wordFrag);
//            userTurn = true;
//            label.setText(USER_TURN);
//        }

//        else if (wordFrag.length() < 4)
//        {
//            Integer length = wordFrag.length();
//            if ((dictionary.getAnyWordStartingWith(wordFrag.toLowerCase()).substring(length, length + 1)) == null)
//                wordFrag += "Z";
//            else
//            {
//                String nextLetter = (dictionary.getAnyWordStartingWith(wordFrag.toLowerCase()).substring(length, length + 1));
//                wordFrag += nextLetter.toUpperCase();
//            }
//            compTurn.setText(wordFrag);
//            label.setText(USER_TURN);
//
//        }
//        else
//        {
//            if (dictionary.getAnyWordStartingWith(wordFrag.toLowerCase()) == null)
//            {
//                label.setText("Computer Challenges the User.");
//                compChallenge = true;
//                challengeButton.setClickable(false);
//            }
//            else
//            {
//                Integer length = wordFrag.length();
//                if ((dictionary.getAnyWordStartingWith(wordFrag.toLowerCase()).substring(length, length + 1)) == null)
//                    wordFrag += "Z";
//                else
//                {
//                    String nextLetter = (dictionary.getAnyWordStartingWith(wordFrag.toLowerCase()).substring(length, length + 1));
//                    wordFrag += nextLetter.toUpperCase();
//                }
//                compTurn.setText(wordFrag);
//                label.setText(USER_TURN);
//            }
//        }

        userTurn = true;
//        label.setText(USER_TURN);
    }
}
