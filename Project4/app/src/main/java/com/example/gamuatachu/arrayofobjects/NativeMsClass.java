package com.example.gamuatachu.arrayofobjects;

public class NativeMsClass implements ComparingListener{

    private ComparingListener cListener;
    public NativeMsClass(ComparingListener bListener) {
        cListener = bListener;
    }
    static {
        System.loadLibrary("native-lib");
    }

   public native Languages[] getLanguageArray(int objectNum);
    public native void sendLanguageArray(Languages[] pLanguageArray, int countInput);


    public native void resetNative(int countInput);

    public native void compareObjects(Languages[] pLanguageArray);

    @Override
    public void onObjectCompare(Languages pLanguageArray) {
        cListener.onObjectCompare(pLanguageArray);

    }



}
