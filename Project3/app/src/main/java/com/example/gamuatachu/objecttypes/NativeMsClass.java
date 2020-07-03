package com.example.gamuatachu.objecttypes;

public class NativeMsClass {
    static {
        System.loadLibrary("native-lib");
    }
    public native Languages getLanguage(int objNum);
    public native void sendLanguage(int countInput, Languages pLanguage);
    public native void resetNative(int countInput);
}
