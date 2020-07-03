package com.example.gamuatachu.copyingstructinfo;

public class NativeMsClass implements StructCopyListener {
    private StructCopyListener mListener;
    public NativeMsClass(StructCopyListener pListener) {
        mListener = pListener;
    }

    static {
        System.loadLibrary("native-lib");
    }
    @Override
    public void printStruct(ITDepartmentInfo pValue) {
        mListener.printStruct(pValue);
    }

    public native void fillAndGetStructInNative(ITDepartmentInfo pInfo);
    public native void resetNative();
}
