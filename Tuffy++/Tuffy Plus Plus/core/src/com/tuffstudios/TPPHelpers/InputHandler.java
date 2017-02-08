package com.tuffstudios.TPPHelpers;
import com.badlogic.gdx.Input.Keys;
import com.badlogic.gdx.InputProcessor;
import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.tuffstudios.GameObjects.Elephant;
import com.tuffstudios.GameWorld.GameWorld;
import com.tuffstudios.ui.SimpleButton;
import com.tuffstudios.ui.ToggleButton;
import com.tuffstudios.TPPHelpers.AssetLoader;

import java.util.ArrayList;
import java.util.List;

public class InputHandler implements InputProcessor {
	private Elephant myElephant;
	private GameWorld myWorld;
	private List<SimpleButton> menuButtons;
	private List<ToggleButton> difficultyButtons;
	private List<SimpleButton> questionButtons;
	private SimpleButton playButton;
	private ToggleButton Easy;
	private ToggleButton Medium;
	private ToggleButton Tuff;
	private ToggleButton muteButton;
	private SimpleButton Retry;
	private SimpleButton AnswerA;
	private SimpleButton AnswerB;
	private SimpleButton AnswerC;
	private SimpleButton AnswerD;
	private SimpleButton tutorial;
	private float scaleFactorX;
	private float scaleFactorY;

	public InputHandler(GameWorld myWorld, float scaleFactorX, float scaleFactorY) {
		this.myWorld = myWorld;
		myElephant = myWorld.getElephant();

		int midPointY = myWorld.getMidPointY();

		this.scaleFactorX = scaleFactorX;
		this.scaleFactorY = scaleFactorY;

		menuButtons = new ArrayList<SimpleButton>();
		difficultyButtons = new ArrayList<ToggleButton>();
		questionButtons = new ArrayList<SimpleButton>();

		playButton = new SimpleButton(136 / 2 - (AssetLoader.playButtonUp.getRegionWidth() / 2),
				midPointY + 50, 29, 16, AssetLoader.playButtonUp, AssetLoader.playButtonDown);
		menuButtons.add(playButton);

		Retry = new SimpleButton (136 / 2 - (AssetLoader.playButtonUp.getRegionWidth() / 2) - 20,
				midPointY + 35, 70, 20, AssetLoader.retry, AssetLoader.playButtonDown);
		menuButtons.add(playButton);

		//ADDED: Used answerLetterA as a placeholder. Button is drawn over in GameRenderer:
		tutorial = new SimpleButton(20, midPointY + 95, 95, 8, AssetLoader.answerletterA, AssetLoader.answerletterA);
		menuButtons.add(tutorial);

		Easy = new ToggleButton((136 / 2 - (AssetLoader.easyUp.getRegionWidth() / 2)) - 30,
				midPointY + 77, 29, 16, AssetLoader.easyUp, AssetLoader.easyDown);
		difficultyButtons.add(Easy);
		Medium = new ToggleButton((136 / 2 - (AssetLoader.mediumUp.getRegionWidth() / 4)) + 5,
				midPointY + 77, 29, 16, AssetLoader.mediumUp, AssetLoader.mediumDown);
		difficultyButtons.add(Medium);
		Tuff = new ToggleButton((136 / 2 - (AssetLoader.tuffUp.getRegionWidth() / 2)) + 30,
				midPointY + 77, 29, 16, AssetLoader.tuffUp, AssetLoader.tuffDown);
		difficultyButtons.add(Tuff);
		muteButton = new ToggleButton((136 / 2 - (AssetLoader.muteButtonUp.getRegionWidth() / 2)) + 70
				, midPointY + 80, 15, 10, AssetLoader.muteButtonUp, AssetLoader.muteButtonDown);
		difficultyButtons.add(muteButton);

				//Defines the positions of the question buttons of px size 95x17
		AnswerA = new SimpleButton(20, midPointY - 35, 95, 17, AssetLoader.answerletterA, AssetLoader.answerletterA);
		questionButtons.add(AnswerA);
		AnswerB = new SimpleButton(20, midPointY - 5, 95, 17, AssetLoader.answerletterB, AssetLoader.answerletterB);
		questionButtons.add(AnswerB);
		AnswerC = new SimpleButton(20, midPointY + 25, 95, 17, AssetLoader.answerletterC, AssetLoader.answerletterC);
		questionButtons.add(AnswerC);
		AnswerD = new SimpleButton(20, midPointY + 55, 95, 17, AssetLoader.answerletterD, AssetLoader.answerletterD);
		questionButtons.add(AnswerD);
	}

	@Override
	public boolean touchDown(int screenX, int screenY, int pointer, int button) {
		screenX = scaleX(screenX);
		screenY = scaleY(screenY);

		if (myWorld.isMenu()) {
			playButton.isTouchDown(screenX, screenY);
			Easy.isTouchDown(screenX, screenY);
			Medium.isTouchDown(screenX, screenY);
			Tuff.isTouchDown(screenX, screenY);
			muteButton.isTouchDown(screenX,screenY);
			tutorial.isTouchDown(screenX, screenY);
		} else if (myWorld.isReady()) {
			myWorld.start();
			myElephant.onClick();
		} else if (myWorld.isRunning()) {
			myElephant.onClick();
		} else if (myWorld.isQuestion()) {
			AnswerA.isTouchDown(screenX, screenY);
			AnswerB.isTouchDown(screenX, screenY);
			AnswerC.isTouchDown(screenX, screenY);
			AnswerD.isTouchDown(screenX, screenY);
		} else if (myWorld.isGameOver() || myWorld.isHighScore()) {
			Retry.isTouchDown(screenX, screenY);
		}
		return true;
	}

	@Override
	public boolean touchUp(int screenX, int screenY, int pointer, int button) {
		screenX = scaleX(screenX);
		screenY = scaleY(screenY);

		if (myWorld.isMenu()) {
			if (playButton.isTouchUp(screenX, screenY)) {
				myWorld.ready();
			}

			if(Easy.isTouchUp(screenX, screenY)){
				myWorld.setDifficulty(0);
				myWorld.loadQ();
				Medium.resetButton();
				Tuff.resetButton();
			} else if(Medium.isTouchUp(screenX, screenY)){
				myWorld.setDifficulty(1);
				myWorld.loadQ();
				Easy.resetButton();
				Tuff.resetButton();
			} else if(Tuff.isTouchUp(screenX, screenY)){
				myWorld.setDifficulty(2);
				myWorld.loadQ();
				Easy.resetButton();
				Medium.resetButton();
			} else if(muteButton.isTouchUp(screenX, screenY)) {
				if (AssetLoader.VOLUME == 0f)
				{
					muteButton.resetButton();
					AssetLoader.VOLUME = 1f;
				} else AssetLoader.VOLUME = 0f;
			} else if (tutorial.isTouchUp(screenX, screenY)) {
				myWorld.setTutorial();
			}

			return true;
		} else if(myWorld.isTutorial()) {
			myWorld.restart();
		}
		else if(myWorld.isQuestion()){
			String theirAnswer = "";

			if (AnswerA.isTouchUp(screenX, screenY)) {
				theirAnswer = myWorld.getQ().getA();

				if(myWorld.getQ().isCorrect(theirAnswer)){
					myWorld.setCorrect("A");
				}else{
					myWorld.setIncorrect("A");
				}
			} else if (AnswerB.isTouchUp(screenX, screenY)) {
				theirAnswer = myWorld.getQ().getB();

				if(myWorld.getQ().isCorrect(theirAnswer)){
					myWorld.setCorrect("B");
				}else{
					myWorld.setIncorrect("B");
				}
			} else if (AnswerC.isTouchUp(screenX, screenY)) {
				theirAnswer = myWorld.getQ().getC();

				if(myWorld.getQ().isCorrect(theirAnswer)){
					myWorld.setCorrect("C");
				}else{
					myWorld.setIncorrect("C");
				}
			} else if (AnswerD.isTouchUp(screenX, screenY)) {
				theirAnswer = myWorld.getQ().getD();

				if(myWorld.getQ().isCorrect(theirAnswer)){
					myWorld.setCorrect("D");
				}else{
					myWorld.setIncorrect("D");
				}
			}

			return true;
		} else if(myWorld.isCorrect()){
			if (myWorld.getHighScoreObtained()) {
				myWorld.resetHighScoreObtained();
 			}else {
				myWorld.gameover();
			}
		} else if(myWorld.isIncorrect()){
			myWorld.setQuestion();
		} else if (myWorld.isGameOver() || myWorld.isHighScore()) {
			if (Retry.isTouchUp(screenX, screenY)) {
				myWorld.setDifficulty(0);
				myWorld.loadQ();
				myWorld.restart();
				Easy.resetButton();
				Medium.resetButton();
				Tuff.resetButton();
			}

			return true;
		}

		return false;
	}

	@Override
	public boolean keyDown(int keycode) {
		// Can now use Space Bar to play the game
		if (keycode == Keys.SPACE) {
			if (myWorld.isMenu()) {
				myWorld.ready();
			} else if (myWorld.isReady()) {
				myWorld.start();
			}

			myElephant.onClick();

			if (myWorld.isQuestion()) {
				myWorld.gameover();
			} else if (myWorld.isGameOver()) {
				myWorld.restart();
			}
		}
		return false;
	}

	@Override
	public boolean keyUp(int keycode) {
		return false;
	}

	@Override
	public boolean keyTyped(char character) {
		return false;
	}

	@Override
	public boolean touchDragged(int screenX, int screenY, int pointer) {
		return false;
	}

	@Override
	public boolean mouseMoved(int screenX, int screenY) {
		return false;
	}

	@Override
	public boolean scrolled(int amount) {
		return false;
	}

	private int scaleX(int screenX) {
		return (int) (screenX / scaleFactorX);
	}

	private int scaleY(int screenY) {
		return (int) (screenY / scaleFactorY);
	}

	public List<SimpleButton> getMenuButtons() {
		return menuButtons;
	}

	public List<ToggleButton> getDifficultyButtonsButtons() {
		return difficultyButtons;
	}

	public List<SimpleButton> getQuestionButtons() {
		return questionButtons;
	}
}