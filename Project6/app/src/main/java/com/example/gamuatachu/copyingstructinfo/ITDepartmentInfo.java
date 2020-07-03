package com.example.gamuatachu.copyingstructinfo;

public class ITDepartmentInfo {

    protected int mHeight;
    protected String  name;

    public ITDepartmentInfo() {

        this.name="Sakari";
        this.mHeight=180;
    }

    @Override
    public String toString() {
        return "Original Object in Java"+"\n"+"(Name: "+this.name+",  "+"Height: "+this.mHeight+")";
    }


    public String toString1() {
        return "Object Filled With Struct"+"\n"+"(Name: "+this.name+",  "+"Height: "+this.mHeight+")";
    }
}
