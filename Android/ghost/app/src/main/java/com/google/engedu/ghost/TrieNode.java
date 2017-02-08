package com.google.engedu.ghost;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Random;


public class TrieNode {
    private HashMap<String, TrieNode> children;
    private boolean isWord;

    public TrieNode() {
        children = new HashMap<>();
        isWord = false;
    }

    public void add(String s)
    {
        //Iteratively way
        TrieNode node = this;
        //HashMap<String, TrieNode> tempMap = children;
        for(int i = 0; i < s.length(); i++)
        {
            char tempChar = s.charAt(i);
            String letter = Character.toString(tempChar);

            if(!node.children.containsKey(letter))
                node.children.put(letter, new TrieNode()); //create new map

            node = node.children.get(letter);
        }
        node.isWord = true;

        //Recursive solution
//        if (s.isEmpty()) {
//            isWord = true;
//            return;
//        }
//
//        String key = s.substring(0,1);  //first character
//        if (!children.containsKey(key))
//        {
//            children.put(key, new TrieNode());
//        }
//        children.get(key).add(s.substring(1));

    }

    public boolean isWord(String s)
    {
        if(s.isEmpty())
            return isWord; //base case
        if (children.containsKey(s.substring(0,1)))
            return children.get(s.substring(0,1)).isWord(s.substring(1));
        else
            return false;
    }

    private String getAnyWordStartingWithImplementation(String s, String SB)
    {
        return getAnyWordStartingWithImplementation(s, new String);
    }

    public String getAnyWordStartingWith(String s)
    {
        //needs fixing

        ArrayList buffer = new ArrayList<String>();
        if(s.isEmpty())
        {
            Random r = new Random();
            int index = r.nextInt(children.size());
            buffer.add(children.keySet().toArray()[index]);
            return buffer.toString();
        }


        String key = s.substring(0,1);
        if(children.containsKey(key))
        {
            return getAnyWordStartingWithImplementation(s.substring(1), key);
        }
        return null;
    }

    public String getGoodWordStartingWith(String s) {
        return null;
    }
}
