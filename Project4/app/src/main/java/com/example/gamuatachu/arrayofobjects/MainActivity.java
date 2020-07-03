package com.example.gamuatachu.arrayofobjects;

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

import java.util.Arrays;
import java.util.Vector;


public class MainActivity extends AppCompatActivity implements ComparingListener{

    private NativeMsClass myWorker = new NativeMsClass(this);
    private EditText mLangAddEdt, mLangDiffEdt;
    private Button mGetBtn, mSetBtn, mResetBtn, mAddObjectBtn, mCompObjBtn;
    private TextView textView1;
    private static int countInput = 0;
    private static boolean toggleKey=false;


    Vector<Languages> vectorOfLanguages = new Vector<>();
    Vector<Languages> vectorToCompare = new Vector<>();
    // Vector<TType> vectorOfLanguages = new Vector<>();

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
                onResetValue();
                return true;
            case R.id.item2:
                (new InfoDialog()).show(getSupportFragmentManager(),null);
                return true;

            default:
                return super.onOptionsItemSelected(item);
        }
    }

    private void init() {

        mLangAddEdt = (EditText) findViewById(
                R.id.sLangAddEdt);
        mLangDiffEdt = (EditText) findViewById(
                R.id.sLangDiffEdt);

        mAddObjectBtn = findViewById(
                R.id.sAddObjectBtn);
       // mResetBtn = findViewById(
                //R.id.sResetBtn);

        mCompObjBtn = findViewById(
                R.id.sCompObjBtn);


        mSetBtn = (Button)findViewById(
                R.id.sSetBtn);
        mSetBtn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {
                sendLanguageArray();
            }
        });

        mGetBtn = findViewById(
                R.id.sGetBtn);
        mAddObjectBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                onAddObject();
            }
        });
        mGetBtn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {
                getLanguageArray();
            }
        });
        textView1 = findViewById(R.id.text1);
       /* mResetBtn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View obView) {
                onResetValue();
            }
        });*/


        mCompObjBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View obView) {
                onCompare();
            }
        });
        mCompObjBtn.setEnabled(false);
        mSetBtn.setEnabled(false);
        (new InfoDialog()).show(getSupportFragmentManager(),null);


    }


    private void onCompare() {
        //myWorker.compareObjects(countInput);
        str.append("\n\n");
        //textView1.setText(str);
        int vecSize = vectorToCompare.size();
        Languages[] lan = vectorToCompare.toArray(new Languages[vectorToCompare.size()]);
        for (int i = 0; i < vecSize; i++) {


            str.append((i + 1) + " set max " + lan[i].toString() + "\n");

        }

        textView1.setText(str);

        vectorToCompare.clear();
    }

    private void onAddObject() {
        try {
            String lan = mLangAddEdt.getText().toString();

            String difficulty = mLangDiffEdt.getText().toString();
            Languages fLan = new Languages(lan, difficulty);

            vectorOfLanguages.add(fLan);
            mSetBtn.setEnabled(true);
            toggleKey=true;

        } catch (Exception e) {
            showMessage("You must enter a value");
        }
    }



    private void getLanguageArray() {

        try {

            str.append("\n");
            for (int i = 0; i < countInput; i++) {

                if (myWorker.getLanguageArray(i) != null) {
                    str.append("Language Object Returned->"+ "\n" + "[ " + Arrays.toString(   myWorker
                      .getLanguageArray(i)).
                            replace("[", "").
                            replace("]",
                            "") + " ]" + "\n");
                }
                str.append("\n");
            }
            textView1.setText(str);
            //str.setLength(0);

        }

        catch (Exception e) {
            showMessage(e.getMessage());
        }
    }

    private void sendLanguageArray() {

        try {
            // Checks if we have added first.
            if (toggleKey==false) {
                showMessage("You Add First");
                return;
            }
            Languages[] lan = vectorOfLanguages.toArray(new Languages[vectorOfLanguages.size()]);
            vectorOfLanguages.clear();


                   myWorker.sendLanguageArray(lan, countInput);
                    countInput++;
                    myWorker.compareObjects(lan);  //added today

            mCompObjBtn.setEnabled(true); toggleKey=false;
        } catch (Exception eException) {
            showMessage("Incorrect value.");
        }

    }

    // method to display ay kind of message.
    private void showMessage(String tUMessage) {
        Toast.makeText(this, tUMessage, Toast.LENGTH_LONG)
                .show();
    }

    private void onResetValue() {
        try {
            //int rsNa = -1;
          for (int i = 0; i < countInput; i++) {
                if (myWorker.getLanguageArray(i) != null)
                    myWorker.resetNative(i);
                else continue;
            }

            str.setLength(0);
            textView1.setText("");
            countInput = 0;

        }  catch (Exception e) {
            showMessage(e.getMessage());
        }
    }


    @Override
    public void onObjectCompare(Languages pLanguageArray) {


        if (pLanguageArray != null) {
            // str.append("Language Type Returned " + pLanguageArray.toString()+ "\n");
            vectorToCompare.add(pLanguageArray);

        }
        // textView1.setText(str);

    }


}
