package com.tuffstudios.QuestionFactory;
import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.files.FileHandle;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.ExecutionException;

public class CustomCSVFile {
    //The current max length per entry: the question, choices a, b, c, d, the answer, and the feedback
    private static final char DEFAULT_SEPARATOR = ',';
    private static final char DEFAULT_QUOTE = '"';
    static final int ROW_LENGTH = 7;
    static final int QUESTION = 0;
    static final int CHOICE_A = 1;
    static final int CHOICE_B = 2;
    static final int CHOICE_C = 3;
    static final int CHOICE_D = 4;
    static final int ANSWER = 5;
    static final int FEEDBACK = 6;
    String csvFile;
    char delimeter;
    Scanner scanner;

    public CustomCSVFile(String csvFile, char delimeter){
        this.csvFile = csvFile;
        //This will be used in getRow()
        this.delimeter = delimeter;
        FileHandle file = Gdx.files.internal(this.csvFile);

        try{
            scanner = new Scanner(file.reader());
        }catch (Exception e) {
            e.printStackTrace();
        }
    }

    public String[] getRow(){
        String[] row = new String[ROW_LENGTH];

        if(scanner.hasNext()){
            List<String> line = parseLine(scanner.nextLine(), delimeter);
            row[QUESTION] = line.get(QUESTION);
            row[CHOICE_A] = line.get(CHOICE_A);
            row[CHOICE_B] = line.get(CHOICE_B);
            row[CHOICE_C] = line.get(CHOICE_C);
            row[CHOICE_D] = line.get(CHOICE_D);
            row[ANSWER] = line.get(ANSWER);
            row[FEEDBACK] = line.get(FEEDBACK);
        }

        return row;
    }

    public void close(){
        scanner.close();
    }

    public static List<String> parseLine(String cvsLine) {
        return parseLine(cvsLine, DEFAULT_SEPARATOR, DEFAULT_QUOTE);
    }

    public static List<String> parseLine(String cvsLine, char separators) {
        return parseLine(cvsLine, separators, DEFAULT_QUOTE);
    }

    public static List<String> parseLine(String cvsLine, char separators, char customQuote) {
        List<String> result = new ArrayList();
        //If empty, return
        if (cvsLine == null && cvsLine.isEmpty()) {
            return result;
        }

        if (customQuote == ' ') {
            customQuote = DEFAULT_QUOTE;
        }

        if (separators == ' ') {
            separators = DEFAULT_SEPARATOR;
        }

        StringBuffer curVal = new StringBuffer();
        boolean inQuotes = false;
        //Boolean to indicate whether or not to start collecting characters
        boolean startCollectChar = false;
        boolean doubleQuotesInColumn = false;
        char[] chars = cvsLine.toCharArray();

        for (char ch : chars) {
            if (inQuotes) {
                startCollectChar = true;
                if (ch == customQuote) {
                    //If char equals to the 2nd custom quote, then you are out of the column entry:
                    inQuotes = false;
                    doubleQuotesInColumn = false;
                } else {
                    //Allows "" within a custom quote enclosure (i.e.: An entry like: " "" " in the csv file):
                    if (ch == '\"') {
                        if (!doubleQuotesInColumn) {
                            //Adds " into the buffer, curVal
                            curVal.append(ch);
                            doubleQuotesInColumn = true;
                        }
                    } else {
                        curVal.append(ch);
                    }
                }
            } else {
                if (ch == customQuote) {
                    inQuotes = true;
                    //Allows "" within an empty quote enclosure (i.e.: An entry like: "" in the csv file):
                    if (chars[0] != '"' && customQuote == '\"') {
                        curVal.append('"');
                    }
                    //Double quotes in a column will invoke the following:
                    if (startCollectChar) {
                        curVal.append('"');
                    }
                } else if (ch == separators) {//The delimeter
                    //Adds the buffer (after converting it to a String), curVal, to the string list, result, as an entry:
                    result.add(curVal.toString());
                    curVal = new StringBuffer();
                    startCollectChar = false;
                } else if (ch == '\r') {
                    //Ignore Line Feed (LF) characters
                    continue;
                } else if (ch == '\n') {
                    //The end, so break
                    break;
                } else {
                    //Adds the char into the buffer, curVal (The cases other than: custom quote, delimeter, line feed, and new line)
                    curVal.append(ch);
                }
            }
        }

        result.add(curVal.toString());
        return result;
    }
}
