package com.tuffstudios.GameWorld;
import com.badlogic.gdx.Game;
import com.badlogic.gdx.math.Intersector;
import com.badlogic.gdx.math.Rectangle;
import com.tuffstudios.GameObjects.Elephant;
import com.tuffstudios.GameObjects.ScrollHandler;
import com.tuffstudios.QuestionFactory.Question;
import com.tuffstudios.QuestionFactory.QuestionRepository;
import com.tuffstudios.TPPHelpers.AssetLoader;
import com.tuffstudios.TPPHelpers.InputHandler;

public class GameWorld {
	private Elephant elephant;
	private ScrollHandler scroller;
	private Rectangle ground;
	private int score = 0;
	private String playerName;
	private float runTime = 0;
	private int midPointY;
	private GameRenderer renderer;
	private GameState currentState;
	private String choice = "A";
	private boolean highScoreObtained = false;

	//Questions
	public QuestionRepository questionloader;
	private Question questions;

	public enum GameState {
		MENU, READY, RUNNING, QUESTION, GAMEOVER, HIGHSCORE, CORRECT, INCORRECT, TUTORIAL
	}

	public GameWorld(int midPointY) {
		currentState = GameState.MENU;
		this.midPointY = midPointY;
		elephant = new Elephant(33, midPointY - 5, 17, 12);
		// The grass should start 66 pixels below the midPointY
		scroller = new ScrollHandler(this, midPointY + 66);
		ground = new Rectangle(0, midPointY + 66, 137, 11);
		//Questions initialization
		questionloader = new QuestionRepository();
		//Will initially be an easy question
		questions = questionloader.generateQuestion();
	}

	public void update(float delta) {
		runTime += delta;

		switch (currentState) {
		case READY:
		case MENU:
			updateReady(delta);
			break;
		case RUNNING:
			updateRunning(delta);
			break;
		default:
			break;
		}
	}

	private void updateReady(float delta) {
		elephant.updateReady(runTime);
		scroller.updateReady(delta);
	}

	public void updateRunning(float delta) {
		if (delta > .15f) {
			delta = .15f;
		}

		elephant.update(delta);
		scroller.update(delta);

		if (scroller.collides(elephant) && elephant.isAlive()) {
			scroller.stop();
			elephant.die();
			AssetLoader.dead.play();
			renderer.prepareTransition(255, 255, 255, .3f);
			AssetLoader.fall.play();
		}

		if (Intersector.overlaps(elephant.getBoundingCircle(), ground)) {
			if (elephant.isAlive()) {
				AssetLoader.dead.play();
				renderer.prepareTransition(255, 255, 255, .3f);
				elephant.die();
			}

			scroller.stop();
			elephant.decelerate();

			if (score > AssetLoader.getHighScore()) {
				AssetLoader.setHighScore(score);
				highScoreObtained = true;
			}
			currentState = GameState.QUESTION;
		}
	}

	public Elephant getElephant() {
		return elephant;
	}

	public int getMidPointY() {
		return midPointY;
	}

	public ScrollHandler getScroller() {
		return scroller;
	}

	public int getScore() {
		return score;
	}

	public void addScore(int increment) {
		score += increment;
	}

	public void start() {
		currentState = GameState.RUNNING;
	}

	public void ready() {
		currentState = GameState.READY;
		renderer.prepareTransition(0, 0, 0, 1f);
	}

	public void gameover() {
		currentState = GameState.GAMEOVER;
		renderer.prepareTransition(0, 0, 0, 1f);
	}

	public void restart() {
		score = 0;
		elephant.onRestart(midPointY - 5);
		scroller.onRestart();
		currentState = GameState.MENU;
	}

	public boolean isReady() {
		return currentState == GameState.READY;
	}

	public boolean isGameOver() {return currentState == GameState.GAMEOVER;}

	public boolean isQuestion() { return currentState == GameState.QUESTION; }

	public boolean isHighScore() {
		return currentState == GameState.HIGHSCORE;
	}

	public boolean isMenu() {
		return currentState == GameState.MENU;
	}

	public boolean isRunning() {
		return currentState == GameState.RUNNING;
	}

	public boolean isCorrect(){
		return currentState == GameState.CORRECT;
	}

	public boolean isIncorrect(){
		return currentState == GameState.INCORRECT;
	}

	public boolean isTutorial() { return currentState == GameState.TUTORIAL; }

	public String getChoice(){ return choice;}

	//Gets the Question object
	public Question getQ(){
		return questions;
	}

	public void setRenderer(GameRenderer renderer) {
		this.renderer = renderer;
	}

	//Game State setters
	public void setCorrect(String choice){
		currentState = GameState.CORRECT;
		this.choice = choice;
	}

	public void setIncorrect(String choice){
		currentState = GameState.INCORRECT;
		this.choice = choice;
	}

	public void setQuestion(){
		currentState = GameState.QUESTION;
	}

	public void setDifficulty(int difficulty){
		questionloader.setDifficulty(difficulty);
	}

	public void setTutorial() { currentState = GameState.TUTORIAL;}

	public void loadQ(){
		questions = questionloader.generateQuestion();
	}

	public boolean getHighScoreObtained(){
		return highScoreObtained;
	}

	public void resetHighScoreObtained(){
		currentState = GameState.HIGHSCORE;
		renderer.prepareTransition(0, 0, 0, 1f);
		highScoreObtained = false;
	}
}
