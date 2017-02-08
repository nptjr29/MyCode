package com.tuffstudios.QuestionFactory;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.FileReader;

public class CSVFile {
    //The current max length per entry: the question, choices a, b, c, d, the answer, and the feedback
    static final int ROW_LENGTH = 7;
    String csvFile;
    char delimiter;
    String csvLine;
    BufferedReader reader;

    public CSVFile(String csvFile, char delimeter){
        this.csvFile = csvFile;
        this.delimiter = delimeter;
        csvLine = "";
        reader = null;
        //Open the file for reading:
        try {
            reader = new BufferedReader(new FileReader(csvFile));
        }catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public String[] getRow(){
        String[] row = new String[ROW_LENGTH];
        try{
            if((csvLine = reader.readLine()) != null){
                //Need to convert the Char delimeter to a String
                row = csvLine.split(Character.toString(delimiter));
            }
        }catch (IOException ex) {
            throw new RuntimeException("Error in reading CSV file");
        }
        return row;
    }

    public void close(){
        try {
            reader.close();
        } catch (IOException e) {
            throw new RuntimeException("Error while closing input stream");
        }
    }
}