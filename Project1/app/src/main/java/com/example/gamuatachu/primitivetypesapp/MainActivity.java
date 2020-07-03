package com.example.gamuatachu.primitivetypesapp;

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


public class MainActivity extends AppCompatActivity implements AdapterView.OnItemSelectedListener{

    private NativeMsClass myWorker = new NativeMsClass();
    private EditText mVlEditTxt;
    private Spinner mTypSpin;
    private Button mGetBtn, mSetBtn, mResetBtn;
    private TextView textView1;

    private static int countInput=0;
    private StringBuilder str
            = new StringBuilder();
    String text=null;
    String checkType[]={null,null,null,null,null,null,null,null,null,null,null,null,null,null,null,null};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

       init();
    }
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.resetanddialog_menu, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case R.id.item1:
                onResetPrimitiveTypes();
                return true;
            case R.id.item2:
                (new InfoDialog()).show(getSupportFragmentManager(),null);
                return true;

            default:
                return super.onOptionsItemSelected(item);
        }
    }
    private void init() {


        mVlEditTxt = (EditText)findViewById(
                R.id.sVlEditTxt);



        mTypSpin = (Spinner) findViewById(
                R.id.sTypSpin);
        ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(this,
                R.array.types, android.R.layout.simple_spinner_item);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        mTypSpin.setAdapter(adapter);
        mTypSpin.setOnItemSelectedListener(this);

        mSetBtn = (Button) findViewById(
                R.id.sSetBtn);
        mSetBtn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {
                sendPrimitiveType();
            }
        });

        mGetBtn = findViewById(
                R.id.sGetBtn);
        mGetBtn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {
                getPrimitiveType();
            }
        });
        textView1=  findViewById(R.id.text1);
        (new InfoDialog()).show(getSupportFragmentManager(),null);
       // mResetBtn = findViewById(
               // R.id.sResetBtn);

       /* mResetBtn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View obView) {
                onResetPrimitiveTypes();
            }
        });*/



    }
    @Override
    public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
        text = parent.getItemAtPosition(position).toString();
        //Toast.makeText(parent.getContext(), text, Toast.LENGTH_SHORT).show();
    }

    @Override
    public void onNothingSelected(AdapterView<?> parent) {

    }

    private void onResetPrimitiveTypes() {
        try{




            for(int i=0;i<countInput;i++)
            {
                //if(myWorker.getStringType(i)!=null)
                    //myWorker.resetNative(i);  //was resetNative(countInput)
               // else continue;}str.setLength(0);textView1.setText(""); countInput=0;

                if(myWorker.getStringType(i)!=null)
                    { myWorker.resetNative(i);}
                else myWorker.resetNative(i);//was resetNative(countInput)
                   }str.setLength(0);textView1.setText(""); countInput=0; for(int i=0;i<checkType.length;i++)
            {
                checkType[i] = null;
            }
        }catch (Exception e) {
            showMessage(e.getMessage());
        }}





    private void getPrimitiveType() {
        str.setLength(0);
        try {
            for(int i=0;i<countInput;i++)
            {


                switch(checkType[i]){
                    case "String":

                    {str.append("String Type Returned  "+myWorker.getStringType(i)+"\n");}break;

                    case "Integer":
                    {str.append("Integer Type Returned "+myWorker.getIntegerType(i)+"\n");} break;

                    case "Boolean":
                    {str.append("Boolean Type Returned "+myWorker.getBooleanType(i)+"\n");}break;

                    case "Byte":
                    {str.append("Byte Type Returned    "+myWorker.getByteType(i)+"\n");}break;


                    case "Char":
                    {str.append("Char Type Returned    "+myWorker.getCharType(i)+"\n");}break;

                    case "Double":
                    {str.append("Double Type Returned  "+myWorker.getDoubleType(i)+"\n");}break;

                    case "Float":
                    {str.append("Float Type Returned   "+myWorker.getFloatType(i)+"\n");}break;

                    case "Long":
                    {str.append("Long Type Returned    "+myWorker.getLongType(i)+"\n");}break;

                    case "Short":
                    {str.append("Short Type Returned   "+myWorker.getShortType(i)+"\n");}break;

                }


            }
            textView1.setText(str);

        }

       catch (Exception e) {
            showMessage(e.getMessage());
        }
    }

    private void sendPrimitiveType() {

       if(text==null)
        {
            showMessage("you have not selected a type");
            return;
        }
        String inputString = mVlEditTxt.getText().toString();
        checkType[countInput]=text;

        try {
            switch (text) {
                case "Boolean":
                    if (inputString.equals("true") || inputString.equals("1")) {
                        myWorker.sendBooleanType( true,countInput);countInput++;
                    } else if (inputString.equals("false")
                            || inputString.equals("0")) {
                        myWorker.sendBooleanType( false,countInput);countInput++;
                    } else {
                        showMessage("Incorrect value.");
                    }
                    break;
                case "Byte":
                    myWorker.sendByteType( Byte.parseByte(inputString),countInput); countInput++;
                    break;
                case "Char":
                    if (inputString.length() == 1) {
                        myWorker.sendCharType( inputString.charAt(0),countInput); countInput++;
                    } else {
                        showMessage("Incorrect value.");
                    }
                    break;
                case "Double":
                    myWorker.sendDoubleType( Double.parseDouble(inputString),countInput); countInput++;
                    break;
                case "Float":
                    myWorker.sendFloatType( Float.parseFloat(inputString),countInput); countInput++;
                    break;
                case "Integer":
                    myWorker.sendIntegerType( Integer.parseInt(inputString),countInput); countInput++;
                    break;
                case "Long":
                    myWorker.sendLongType( Long.parseLong(inputString),countInput); countInput++;
                    break;
                case "Short":
                    myWorker.sendShortType( Short.parseShort(inputString),countInput); countInput++;
                    break;
                case "String":
                    myWorker.sendStringType( inputString,countInput); countInput++;
                    break;

            }
        }  catch (Exception eException) {
            showMessage("Incorrect value.");
        }

    }

    // Method to display any message to the user.
    private void showMessage(String tUMessage) {
        Toast.makeText(this, tUMessage, Toast.LENGTH_LONG)
                .show();
    }







}
