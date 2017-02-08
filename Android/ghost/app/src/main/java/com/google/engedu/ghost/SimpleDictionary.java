package com.google.engedu.ghost;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Random;

public class SimpleDictionary implements GhostDictionary {
    private ArrayList<String> words;
    private static final int DEFAULT_WORD_LENGTH = 4;
    private static final int MAX_WORD_LENGTH = 7;
    private Random random = new Random();

    public SimpleDictionary(InputStream wordListStream) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(wordListStream));
        words = new ArrayList<>();
        String line = null;
        while((line = in.readLine()) != null) {
            String word = line.trim();
            if (word.length() >= MIN_WORD_LENGTH)
              words.add(line.trim());
        }
    }

    @Override
    public boolean isWord(String word) {
        return words.contains(word);
    }

    @Override
    public String getAnyWordStartingWith(String prefix)
    {
        if (prefix.isEmpty())
        {
            return words.get(new Random().nextInt(words.size()));
        }
        else if(binarySearch(words, words.size(), prefix) != null)
        {
            return binarySearch(words, words.size(), prefix);
        }
        else
        {
            return null;
        }
        //return "UNSTOPPED";
    }

    //Helper function for binarySearch
    public String binarySearch(ArrayList<String> words, Integer size, String prefix)
    {
        if (size == 0)
            return null;
        Integer lower = 0;
        Integer upper = size - 1;
        Integer midPoint = 0;
        Integer length = prefix.length();
        boolean found = false;

        while(!found)
        {
            if (upper < lower)
            {
                return null; //prefix does not exist
            }

            midPoint = (lower + upper) / 2;
            if(((words.get(midPoint)).substring(0, length)).compareTo(prefix) < 0) // if prefix of string in dict is before prefix
            {
                lower = midPoint + 1;
            }
            else if(((words.get(midPoint)).substring(0, length)).compareTo(prefix) > 0) // if prefix of string in dict is after prefix
            {
                upper = midPoint - 1;
            }
            else
            {
                found = true;
                //return words.get(midPoint);
            }
//            if (upper < lower)
//            {
//                return null; //prefix does not exist
//            }
//
//            midPoint = (lower + upper) / 2;
//            if((words.get(midPoint)).compareTo(prefix) > 0) // if prefix of string in dict is before prefix
//            {
//                lower = midPoint + 1;
//            }
//            else if((words.get(midPoint)).compareTo(prefix) < 0) // if prefix of string in dict is after prefix
//            {
//                upper = midPoint - 1;
//            }
//            else
//            {
//                found = true;
//                //return words.get(midPoint);
//            }
        }
        if (found)
            return words.get(midPoint);
        else
            return null;
    }


    @Override
    public String getGoodWordStartingWith(String prefix) {
        String selected = null;
        return selected;
    }




}
