package com.example.scarnesdice;

import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import com.google.android.gms.appindexing.Action;
import com.google.android.gms.appindexing.AppIndex;
import com.google.android.gms.common.api.GoogleApiClient;

import java.util.Random;

public class MainActivity extends AppCompatActivity {

    TextView message;
    public Integer userOverallScore = 0;
    public Integer userTurnScore = 0;
    public Integer compOverallScore = 0;
    public Integer compTurnScore = 0;
    private Random rng = new Random(); //generates a random number
    private Random rng2 = new Random();
    ImageView dicePicture;
    public Integer roll = 0;
    Boolean userTurn = true;
    //Boolean compTurn = false;
    Button rollButton;

    /**
     * ATTENTION: This was auto-generated to implement the App Indexing API.
     * See https://g.co/AppIndexing/AndroidStudio for more information.
     */
    private GoogleApiClient client;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        dicePicture = (ImageView) findViewById(R.id.dice1);
        message = (TextView) findViewById(R.id.scoring);
        rollButton = (Button) findViewById(R.id.rollButton);
        // ATTENTION: This was auto-generated to implement the App Indexing API.
        // See https://g.co/AppIndexing/AndroidStudio for more information.
        client = new GoogleApiClient.Builder(this).addApi(AppIndex.API).build();
    }

    /*Called when user click Roll button*/
    public void rollDice(View view) {
        int diceUNum = (rng.nextInt(6) + 1);
        String msg;
        if (diceUNum == 1)
        {
            dicePicture.setImageResource(R.drawable.dice1);
            //roll = 1;
            userTurnScore = 0;
            msg = "Your score: " + Integer.toString(userOverallScore) + " Computer's score: " + Integer.toString(compOverallScore) + " You rolled a 1";
            message.setText(msg);
            userTurn = false;
            //compTurn = true;
        }
        else
        {
            switch (diceUNum) {
                case 2:
                    dicePicture.setImageResource(R.drawable.dice2);
                    roll = 2;
                    userTurnScore += 2;
                    msg = "Your score: " + Integer.toString(userOverallScore) + " Computer's score: " + Integer.toString(compOverallScore) + " Your turn's score: " + Integer.toString(userTurnScore);
                    message.setText(msg);
                    break;
                case 3:
                    dicePicture.setImageResource(R.drawable.dice3);
                    roll = 3;
                    userTurnScore += 3;
                    msg = "Your score: " + Integer.toString(userOverallScore) + " Computer's score: " + Integer.toString(compOverallScore) + " Your turn's score: " + Integer.toString(userTurnScore);
                    message.setText(msg);
                    break;
                case 4:
                    dicePicture.setImageResource(R.drawable.dice4);
                    roll = 4;
                    userTurnScore += 4;
                    //userOverallScore += userTurnScore;
                    msg = "Your score: " + Integer.toString(userOverallScore) + " Computer's score: " + Integer.toString(compOverallScore) + " Your turn's score: " + Integer.toString(userTurnScore);
                    message.setText(msg);
                    break;
                case 5:
                    dicePicture.setImageResource(R.drawable.dice5);
                    roll = 5;
                    userTurnScore += 5;
                    msg = "Your score: " + Integer.toString(userOverallScore) + " Computer's score: " + Integer.toString(compOverallScore) + " Your turn's score: " + Integer.toString(userTurnScore);
                    message.setText(msg);
                    break;
                case 6:
                    dicePicture.setImageResource(R.drawable.dice6);
                    roll = 6;
                    userTurnScore += 6;
                    msg = "Your score: " + Integer.toString(userOverallScore) + " Computer's score: " + Integer.toString(compOverallScore) + " Your turn's score: " + Integer.toString(userTurnScore);
                    message.setText(msg);
                    break;
                default:
                    msg = "Your score: 0 Computer score: 0";
                    message.setText(msg);
            }

        }
        if (!userTurn) {
            userOverallScore += userTurnScore;
            userTurnScore = 0;
        }
        while(!userTurn)
        {
            rollButton.setClickable(false);
            compTurn();
        }

        if (userOverallScore >= 100)
            gameOver();
        if (compOverallScore >= 100)
            gameOver();

    }


    /*Called when user click Hold button*/
    public void holdTurn(View view) {
        String msg;
        //compTurn = true;
        userTurn = false;
        userOverallScore += userTurnScore;
        userTurnScore = 0;
        while (!userTurn && compTurnScore <= 20)
        {
            compTurn();
        }
        if (compTurnScore > 20)
        {
            compOverallScore += compTurnScore;
            msg = "Your score: " + Integer.toString(userOverallScore) + " Computer's score: " + Integer.toString(compOverallScore) + " Computer held.";
            compTurnScore = 0;
            userTurn = true;
            rollButton.setClickable(true);
            //compTurn = false;
            message.setText(msg);
        }

        if (userOverallScore >= 100)
            gameOver();
        if (compOverallScore >= 100)
            gameOver();
    }

    /*Called when user click Reset button*/
    public void resetGame(View view) {
        userTurn = true;
        rollButton.setClickable(true);
        //compTurn = false;
        userOverallScore = 0;
        userTurnScore = 0;
        compOverallScore = 0;
        compTurnScore = 0;
        message.setText("Your score: 0 Computer score: 0");

    }

    /*helper functions */
    public void compTurn() {
        rollButton.setClickable(false);
        int diceNum = (rng2.nextInt(6) + 1);
        diceNum = (rng2.nextInt(6) + 1);
        String msg;
        if (diceNum == 1) {
            //roll = 1;
            compTurnScore = 0;
            //compOverallScore += compTurnScore;
            msg = "Your score: " + Integer.toString(userOverallScore) + " Computer's score: " + Integer.toString(compOverallScore) + " Computer rolled a 1";
            message.setText(msg);
            userTurn = true;
            rollButton.setClickable(true);
            //compTurn = false;
        } else {
            switch (diceNum) {
                case 2:
                    roll = 2;
                    compTurnScore += 2;
                    break;
                case 3:
                    roll = 3;
                    compTurnScore += 3;
                    break;
                case 4:
                    roll = 4;
                    compTurnScore += 4;
                    break;
                case 5:
                    roll = 5;
                    compTurnScore += 5;
                    break;
                case 6:
                    roll = 6;
                    compTurnScore += 6;
                    break;
                default:
            }
        }
//        if(userTurn)
//        {
//            compOverallScore += compTurnScore;
//            compTurnScore = 0;
//        }

        if (userOverallScore >= 100)
            gameOver();
        if (compOverallScore >= 100)
            gameOver();
    }

    public void gameOver()
    {
        if (userOverallScore >= 100)
        {
            message.setText("You Win!");
        }
        else if (compOverallScore >= 100)
        {
            message.setText("Computer Wins!");
        }
    }





    @Override
    public void onStart() {
        super.onStart();

        // ATTENTION: This was auto-generated to implement the App Indexing API.
        // See https://g.co/AppIndexing/AndroidStudio for more information.
        client.connect();
        Action viewAction = Action.newAction(
                Action.TYPE_VIEW, // TODO: choose an action type.
                "Main Page", // TODO: Define a title for the content shown.
                // TODO: If you have web page content that matches this app activity's content,
                // make sure this auto-generated web page URL is correct.
                // Otherwise, set the URL to null.
                Uri.parse("http://host/path"),
                // TODO: Make sure this auto-generated app URL is correct.
                Uri.parse("android-app://com.example.scarnesdice/http/host/path")
        );
        AppIndex.AppIndexApi.start(client, viewAction);
    }

    @Override
    public void onStop() {
        super.onStop();

        // ATTENTION: This was auto-generated to implement the App Indexing API.
        // See https://g.co/AppIndexing/AndroidStudio for more information.
        Action viewAction = Action.newAction(
                Action.TYPE_VIEW, // TODO: choose an action type.
                "Main Page", // TODO: Define a title for the content shown.
                // TODO: If you have web page content that matches this app activity's content,
                // make sure this auto-generated web page URL is correct.
                // Otherwise, set the URL to null.
                Uri.parse("http://host/path"),
                // TODO: Make sure this auto-generated app URL is correct.
                Uri.parse("android-app://com.example.scarnesdice/http/host/path")
        );
        AppIndex.AppIndexApi.end(client, viewAction);
        client.disconnect();
    }
}
