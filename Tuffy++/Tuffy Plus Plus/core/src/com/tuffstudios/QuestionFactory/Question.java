package com.tuffstudios.QuestionFactory;

public class Question {
	private String question;
	private String choiceA;
	private String choiceB;
	private String choiceC;
	private String choiceD;
	private String answer;
	private String feedback;
	private boolean isAnswered;
	
	//Initialize during matrix creation for each Question
	public Question(String question, String choiceA, String choiceB, String choiceC, String choiceD, String answer, String feedback){
		this.question = question;
		this.choiceA = choiceA;
		this.choiceB = choiceB;
		this.choiceC = choiceC;
		this.choiceD = choiceD;
		this.answer = answer;
		this.feedback = feedback;
		isAnswered = false;
	}

	//Getters - Use these to display the question and choices
	//Or when you need to compare the selected choice and answer
	public String getQuestion () { return question; }

	public String getA(){
		return choiceA;
	}

	public String getB() {
		return choiceB;
	}

	public String getC() {
		return choiceC;
	}

	public String getD(){
		return choiceD;
	}
	
	public String getAnswer(){
		return answer;
	}

	public String getFeedback() {
		return feedback;
	}
	
	//Optional - Use this to check if the question has already been answered
	public boolean isAnswered(){
		return isAnswered;
	}

	//Setters - Use this to keep track of which questions have already been answered
	public void answered(){
		isAnswered = true;
	}
	
	//Utility functions
	//Argument should be the string value of their chosen answer, which can be obtained from the getters
	public boolean isCorrect(String theirChoice){
		if(theirChoice.equals(answer)){
			return true;
		}else{
			return false;
		}
	}
}