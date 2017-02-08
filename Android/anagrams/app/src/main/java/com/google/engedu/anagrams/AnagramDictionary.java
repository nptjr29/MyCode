package com.google.engedu.anagrams;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Random;
import java.util.Arrays;
import java.util.HashSet;
import java.util.HashMap;

public class AnagramDictionary {

    private static final int MIN_NUM_ANAGRAMS = 5;
    private static final int DEFAULT_WORD_LENGTH = 3;
    private static final int MAX_WORD_LENGTH = 7;
    private Random random = new Random();

    private ArrayList<String> wordList = new ArrayList<String>();
    private HashSet<String> wordSet = new HashSet<String>();
    private HashMap<String, ArrayList<String>> lettersToWord = new HashMap<String, ArrayList<String>>();
    private HashMap<Integer, ArrayList<String>> sizeToWords = new HashMap<Integer, ArrayList<String>>();
    public int wordLength = DEFAULT_WORD_LENGTH;

    public AnagramDictionary(InputStream wordListStream) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(wordListStream));
        String line;
//        int wordLength = DEFAULT_WORD_LENGTH;
        while((line = in.readLine()) != null) {
            String word = line.trim();
            wordList.add(word); //add new word to wordList
            wordSet.add(word); // add new word to wordSet
            String sortedWord = sortLetters(word);
            if (lettersToWord.containsKey(sortedWord))
            {
                ArrayList<String> listWords = lettersToWord.get(sortedWord);
                listWords.add(word);
            }
            else
            {
                ArrayList<String> listWords = new ArrayList<String>();
                listWords.add(word);
                lettersToWord.put(sortedWord, listWords);
            }
            if (sizeToWords.containsKey(word.length())) {
                ArrayList<String> list = sizeToWords.get(word.length());
                list.add(word);
            }
            else
            {
                ArrayList<String> list = new ArrayList<String>();
                list.add(word);
                sizeToWords.put(word.length(), list);
            }
        }

    }

    public boolean isGoodWord(String word, String base) {
        //check if the provided word is in wordSet
//        boolean isInDictionary = false;
//        if (wordSet.contains(word))
//            isInDictionary = true;
//
//        //check if the word does not contain the base word as a substring
//        boolean containsBaseSubs = false;
//        if (word.contains(base))
//            containsBaseSubs = true;
        return (wordSet.contains(word) && !word.contains(base));
    }

    public ArrayList<String> getAnagrams(String targetWord) {
        //one way:
        ArrayList<String> result = new ArrayList<String>();
        //sort the letter of the word in alphabetical order
        String sortedTargetWord = sortLetters(targetWord);
        //compare the length of both words to see if it's an anagram
        for (String w : wordList){
            String sortedW = sortLetters(w);
            if(sortedTargetWord.equals(sortedW)) {
                result.add(w);
            }
        }
        //another way:
//        for (String w : wordList)
//        {
//            //check length first
//            if (w.length() == targetWord.length())
//            {
//                String sortedW = sortLetters(w);
//                String sortedWord = sortLetters(targetWord);
//                if (sortedW.equals(sortedWord))
//                    result.add(w);
//            }
//        }
//
        return result;
        //return lettersToWord.get(sortLetters(targetWord));
    }

    public ArrayList<String> getAnagramsWithOneMoreLetter(String word) {
        ArrayList<String> result = new ArrayList<String>();
        char[] alphabets = "abcdefghijklmnopqrstuvwxyz".toCharArray();
        for (char letter : alphabets) {
            String sortedAddedWord = sortLetters(word + letter);
            if (lettersToWord.containsKey(sortedAddedWord)) {
                ArrayList<String> tempArray = lettersToWord.get(sortedAddedWord);
                for (String anagramWord : tempArray) {
                    result.add(anagramWord);
                }
            }
        }
        return result;
    }

    public String pickGoodStarterWord() {
        int length = 0;
        ArrayList<String> list = sizeToWords.get(wordLength);
        while (length < MIN_NUM_ANAGRAMS)
        {
            String word = list.get(new Random().nextInt(list.size()));
            length = getAnagramsWithOneMoreLetter(word).size();
            if (length >= MIN_NUM_ANAGRAMS)
            {
                if (wordLength < MAX_WORD_LENGTH)
                    ++wordLength;
                return word;
            }
        }
        return "post";
    }

    public String sortLetters(String word){
        char[] chars = word.toCharArray();
        Arrays.sort(chars);
        String result = new String(chars);
        return result;
    }
}
