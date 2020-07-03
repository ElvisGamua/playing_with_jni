package com.example.gamuatachu.nativethreads;


import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity implements NativeListener {

    private NativeMsClass myWorker = new NativeMsClass(this);  //ok
    private EditText mVlEditTxt;  //ok
    private TextView textView1;//ok
    private Button mStartBtn, mResetBtn;//ok
    private static final int NUMBER_PER_LINE = 10;
    private static int count = 0;
    private static int maxPrimeInt;
    private StringBuilder str
            = new StringBuilder();


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        init();

    }

    private void init() {
        mVlEditTxt = (EditText) findViewById(
                R.id.sVlEditTxt);
        textView1 = findViewById(R.id.text1);
        mResetBtn = findViewById(
                R.id.sResetBtn);
        mResetBtn.setEnabled(false);
        mStartBtn = findViewById(
                R.id.sStartBtn);
        mStartBtn.setOnClickListener(this::startNativeThread);
        mResetBtn.setOnClickListener(this::resetMainUI);
    }

    private void resetMainUI(View view) {
        textView1.setText("");
        count=0;
        str.setLength(0);
        mResetBtn.setEnabled(false);
        mStartBtn.setEnabled(true);
    }


    @Override
    public void setStringBuilder(int nativeInt) {
      count++;
        if (count % NUMBER_PER_LINE == 0) {
            str.append(String.valueOf(nativeInt) + "\n");
            }
        else
            str.append(String.valueOf(nativeInt) + "\t");

  }


    @Override
    public void setUI() {
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                textView1.setText(str);
                mResetBtn.setEnabled(true);
            }
        });

    }


    private void startNativeThread(View view) {
        try {
            String maxPrime = mVlEditTxt.getText().toString();
            if (maxPrime == null) {
                showMessage("You have not entered a number.");
                return;
            }
            maxPrimeInt = Integer.parseInt(maxPrime);
            if (maxPrimeInt < 2) {
                showMessage("You must enter a number greater than or equal to 2.");
                return;
            }
            myWorker.startNativeThread(maxPrimeInt);
            mStartBtn.setEnabled(false);
        } catch (Exception e) {
            showMessage("You have entered a wrong type");
        }
        }


    private void showMessage(String tUMessage) {
        Toast.makeText(this, tUMessage, Toast.LENGTH_LONG)
                .show();
    }
}