package com.example.gamuatachu.nativethreads;

public class NativeMsClass implements NativeListener {

    private NativeListener cListener;
    public NativeMsClass(NativeListener pListener) {
        cListener = pListener;
    }

    static {
        System.loadLibrary("native-lib");
    }








    public native void startNativeThread(int pInt);//only this



    @Override
    public void setStringBuilder(int nativeInt) {

        cListener.setStringBuilder(nativeInt);


    }

    @Override
    public void setUI() {
        cListener.setUI();
    }
}
