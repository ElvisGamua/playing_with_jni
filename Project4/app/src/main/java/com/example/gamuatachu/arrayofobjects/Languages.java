package com.example.gamuatachu.arrayofobjects;

import android.text.TextUtils;

public class Languages {

    private int objectNumber;
    private String language;
    private String difficulty;
    private int intDiff;

    public Languages(String language, String difficulty) {
        if (TextUtils.isEmpty(language)||TextUtils.isEmpty(difficulty)) {
            throw new IllegalArgumentException();
        }
        this.language=language;
        this.difficulty=difficulty;
        this.intDiff=Integer.parseInt(String.valueOf(difficulty));

    }

    @Override
    public String toString() {

        String stringToSend="( "+"Language: "+language+","+   "  Difficulty "+intDiff+" )";

        return stringToSend;
    }
}
