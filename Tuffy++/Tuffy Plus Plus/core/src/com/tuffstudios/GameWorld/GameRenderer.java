package com.tuffstudios.GameWorld;
import com.badlogic.gdx.ApplicationListener;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.graphics.g2d.Animation;
import com.badlogic.gdx.graphics.g2d.GlyphLayout;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.graphics.g2d.TextureRegion;
import com.badlogic.gdx.graphics.glutils.ShapeRenderer;
import com.badlogic.gdx.graphics.glutils.ShapeRenderer.ShapeType;
import com.badlogic.gdx.utils.Align;
import com.tuffstudios.GameObjects.Elephant;
import com.tuffstudios.GameObjects.Grass;
import com.tuffstudios.GameObjects.Pipe;
import com.tuffstudios.GameObjects.ScrollHandler;
import com.tuffstudios.QuestionFactory.Question;
import com.tuffstudios.QuestionFactory.QuestionRepository;
import com.tuffstudios.TPPHelpers.AssetLoader;
import com.tuffstudios.TPPHelpers.InputHandler;
import com.tuffstudios.TPPHelpers.MyTextInputListener;
import com.tuffstudios.TweenAccessors.Value;
import com.tuffstudios.TweenAccessors.ValueAccessor;
import com.tuffstudios.ui.SimpleButton;
import com.tuffstudios.ui.ToggleButton;
import java.util.List;
import aurelienribon.tweenengine.Tween;
import aurelienribon.tweenengine.TweenEquations;
import aurelienribon.tweenengine.TweenManager;

public class GameRenderer {
	private GameWorld myWorld;
	private OrthographicCamera cam;
	private ShapeRenderer shapeRenderer;
	private SpriteBatch batcher;
	private GlyphLayout layout = new GlyphLayout();
	private int midPointY;
	private boolean asked;

	// Game Objects
	private Elephant elephant;
	private ScrollHandler scroller;
	private Grass frontGrass, backGrass;
	private Pipe pipe1, pipe2, pipe3;

	// Game Assets
	private TextureRegion bg, grass, elephantMid, pipeUp, pipeDown, bar, ready, zbLogo, gameOver,
			highScore, scoreboard, scoreboardextension, answerletterA, answerletterB, answerletterC,
			answerletterD, answerextension, blackline, retry, correctAnswerExtension, inccorrectAnswerExtension,
			taptostart;
	private Animation elephantAnimation;

	// Tween stuff
	private TweenManager manager;
	private Value alpha = new Value();

	// Buttons
	private List<SimpleButton> menuButtons;
	private List<ToggleButton> difficultyButtons;
	private List<SimpleButton> questionButtons;
	private Color transitionColor;

	//Text input
	MyTextInputListener listener = new MyTextInputListener();

	public GameRenderer(GameWorld world, int gameHeight, int midPointY) {
		myWorld = world;
		this.midPointY = midPointY;

		this.menuButtons = ((InputHandler) Gdx.input.getInputProcessor()).getMenuButtons();
		this.difficultyButtons = ((InputHandler) Gdx.input.getInputProcessor()).getDifficultyButtonsButtons();
		this.questionButtons = ((InputHandler) Gdx.input.getInputProcessor()).getQuestionButtons();

		cam = new OrthographicCamera();
		cam.setToOrtho(true, 136, gameHeight);

		batcher = new SpriteBatch();
		batcher.setProjectionMatrix(cam.combined);
		shapeRenderer = new ShapeRenderer();
		shapeRenderer.setProjectionMatrix(cam.combined);

		initGameObjects();
		initAssets();
		AssetLoader.bgmusic.setLooping(true);
		AssetLoader.bgmusic.play();

		transitionColor = new Color();
		prepareTransition(255, 255, 255, .5f);
	}

	private void initGameObjects() {
		elephant = myWorld.getElephant();
		scroller = myWorld.getScroller();
		frontGrass = scroller.getFrontGrass();
		backGrass = scroller.getBackGrass();
		pipe1 = scroller.getPipe1();
		pipe2 = scroller.getPipe2();
		pipe3 = scroller.getPipe3();
	}

	private void initAssets() {
		bg = AssetLoader.bg;
		grass = AssetLoader.grass;
		elephantAnimation = AssetLoader.elephantAnimation;
		elephantMid = AssetLoader.elephant;
		pipeUp = AssetLoader.pipeUp;
		pipeDown = AssetLoader.pipeDown;
		bar = AssetLoader.bar;
		ready = AssetLoader.ready;
		zbLogo = AssetLoader.zbLogo;
		gameOver = AssetLoader.gameOver;
		highScore = AssetLoader.highScore;
		scoreboard = AssetLoader.scoreboard;
		scoreboardextension = AssetLoader.scoreboardextension;
		answerletterA = AssetLoader.answerletterA;
		answerletterB = AssetLoader.answerletterB;
		answerletterC = AssetLoader.answerletterC;
		answerletterD = AssetLoader.answerletterD;
		answerextension = AssetLoader.answerextension;
		correctAnswerExtension = AssetLoader.correctAnswerExtension;
		inccorrectAnswerExtension = AssetLoader.inccorrectAnswerExtension;
		blackline = AssetLoader.blackline;
		retry = AssetLoader.retry;
		taptostart = AssetLoader.taptostart;
	}

	private void drawRetry() {
		batcher.draw(retry, 36, midPointY + 40, 66, 14);
	}

	private void drawReady() {
		batcher.draw(ready, 36, midPointY - 50, 68, 14);
		batcher.draw(taptostart, 28, midPointY - 30, 84, 11);
	}

	private void drawGrass() {
		// Draw the grass
		batcher.draw(grass, frontGrass.getX(), frontGrass.getY(), frontGrass.getWidth(), frontGrass.getHeight());
		batcher.draw(grass, backGrass.getX(), backGrass.getY(), backGrass.getWidth(), backGrass.getHeight());
		if (scroller.isStopped()){
			drawRetry();
		}
	}

	private void drawpipes() {
		batcher.draw(pipeUp, pipe1.getX() - 1, pipe1.getY() + pipe1.getHeight() - 14, 24, 14);
		batcher.draw(pipeDown, pipe1.getX() - 1, pipe1.getY() + pipe1.getHeight() + 45, 24, 14);
		batcher.draw(pipeUp, pipe2.getX() - 1, pipe2.getY() + pipe2.getHeight() - 14, 24, 14);
		batcher.draw(pipeDown, pipe2.getX() - 1, pipe2.getY() + pipe2.getHeight() + 45, 24, 14);
		batcher.draw(pipeUp, pipe3.getX() - 1, pipe3.getY() + pipe3.getHeight() - 14, 24, 14);
		batcher.draw(pipeDown, pipe3.getX() - 1, pipe3.getY() + pipe3.getHeight() + 45, 24, 14);
	}

	private void drawPipes() {
		batcher.draw(bar, pipe1.getX(), pipe1.getY(), pipe1.getWidth(), pipe1.getHeight());
		batcher.draw(bar, pipe1.getX(), pipe1.getY() + pipe1.getHeight() + 45, pipe1.getWidth(), midPointY + 66 - (pipe1.getHeight() + 45));
		batcher.draw(bar, pipe2.getX(), pipe2.getY(), pipe2.getWidth(), pipe2.getHeight());
		batcher.draw(bar, pipe2.getX(), pipe2.getY() + pipe2.getHeight() + 45, pipe2.getWidth(), midPointY + 66 - (pipe2.getHeight() + 45));
		batcher.draw(bar, pipe3.getX(), pipe3.getY(), pipe3.getWidth(), pipe3.getHeight());
		batcher.draw(bar, pipe3.getX(), pipe3.getY() + pipe3.getHeight() + 45, pipe3.getWidth(), midPointY + 66 - (pipe3.getHeight() + 45));
	}

	private void drawElephantCentered(float runTime) {
		batcher.draw(elephantAnimation.getKeyFrame(runTime), 59, elephant.getY() - 15, elephant.getWidth() / 2.0f, elephant.getHeight() / 2.0f, elephant.getWidth(), elephant.getHeight(), 1, 1, elephant.getRotation());
	}

	private void drawElephant(float runTime) {
		if (elephant.shouldntFlap()) {
			batcher.draw(elephantMid, elephant.getX(), elephant.getY(), elephant.getWidth() / 2.0f, elephant.getHeight() / 2.0f, elephant.getWidth(), elephant.getHeight(), 1, 1, elephant.getRotation());
		} else {
			batcher.draw(elephantAnimation.getKeyFrame(runTime), elephant.getX(), elephant.getY(), elephant.getWidth() / 2.0f, elephant.getHeight() / 2.0f, elephant.getWidth(), elephant.getHeight(), 1, 1, elephant.getRotation());
		}
	}

	private void drawMenuUI() {
		batcher.draw(zbLogo, 136 / 2 - 62, midPointY - 75, zbLogo.getRegionWidth() / 1.2f, zbLogo.getRegionHeight() / 1.2f);
		for (SimpleButton button : menuButtons) {
			button.draw(batcher);
		}
	}

	private void drawTutorial() {
		batcher.draw(scoreboardextension, 16, midPointY - 90, 105, 185);
		AssetLoader.font.getData().setScale(0.11f, -0.11f);
		AssetLoader.font.draw(batcher, "" + "How to Play:\n\n1. Tap to ascend\n2. Let go to descend\n3. Avoid the obstacles\n\n\nGood Luck!", 17, midPointY / 3, 103,
				Align.center, true);
	}

	private void drawScoreboard() {

		batcher.draw(scoreboard, 40, midPointY - 50, 60, 80);
		batcher.draw(blackline, 38, midPointY - 52, 62, 2);
		batcher.draw(blackline, 38, midPointY - 52, 2, 82);

		int length = ("" + myWorld.getScore()).length();
		AssetLoader.whiteFont.getData().setScale(0.25f, -0.25f);
		AssetLoader.whiteFont.draw(batcher, "" + myWorld.getScore(), 67 - (2 * length), midPointY - 27);

		int length2 = ("" + AssetLoader.getHighScore()).length();
		AssetLoader.whiteFont.draw(batcher, "" + AssetLoader.getHighScore(), 67 - (2 * length2), midPointY + 10);
	}

	private void drawPlayerName() {

		AssetLoader.font.getData().setScale(.25f, -.25f);
		AssetLoader.shadow.getData().setScale(.249f, -.249f);
		AssetLoader.shadow.draw(batcher, "" + AssetLoader.getPlayerName(), -31, midPointY - 74, 200, Align.center, true);
		AssetLoader.font.draw(batcher, "" + AssetLoader.getPlayerName(), -31 , midPointY -75, 200, Align.center, true);

	}


	private void drawAnswers() {
		int choicesXPos = 34;
		int textBoxWidth = 80;
		AssetLoader.font.getData().setScale(0.08f, -0.08f);
		batcher.draw(scoreboardextension, 16, midPointY - 90, 105, 185);

		// Draw Answer A Box
		batcher.draw(answerletterA, 20, midPointY - 35, 13, 20);
		batcher.draw(answerextension, 33, midPointY - 35, 82, 20);
		batcher.draw(blackline, 115, midPointY - 35, 1, 20);

		// Draw Answer B Box
		batcher.draw(answerletterB, 20, midPointY - 5, 13, 20);
		batcher.draw(answerextension, 33, midPointY - 5, 82, 20);
		batcher.draw(blackline, 115, midPointY - 5, 1, 20);

		// Draw Answer C Box
		batcher.draw(answerletterC, 20, midPointY + 25, 13, 20);
		batcher.draw(answerextension, 33, midPointY + 25, 82, 20);
		batcher.draw(blackline, 115, midPointY + 25, 1, 20);

		// Draw Answer D Box
		batcher.draw(answerletterD, 20, midPointY + 55, 13, 20);
		batcher.draw(answerextension, 33, midPointY + 55, 82, 20);
		batcher.draw(blackline, 115, midPointY + 55, 1, 20);
		// Draw Answer A
		AssetLoader.font.draw(batcher, "" + myWorld.getQ().getA(), choicesXPos, midPointY - 29, textBoxWidth, Align.center, true);
		//Draw Answer B
		AssetLoader.font.draw(batcher, "" + myWorld.getQ().getB(), choicesXPos, midPointY + 1, textBoxWidth, Align.center, true);
		//Draw Answer C
		AssetLoader.font.draw(batcher, "" + myWorld.getQ().getC(), choicesXPos, midPointY + 31, textBoxWidth, Align.center, true);
		//Draw Answer D
		AssetLoader.font.draw(batcher, "" + myWorld.getQ().getD(), choicesXPos, midPointY + 61, textBoxWidth, Align.center, true);
	}

	private void drawQuestion() {
		//ADDED:
		AssetLoader.font.getData().setScale(0.07f, -0.07f);
		AssetLoader.font.draw(batcher, "" + "You died! Answer to move on:", 17, midPointY / 5, 103,
				Align.center, true);

		AssetLoader.font.getData().setScale(0.11f, -0.11f);
		AssetLoader.font.draw(batcher, "" + myWorld.getQ().getQuestion(), 17, midPointY / 3, 103,
				Align.center, true);
	}

	private void drawQuestionButtons(){
		for (SimpleButton button : questionButtons) {
			button.draw(batcher);
		}
	}

private void drawFeedback(String choice) {
	int textBoxWidth = 103;
	int choicesXPos = 34;
	int answerExtensionTextBoxWidth = 80;
	//Draws the feedback/hint
	//ADDED - UPDATED:
	AssetLoader.font.getData().setScale(0.07f, -0.07f);
	AssetLoader.font.draw(batcher, "" + myWorld.getQ().getFeedback(), 17, midPointY + 76, textBoxWidth, Align.center, true);
	//Colors the incorrect answer red
	AssetLoader.font.getData().setScale(0.08f, -0.08f);
	AssetLoader.shadow.getData().setScale(0.08f, -0.08f);

	if (choice == "A") {
		batcher.draw(inccorrectAnswerExtension, 21, midPointY - 35, 94, 20);
		AssetLoader.font.draw(batcher, "" + myWorld.getQ().getA(), choicesXPos, midPointY - 29, answerExtensionTextBoxWidth, Align.center, true);
	} else if (choice == "B") {
		batcher.draw(inccorrectAnswerExtension, 21, midPointY - 5, 94, 20);
		AssetLoader.font.draw(batcher, "" + myWorld.getQ().getB(), choicesXPos, midPointY + 1, answerExtensionTextBoxWidth, Align.center, true);
	} else if (choice == "C") {
		batcher.draw(inccorrectAnswerExtension, 21, midPointY + 25, 94, 20);
		AssetLoader.font.draw(batcher, "" + myWorld.getQ().getC(), choicesXPos, midPointY + 31, answerExtensionTextBoxWidth, Align.center, true);
	} else if (choice == "D") {
		batcher.draw(inccorrectAnswerExtension, 21, midPointY + 55, 94, 20);
		AssetLoader.font.draw(batcher, "" + myWorld.getQ().getD(), choicesXPos, midPointY + 61, answerExtensionTextBoxWidth, Align.center, true);
	}
}

	private void drawCorrect(String choice){
		int textBoxWidth = 103;
		int choicesXPos = 34;
		int answerExtensionTextBoxWidth = 80;

		//Draws "You are Correct!" text
		AssetLoader.font.draw(batcher, "" + "You are Correct!", 17, midPointY + 81, textBoxWidth, Align.center, true);

		//Colors the correct answer green
		AssetLoader.font.getData().setScale(0.08f, -0.08f);
		AssetLoader.shadow.getData().setScale(0.08f, -0.08f);

		if(choice == "A"){
			batcher.draw(correctAnswerExtension, 21, midPointY - 35, 94, 20);
			AssetLoader.font.draw(batcher, "" + myWorld.getQ().getA(), choicesXPos, midPointY - 29, answerExtensionTextBoxWidth, Align.center, true);
		}else if(choice == "B"){
			batcher.draw(correctAnswerExtension, 21, midPointY - 5, 94, 20);
			AssetLoader.font.draw(batcher, "" + myWorld.getQ().getB(), choicesXPos, midPointY + 1, answerExtensionTextBoxWidth, Align.center, true);
		}else if(choice == "C"){
			batcher.draw(correctAnswerExtension, 21, midPointY + 25, 94, 20);
			AssetLoader.font.draw(batcher, "" + myWorld.getQ().getC(), choicesXPos, midPointY + 31, answerExtensionTextBoxWidth, Align.center, true);
		}else if(choice == "D"){
			batcher.draw(correctAnswerExtension, 21, midPointY + 55, 94, 20);
			AssetLoader.font.draw(batcher, "" + myWorld.getQ().getD(), choicesXPos, midPointY + 61, answerExtensionTextBoxWidth, Align.center, true);
		}
	}

	private void drawCorrect(){
		int lengthFeedback = ("" + "You are Correct!").length();
		AssetLoader.shadow.draw(batcher, "" + "You are Correct!", 80 - (3 * lengthFeedback), midPointY + 82);
		AssetLoader.font.draw(batcher, "" + "You are Correct!", 80 - (3 * lengthFeedback), midPointY + 81);
	}

	private void drawDifficultyButtons(){
		for (ToggleButton button : difficultyButtons) {
			button.draw(batcher);
		}
	}

	//ADDED: Draws OVER the Tutorial button defined in InputHandler
	private void drawTutorialButton(){
		batcher.draw(blackline, 20, midPointY + 95, 1, 8);
		//Draw blue-green background color:
		batcher.draw(answerextension, 21, midPointY + 95, 94, 8);
		batcher.draw(blackline, 20 + 94, midPointY + 95, 1, 8);

		AssetLoader.font.getData().setScale(0.08f, -0.08f);
		AssetLoader.font.draw(batcher, "How to Play", 20, midPointY + 97, 95, Align.center, true);
	}

	private void ObtainPlayerName() {
		asked = AssetLoader.getAsked();
		if (!asked) {
			Gdx.input.getTextInput(listener, "Enter Your Name", "", "");
			AssetLoader.setAsked(true);
		}

	}

	private void drawGameOver() {
		batcher.draw(gameOver, 24, 25, 92, 14);
	}

	private void drawScore() {
		int length = ("" + myWorld.getScore()).length();
		AssetLoader.shadow.getData().setScale(0.25f, -0.25f);
		AssetLoader.font.getData().setScale(0.25f, -0.25f);
		AssetLoader.shadow.draw(batcher, "" + myWorld.getScore(), 68 - (3 * length), midPointY - 82);
		AssetLoader.font.draw(batcher, "" + myWorld.getScore(), 68 - (3 * length), midPointY - 83);
	}

	private void drawHighScore() {
		batcher.draw(highScore, 24, 25, 92, 14);
	}

	public void render(float delta, float runTime) {
		Gdx.gl.glClearColor(0, 0, 0, 1);
		Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);

		shapeRenderer.begin(ShapeType.Filled);
		// Draw Background color
		shapeRenderer.setColor(122 / 255.0f, 163 / 255.0f, 198 / 255.0f, 1);
		shapeRenderer.rect(0, 0, 136, midPointY + 66);

		// Draw Grass
		shapeRenderer.setColor(111 / 255.0f, 186 / 255.0f, 45 / 255.0f, 1);
		shapeRenderer.rect(0, midPointY + 66, 136, 11);

		// Draw Dirt
		shapeRenderer.setColor(191 / 255.0f, 158 / 255.0f, 67 / 255.0f, 1);
		shapeRenderer.rect(0, midPointY + 77, 136, 52);

		shapeRenderer.end();

		batcher.begin();
		batcher.disableBlending();
		batcher.draw(bg, 0, midPointY + 23, 136, 43);

		drawPipes();
		batcher.enableBlending();
		drawpipes();
		AssetLoader.bgmusic.setVolume(AssetLoader.VOLUME);

		if (myWorld.isRunning()) {
			drawElephant(runTime);
			drawScore();
		} else if (myWorld.isReady()) {
			drawElephant(runTime);
			drawReady();
		} else if (myWorld.isMenu()) {
			drawElephantCentered(runTime);
			drawMenuUI();
			drawDifficultyButtons();
			ObtainPlayerName();
			drawTutorialButton();
		} else if (myWorld.isQuestion()) {
			drawQuestionButtons();
		}  else if (myWorld.isGameOver()) {
			drawScoreboard();
			drawPlayerName();
			drawElephant(runTime);
			drawGameOver();
		} else if (myWorld.isHighScore()) {
			drawScoreboard();
			drawPlayerName();
			drawElephant(runTime);
			drawHighScore();
			drawRetry();
		}
		drawGrass();

		// This puts these on top of the grass
		if(myWorld.isGameOver()) {
			drawRetry();
		} else if(myWorld.isQuestion()) {
			drawAnswers();
			drawQuestion();
		} else if(myWorld.isCorrect()){
			String choice = myWorld.getChoice();
			drawAnswers();
			drawQuestion();
			drawCorrect(choice);
		} else if(myWorld.isIncorrect()){
			String choice = myWorld.getChoice();
			drawAnswers();
			drawQuestion();
			drawFeedback(choice);
		} else if(myWorld.isTutorial()) {
			drawTutorial();
		}

		batcher.end();
		drawTransition(delta);
	}

	public void prepareTransition(int r, int g, int b, float duration) {
		transitionColor.set(r / 255.0f, g / 255.0f, b / 255.0f, 1);
		alpha.setValue(1);
		Tween.registerAccessor(Value.class, new ValueAccessor());
		manager = new TweenManager();
		Tween.to(alpha, -1, duration).target(0).ease(TweenEquations.easeOutQuad).start(manager);
	}

	private void drawTransition(float delta) {
		if (alpha.getValue() > 0) {
			manager.update(delta);
			Gdx.gl.glEnable(GL20.GL_BLEND);
			Gdx.gl.glBlendFunc(GL20.GL_SRC_ALPHA, GL20.GL_ONE_MINUS_SRC_ALPHA);
			shapeRenderer.begin(ShapeType.Filled);
			shapeRenderer.setColor(transitionColor.r, transitionColor.g, transitionColor.b, alpha.getValue());
			shapeRenderer.rect(0, 0, 136, 300);
			shapeRenderer.end();
			Gdx.gl.glDisable(GL20.GL_BLEND);
		}
	}
}