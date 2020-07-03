package com.example.gamuatachu.primitivetypesapp;

public class NativeMsClass {


    static {
        System.loadLibrary("native-lib");
    }

    public native int getBooleanType(int objectNum)
            ;
    public native void sendBooleanType( boolean jBool, int countInput);

    public native byte getByteType( int objectNum)
            ;
    public native void sendByteType( byte jByte, int countInput);

    public native char getCharType( int objectNum)
            ;
    public native void sendCharType(char jChar, int countInput);

    public native double getDoubleType( int objectNum)
            ;
    public native void sendDoubleType(double jDouble, int countInput);

    public native float getFloatType(int objectNum)
           ;
    public native void sendFloatType(float jFloat, int countInput);



    public native int getIntegerType( int objectNum)
            ;
    public native void sendIntegerType( int jInt, int countInput);


    public native long getLongType( int objectNum);
    public native void sendLongType(long jLong, int countInput);

    public native short getShortType( int objectNum)
            ;
    public native void sendShortType( short jShort, int countInput);


    public native String getStringType( int objectNum)
            ;
    public native void sendStringType( String jString, int countInput);


    public native void resetNative(int countInput);




}
