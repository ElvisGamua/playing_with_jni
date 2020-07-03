package com.example.gamuatachu.objecttypes;

import android.text.TextUtils;

public class Languages {

    private int objectNumber;
    private String language;
    private char difficulty;

    public Languages(String language, char difficulty, int objectNum) {
        if (TextUtils.isEmpty(language)||(difficulty==' ')) {
            throw new IllegalArgumentException();
        }
        this.language=language;
        this.difficulty=difficulty;
        this.objectNumber=objectNum;
    }

    @Override
    public String toString() {

        String stringToSend="Object "+objectNumber+"\n"+"Language: "+language+"  Difficulty "+difficulty;

        return stringToSend;
    }
}
