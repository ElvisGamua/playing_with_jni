package com.example.gamuatachu.objecttypes;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;



public class MainActivity extends AppCompatActivity {
    private NativeMsClass myWorker = new NativeMsClass();
    private EditText mlangEdit, mDiffiEdit;
    private Button mGetBtn, mSetBtn, mResetBtn;;

    private TextView textView1;
    private static int countInput=0;
    private StringBuilder str
            = new StringBuilder();

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
                onResetLanguage();
                return true;
            case R.id.item2:
                (new InfoDialog()).show(getSupportFragmentManager(),null);
                return true;

            default:
                return super.onOptionsItemSelected(item);
        }
    }


    private void init() {

        mlangEdit = (EditText) findViewById(
                R.id.sLangEdt);
        mDiffiEdit = (EditText) findViewById(
                R.id.sDiffiEdit);
       // mResetBtn = findViewById(
               // R.id.sResetBtn);


        mSetBtn = (Button) findViewById(
                R.id.sSetBtn);
        mSetBtn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View obView) {
                sendLanguage();
            }
        });

        mGetBtn = findViewById(
                R.id.sGetBtn);
        mGetBtn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View obView) {
                getLanguage();
            }
        });
        textView1=  findViewById(R.id.text1);
        (new InfoDialog()).show(getSupportFragmentManager(),null);
        /*mResetBtn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View obView) {
                onResetLanguage();
            }
        });*/

    }




    private void getLanguage() {

        String lang1 = mlangEdit.getText().toString();

       
        // textView1.setText("");

        try {

            for(int i=0;i<countInput;i++)
            {
                if(myWorker.getLanguage(i)!=null)
                {str.append(myWorker.getLanguage(i).toString()+"\n"+"\n");}
            }
            textView1.setText(str);
            str.setLength(0);


        }

        catch (Exception e) {
            showMessage(e.getMessage());
        }
    }

    private void sendLanguage() {

        if (mlangEdit.getText().toString()== null || mlangEdit.getText().toString().isEmpty()||mDiffiEdit.getText().toString().isEmpty()) {
            showMessage("You must fill All fields."); //.charAt(0)==' '
            return;
        }
        String lang2 = mlangEdit.getText().toString();
        char value = mDiffiEdit.getText().toString().charAt(0);

        try {




                    myWorker.sendLanguage(countInput, new Languages(lang2,value,countInput)); countInput++;





        }  catch (Exception eException) {
            showMessage("Incorrect value.");
        }

    }

    // Method to display any kind of message.
    private void showMessage(String tUMessage) {
        Toast.makeText(this, tUMessage, Toast.LENGTH_LONG)
                .show();
    }
    private void onResetLanguage() {
        try{




            for(int i=0;i<countInput;i++)
            {
                if(myWorker.getLanguage(i)!=null)
                    myWorker.resetNative(i);
                else continue;}str.setLength(0);textView1.setText(""); countInput=0;
            mGetBtn.setEnabled(true);
            mSetBtn.setEnabled(true);
        }catch (Exception e) {
            showMessage(e.getMessage());
        }}


}
