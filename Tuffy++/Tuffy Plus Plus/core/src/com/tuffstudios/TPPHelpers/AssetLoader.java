package com.tuffstudios.TPPHelpers;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Preferences;
import com.badlogic.gdx.audio.Music;
import com.badlogic.gdx.audio.Sound;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.Texture.TextureFilter;
import java.util.Random;
import com.badlogic.gdx.graphics.g2d.Animation;
import com.badlogic.gdx.graphics.g2d.BitmapFont;
import com.badlogic.gdx.graphics.g2d.TextureRegion;
import com.badlogic.gdx.utils.BooleanArray;

public class AssetLoader {
	public static Texture texture, logoTexture;
	public static TextureRegion logo, zbLogo, bg, grass, elephant, elephantDown, elephantUp, pipeUp,
			pipeDown, bar, playButtonUp, playButtonDown, ready, taptostart, gameOver, highScore,
			scoreboard, scoreboardextension, answerletterA, answerletterB, answerletterC,
			answerletterD, star, answerextension, noStar, retry, easyUp, easyDown, mediumUp,
			mediumDown,tuffUp, tuffDown, blackline, muteButtonUp, muteButtonDown, correctAnswerExtension,
			inccorrectAnswerExtension;
	public static Animation elephantAnimation;
	public static Sound dead, flap, coin, fall;
	public static Music bgmusic;
	public static float VOLUME = 1.0f;
	public static BitmapFont font, shadow, whiteFont;
	private static Preferences prefs;

	public static void load() {
		logoTexture = new Texture(Gdx.files.internal("data/logo.png"));
		logoTexture.setFilter(TextureFilter.Linear, TextureFilter.Linear);
		logo = new TextureRegion(logoTexture, 0, 0, 510, 326);

		texture = new Texture(Gdx.files.internal("data/texture.png"));
		texture.setFilter(TextureFilter.Nearest, TextureFilter.Nearest);

		playButtonUp  = new TextureRegion(texture, 1, 83, 28, 16);
		playButtonDown = new TextureRegion(texture, 29, 83, 28, 16);
		playButtonUp.flip(false, true);
		playButtonDown.flip(false, true);

		muteButtonUp = new TextureRegion(texture, 209, 83, 46, 37);
		muteButtonDown = new TextureRegion(texture, 209, 121, 46, 37);
		muteButtonUp.flip(false, true);
		muteButtonDown.flip(false, true);

		easyUp  = new TextureRegion(texture, 136, 24, 28, 16);
		easyDown = new TextureRegion(texture, 1, 129, 28, 16);
		easyUp.flip(false, true);
		easyDown.flip(false, true);

		mediumUp  = new TextureRegion(texture, 165, 43, 78, 36);
		mediumDown = new TextureRegion(texture, 92, 120, 78, 36);
		mediumUp.flip(false, true);
		mediumDown.flip(false, true);

		tuffUp  = new TextureRegion(texture, 164, 24, 28, 16);
		tuffDown = new TextureRegion(texture, 29, 129, 28, 16);
		tuffUp.flip(false, true);
		tuffDown.flip(false, true);

		ready = new TextureRegion(texture, 62, 84, 37, 7);
		ready.flip(false, true);

		taptostart = new TextureRegion(texture, 10, 117, 84, 11);
		taptostart.flip(false, true);

		retry = new TextureRegion(texture, 62, 108, 38, 7);
		retry.flip(false, true);
		
		gameOver = new TextureRegion(texture, 59, 92, 51, 7);
		gameOver.flip(false, true);

		scoreboard = new TextureRegion(texture, 181, 84, 27, 35);
		scoreboard.flip(false, true);

		scoreboardextension = new TextureRegion(texture, 115, 85, 50, 30);
		scoreboardextension.flip(false, true);

		// Textures for Answer Boxes
		answerletterA = new TextureRegion(texture, 193, 23, 13, 17);
		answerletterA.flip(false, true);
		answerletterB = new TextureRegion(texture, 207, 23, 13, 17);
		answerletterB.flip(false, true);
		answerletterC = new TextureRegion(texture, 221, 23, 13, 17);
		answerletterC.flip(false, true);
		answerletterD = new TextureRegion(texture, 235, 23, 13, 17);
		answerletterD.flip(false, true);
		answerextension = new TextureRegion(texture, 248, 23, 3, 17);
		answerextension.flip(false, true);
		correctAnswerExtension = new TextureRegion(texture, 252, 23, 1, 17);
		correctAnswerExtension.flip(false, true);
		inccorrectAnswerExtension = new TextureRegion(texture, 253, 23, 1, 17);
		inccorrectAnswerExtension.flip(false, true);
		blackline = new TextureRegion(texture, 251, 23, 1, 17);
		blackline.flip(false, true);


		star = new TextureRegion(texture, 152, 70, 10, 10);
		noStar = new TextureRegion(texture, 166 , 70, 10, 10);

		star.flip(false, true);
		noStar.flip(false, true);

		highScore = new TextureRegion(texture, 57, 100, 53, 7);
		highScore.flip(false, true);

		zbLogo = new TextureRegion(texture, 0, 55, 148, 28);
		zbLogo.flip(false, true);

		bg = new TextureRegion(texture, 0, 0, 136, 43);
		bg.flip(false, true);

		grass = new TextureRegion(texture, 0, 43, 143, 11);
		grass.flip(false, true);

		elephantDown = new TextureRegion(texture, 136, 0, 20, 13);
		elephantDown.flip(false, true);

		elephant = new TextureRegion(texture, 156, 0, 20, 13);
		elephant.flip(false, true);

		elephantUp = new TextureRegion(texture, 176, 0, 20, 13);
		elephantUp.flip(false, true);

		TextureRegion[] elephants = { elephantDown, elephant, elephantUp };
		elephantAnimation = new Animation(.55f, elephants);
		elephantAnimation.setPlayMode(Animation.PlayMode.LOOP_PINGPONG);

		pipeUp = new TextureRegion(texture, 196, 0, 24, 14);
		// Create by flipping existing pipeUp
		pipeDown = new TextureRegion(pipeUp);
		pipeDown.flip(false, true);

		bar = new TextureRegion(texture, 136, 16, 22, 3);
		bar.flip(false, true);

		dead = Gdx.audio.newSound(Gdx.files.internal("data/dead.wav"));
		flap = Gdx.audio.newSound(Gdx.files.internal("data/flap.wav"));
		coin = Gdx.audio.newSound(Gdx.files.internal("data/coin.wav"));
		fall = Gdx.audio.newSound(Gdx.files.internal("data/fall.wav"));
		randomSong();

		font = new BitmapFont(Gdx.files.internal("data/text.fnt"));
		font.getData().setScale(.25f, -.25f);

		whiteFont = new BitmapFont(Gdx.files.internal("data/whitetext.fnt"));
		whiteFont.getData().setScale(.1f, -.1f);

		shadow = new BitmapFont(Gdx.files.internal("data/shadow.fnt"));
		shadow.getData().setScale(.25f, -.25f);

		// Create (or retrieve existing) preferences fil
		prefs = Gdx.app.getPreferences("Tuffy Plus Plus");

		if (!prefs.contains("highScore")) {
			prefs.putInteger("highScore", 0);
		}
	}


	public static void setHighScore(int val) {
		prefs.putInteger("highScore", val);
		prefs.flush();
	}

	public static void setPlayerName(String name) {
		prefs.putString("playername", name);
		prefs.flush();
	}

	public static void setAsked(boolean asked) {
		prefs.putBoolean("asked", asked);
		prefs.flush();
	}

	public static Boolean getAsked() { return prefs.getBoolean("asked"); }

	public static String getPlayerName() { return prefs.getString("playername"); }

	public static int getHighScore() {
		return prefs.getInteger("highScore");
	}

	public static void dispose() {
		// We must dispose of the texture when we are finished.
		texture.dispose();

		// Dispose sounds
		dead.dispose();
		flap.dispose();
		coin.dispose();
		bgmusic.dispose();

		font.dispose();
		shadow.dispose();
	}
	public static void randomSong(){
		int MAX_SONGS = 6;
		Random rn = new Random();
		int randomNumber = rn.nextInt(MAX_SONGS);
		String fileName = "bg" + randomNumber + ".mp3";
		bgmusic = Gdx.audio.newMusic(Gdx.files.internal(fileName));
	}
}