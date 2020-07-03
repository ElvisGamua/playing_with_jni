package com.example.gamuatachu.arraytypes;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Arrays;


public class MainActivity extends AppCompatActivity implements AdapterView.OnItemSelectedListener{

    private NativeMsClass myWorker = new NativeMsClass();
    private EditText mVlEdtTxt;
    private Spinner mArrTypSpinn;
    private Button mGetBtn, mSetBtn, mResetBtn, mAddToArrBtn;;
    private TextView textView1;

    private static int countInput=0;
    private StringBuilder str
            = new StringBuilder();
    String text=null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

       init();
    }



    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.resetdialog_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case R.id.item1:
                onResetAll();
                return true;
            case R.id.item2:
                (new InfoDialog()).show(getSupportFragmentManager(),null);
                return true;

            default:
                return super.onOptionsItemSelected(item);
        }
    }

    private void init() {


        mVlEdtTxt = (EditText) findViewById(
                R.id.sVlEdtTxt);
        mAddToArrBtn=findViewById(
                R.id.sAddToArrBtn);



        mArrTypSpinn = (Spinner) findViewById(
                R.id.sArrTypSpinn);
        ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(this,
                R.array.types, android.R.layout.simple_spinner_item);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        mArrTypSpinn.setAdapter(adapter);
        mArrTypSpinn.setOnItemSelectedListener(this);

        mSetBtn = (Button) findViewById(
                R.id.sSetBtn);
        mSetBtn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {
                sendArray();
            }
        });

        mGetBtn = findViewById(
                R.id.sGetBtn);
        mGetBtn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {
                getArray();
            }
        });
        textView1=  findViewById(R.id.text1);

       // mResetBtn = findViewById(
               // R.id.sResetBtn);
        mAddToArrBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                onAddType();
            }
        });

       /* mResetBtn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View obView) {
                onResetAll();
            }
        });   */

        (new InfoDialog()).show(getSupportFragmentManager(),null);
    }

    @Override
    public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
        text = parent.getItemAtPosition(position).toString();
        //Toast.makeText(parent.getContext(), text, Toast.LENGTH_SHORT).show();
    }

    @Override
    public void onNothingSelected(AdapterView<?> parent) {

    }
    private void onAddType() {

        if (mVlEdtTxt.getText().toString()== null || mVlEdtTxt.getText().toString().isEmpty()) {
            showMessage("You must enter a value.");
            return;
        }
        try{

            String value = mVlEdtTxt.getText().toString();

            myWorker.addToList(value);

        }catch (Exception e) {
            showMessage(e.getMessage());
            //  showMessage("You must enter a value");
        }}

    private void onResetAll() {
        try{
       // for(int i=0;i<countInput;i++)
        //{
            if(str.length()>0)
                myWorker.resetNative(countInput);
           // else continue;
        //}
        str.setLength(0);textView1.setText(""); countInput=0;
            if(myWorker.lengthOfList()>0)
        {
            myWorker.clearList();
        }} catch (Exception e) {
            showMessage("Problem with Reset");
        }
        //
    }





    private void getArray() {



        try {
            for(int i=0;i<countInput;i++)
            {


                if(myWorker.getStringArrayType(i)!=null)
                {    String a= Arrays.toString(myWorker.getStringArrayType(i));
                     str.append("String Type Returned  "+"[ " +myWorker.convertArray(a)+" ]"+"\n"+"\n");



                }

                if(myWorker.getIntegerArrayType(i)!=null)
                {   String a= Arrays.toString(myWorker.getIntegerArrayType(i));
                    str.append("Integer Type Returned  "+"[ "+myWorker.convertArray(a)+" ]"+"\n"+"\n");


                     }

                if((myWorker.getBooleanArrayType(i)!=null))
                {
                    String a= Arrays.toString(myWorker.getBooleanArrayType(i));
                    str.append("Boolean Type Returned  "+"[ "+myWorker.convertArray(a)+" ]"+"\n"+"\n");


                }

                if(myWorker.getByteArrayType(i)!=null)
                {    String a= Arrays.toString(myWorker.getByteArrayType(i));
                    str.append("Byte Type Returned  "+"[ "+myWorker.convertArray(a)+" ]"+"\n"+"\n");


                }


                if(myWorker.getCharArrayType(i)!=null)
                {
                    String a= Arrays.toString(myWorker.getCharArrayType(i));
                    str.append("Char Type Returned  "+"[ "+myWorker.convertArray(a)+" ]"+"\n"+"\n");



                }

                if(myWorker.getDoubleArrayType(i)!=null)
                {
                    String a= Arrays.toString(myWorker.getDoubleArrayType(i));
                    str.append("Double Type Returned  "+"[ "+myWorker.convertArray(a)+" ]"+"\n"+"\n");


                }

                if(myWorker.getFloatArrayType(i)!=null)
                {
                    String a= Arrays.toString(myWorker.getFloatArrayType(i));
                    str.append("Float Type Returned  "+"[ "+myWorker.convertArray(a)+" ]"+"\n"+"\n");



                }

                if(myWorker.getLongArrayType(i)!=null)
                {
                    String a= Arrays.toString(myWorker.getLongArrayType(i));
                    str.append("Long Type Returned  "+"[ "+myWorker.convertArray(a)+" ]"+"\n"+"\n");



                }

                if(myWorker.getShortArrayType(i)!=null)
                {
                    String a= Arrays.toString(myWorker.getShortArrayType(i));
                    str.append("Short Type Returned  "+"[ "+myWorker.convertArray(a)+" ]"+"\n"+"\n");


                }

            }
            textView1.setText(str);

        }

         catch (Exception e) {
            showMessage(e.getMessage());
        }
    }

    private void sendArray() {

        if (mVlEdtTxt.getText().toString()== null || mVlEdtTxt.getText().toString().isEmpty()) {
            showMessage("You must enter a value.");
            return;
        }


        //String value = mVlEdtTxt.getText().toString();
        if(text==null)
        {
            showMessage("you have not selected a type");
            return;
        }

        str.setLength(0);

        try {
            switch (text) {

             case "IntegerArrayType":

                 Object[] array;
                        if ( myWorker.returnArrayList(Integer.class)!= null&&(myWorker.returnArrayList(Integer.class)).length>0) {
                            array = myWorker.returnArrayList(Integer.class);
                            int intArray[] = new int[array.length];
                            for (int i = 0; i < array.length; i++) {
                                intArray[i] = Integer.valueOf((String) array[i]);
                                ;
                            }

                            myWorker.sendIntegerArrayType(intArray, countInput);
                            countInput++;


                        } else showMessage("You must enter a type first");

                    break;
                case "StringArrayType":
                    Object[] array1;
                    if ( myWorker.returnArrayList(String.class)!= null&&(myWorker.returnArrayList(String.class)).length>0) {


                         array1 = myWorker.returnArrayList(String.class);
                        String[] stringArray = new String[array1.length];
                        for (int i = 0; i < array1.length; i++) {
                            stringArray[i] = ((String) array1[i]);
                            ;
                        }
                        myWorker.sendStringArrayType(stringArray,countInput);countInput++;
                    }
                    else showMessage("You must enter a type first");

                    break;

                case "BooleanArrayType":
                    Object[] array2;
                    if ( myWorker.returnArrayList(Boolean.class)!= null&&(myWorker.returnArrayList(Boolean.class)).length>0) {


                        array2 = myWorker.returnArrayList(Boolean.class);
                        boolean[] boolArray = new boolean[array2.length];
                        for (int i = 0; i < array2.length; i++) {
                            boolArray[i] = Boolean.valueOf((String) array2[i]);
                            ;
                        }

                        myWorker.sendBooleanArrayType(boolArray, countInput);
                        countInput++;
                    }
                    else showMessage("You must enter a type first");
                    break;

                case "ByteArrayType":
                    Object[] array3;
                    if ( myWorker.returnArrayList(Byte.class)!= null&&(myWorker.returnArrayList(Byte.class)).length>0) {

                    array3 = myWorker.returnArrayList(Byte.class);
                    byte byteArray[] = new byte[array3.length];
                    for(int i=0; i<array3.length; i++){
                        byteArray[i] = Byte.valueOf((String) array3[i]);;
                    }

                    myWorker.sendByteArrayType(byteArray,countInput);countInput++;}
                    else showMessage("You must enter a type first");
                    break;

                case "FloatArrayType":
                    Object[] array4;
                    if ( myWorker.returnArrayList(Float.class)!= null&&(myWorker.returnArrayList(Float.class)).length>0) {

                     array4 = myWorker.returnArrayList(Float.class);
                    float floatArray[] = new float[array4.length];
                    for(int i=0; i<array4.length; i++){
                        floatArray[i] = Float.valueOf((String) array4[i]);;
                    }

                    myWorker.sendFloatArrayType(floatArray,countInput);countInput++;}
                    else showMessage("You must enter a type first");
                    break;


                case "LongArrayType":

                    Object[] array5;
                    if ( myWorker.returnArrayList(Long.class)!= null&&(myWorker.returnArrayList(Long.class)).length>0) {
                    array5 = myWorker.returnArrayList(Long.class);
                    long longArray[] = new long[array5.length];
                    for(int i=0; i<array5.length; i++){
                        longArray[i] = Long.valueOf((String) array5[i]);;
                    }

                    myWorker.sendLongArrayType(longArray,countInput);countInput++;}
                    else showMessage("You must enter a type first");
                    break;

                case "DoubleArrayType":
                    Object[] array6;
                    if ( myWorker.returnArrayList(Double.class)!= null&&(myWorker.returnArrayList(Double.class)).length>0) {

                     array6 = myWorker.returnArrayList(Double.class);
                    double doubleArray[] = new double[array6.length];
                    for(int i=0; i<array6.length; i++){
                        doubleArray[i] = Double.valueOf((String) array6[i]);;
                    }

                    myWorker.sendDoubleArrayType(doubleArray,countInput);countInput++;}
                    else showMessage("You must enter a type first");
                    break;


                case "ShortArrayType":
                    Object[] array7;
                    if ( myWorker.returnArrayList(Short.class)!= null&&(myWorker.returnArrayList(Short.class)).length>0) {

                     array7 = myWorker.returnArrayList(Short.class);
                    short shortArray[] = new short[array7.length];
                    for(int i=0; i<array7.length; i++){
                        shortArray[i] = Short.valueOf((String) array7[i]);;
                    }

                    myWorker.sendShortArrayType(shortArray,countInput);countInput++;}
                    else showMessage("You must enter a type first");
                    break;

                case "CharArrayType":
                    Object[] array8;
                    if ( myWorker.returnArrayList(Character.class)!= null&&(myWorker.returnArrayList(Character.class)).length>0) {
                    array8 = myWorker.returnArrayList(Character.class);
                    char charArray[] = new char[array8.length];
                    for(int i=0; i<array8.length; i++){
                        charArray[i] = ((String)array8[i]).charAt(0);;
                    }

                    myWorker.sendCharArrayType(charArray,countInput);countInput++;}
                    else showMessage("You must enter a type first");
                    break;

                default :
                    showMessage("You must enter a type first");

            }
            if(myWorker.lengthOfList()>0)
            {
                myWorker.clearList();
            }

        } catch (Exception eException) {
            showMessage("You entered For the wrong type");onResetAll();
           // showMessage(eException.getMessage());//"Incorrect value.");
        }

    }

    // Method to display  messages
    private void showMessage(String tUMessage) {
        Toast.makeText(this, tUMessage, Toast.LENGTH_LONG)
                .show();
    }






}
