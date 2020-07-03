package com.example.gamuatachu.arraytypes;
import java.util.ArrayList;
import java.util.Arrays;

import exceptionPackage.InvalidTypeException;

public class NativeMsClass<T> {
    static {
        System.loadLibrary("native-lib");
    }




    ArrayList<Object> arrayList;

    public NativeMsClass() {
        // Use Array native method to create array
        // of a type only known at run time

        arrayList= new ArrayList();

    }


    public  <T> void addToList(T cl)
    {

        arrayList.add(cl);

    }

    public  Object[]  returnArrayList(Class<T> clazz)
    {

        Object[] array = arrayList.toArray();
        return array;

    }

    public String convertArray(String  jArray1)
    {

        //String a= Arrays.toString(jArray1); //toString the List or Vector
        String jArray2[]=jArray1.substring(1,jArray1.length()-1).split(", ");
        int j=jArray2.length-1;
        StringBuilder builder = new StringBuilder();
        //for (String value : jArray2) {
            //builder.append(value+", ");
       // }
        for (int i=0;i<j;i++){
            builder.append(jArray2[i]+", ");
            }
        builder.append(jArray2[j]);
        String text = builder.toString();

        return text;
        //return Arrays.toString(jArray2);
    }


    public void clearList()
    {
        arrayList.clear();

    }
    public int lengthOfList()
    {
       return arrayList.size();

    }





    public native void resetNative(int countInput);

    /*---------------------------------------Primitive Array Native Methods------------------------*/

    public native int[] getIntegerArrayType( int objectNum)
            ;
    public native void sendIntegerArrayType( int[] pIntArray, int countInput);



    public native String[] getStringArrayType( int objectNum)
            ;
    public native void sendStringArrayType(
            String[] pStringArray, int countInput);


    public native boolean[] getBooleanArrayType( int objectNum)
            ;
    public native void sendBooleanArrayType(
            boolean[] pBoolArray, int countInput);

    public native byte[] getByteArrayType( int objectNum)
            ;
    public native void sendByteArrayType(byte[] pByteArray, int countInput);

    public native char[] getCharArrayType( int objectNum)
            ;
    public native void sendCharArrayType(char[] pCharArray, int countInput);


    public native long[] getLongArrayType( int objectNum)
            ;
    public native void sendLongArrayType(long[] pLongArray, int countInput);

    public native short[] getShortArrayType( int objectNum)
            ;
    public native void sendShortArrayType( short[] pShortArray, int countInput);
    public native float[] getFloatArrayType(int objectNum)
            ;
    public native void sendFloatArrayType(float[] pFloatArray, int countInput);

    public native double[] getDoubleArrayType(int objectNum)
           ;
    public native void sendDoubleArrayType(double[] pDoubleArray, int countInput);




}
