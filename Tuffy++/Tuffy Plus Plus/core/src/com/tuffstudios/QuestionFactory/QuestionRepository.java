package com.tuffstudios.QuestionFactory;
import java.util.Random;

public class QuestionRepository {
	static final String FILE = "data/questions.csv";
	static final char DELIMETER = ',';
	static final int MAX_DIFFICULTY = 3;
	static final int MAX_QUESTIONS = 5;
	static final int QUESTION = 0;
	static final int CHOICE_A = 1;
	static final int CHOICE_B = 2;
	static final int CHOICE_C = 3;
	static final int CHOICE_D = 4;
	static final int ANSWER = 5;
	static final int FEEDBACK = 6;
	protected int difficulty;
	protected Question[][] questions = new Question[MAX_DIFFICULTY][MAX_QUESTIONS];

	//Initialize this when starting the game
	public QuestionRepository(){
		//Set the default difficulty to easy
		//Difficulty levels - 0 = Easy, 1 = Medium, 2 = Hard (Tuff)
		difficulty = 0;
		//Populate the matrix with the questions
		//CSVFile csvFile = new CSVFile(FILE, DELIMETER);
		CustomCSVFile csvFile = new CustomCSVFile(FILE, DELIMETER);

		for (int difficulty = 0; difficulty < MAX_DIFFICULTY; difficulty++){
			for(int question = 0; question < MAX_QUESTIONS; question++){
				String[] row = csvFile.getRow();
				questions[difficulty][question] = new Question(row[QUESTION], row[CHOICE_A], row[CHOICE_B], row[CHOICE_C], row[CHOICE_D], row[ANSWER], row[FEEDBACK]);
			}
		}
		csvFile.close();
	}
	
	//Setters - Set by the player at the beginning of the game 
	public void setDifficulty(int difficulty){
		this.difficulty = difficulty;
	}
	
	//Utility functions
	//Randomly picks a question from the list, based on difficulty
	public Question generateQuestion(){
		Random rn = new Random();
		int randomNumber = rn.nextInt(MAX_QUESTIONS);
		return questions[difficulty][randomNumber];
	}

	//Debug
	int getDifficulty(){
		return difficulty;
	}
}