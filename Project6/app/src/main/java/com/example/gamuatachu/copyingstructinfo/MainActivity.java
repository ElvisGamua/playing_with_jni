package com.example.gamuatachu.copyingstructinfo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements StructCopyListener {
    private NativeMsClass myWorker = new NativeMsClass(this);
    private Button mFillGetUpdatedBtn,mPrintObjectBtn,mResetBtn;
    private TextView textView1;
    private StringBuilder str
            = new StringBuilder();
    private ITDepartmentInfo pITInfo;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

      init();
    }

    private void init() {

        mPrintObjectBtn= (Button) findViewById(
                R.id.sPrintObjectBtn);
        mFillGetUpdatedBtn = (Button) findViewById(
                R.id.sFillGetUpdatedBtn);
        mResetBtn= (Button) findViewById(
                R.id.sResetBtn);

        mResetBtn.setEnabled(false);
        mFillGetUpdatedBtn.setEnabled(false);

        mPrintObjectBtn.setOnClickListener(this::printJavaClsObject);
        mFillGetUpdatedBtn.setOnClickListener(this::fillAndGetStructInC);
        mResetBtn.setOnClickListener(this::resetNativeClrUI);
        textView1 = findViewById(R.id.text1);
        pITInfo=new ITDepartmentInfo();
    }

    private void resetNativeClrUI(View view) {
       myWorker.resetNative();
       str.setLength(0);
        textView1.setText("");
        mPrintObjectBtn.setEnabled(true);
        mResetBtn.setEnabled(false);
        pITInfo=new ITDepartmentInfo();
    }


    private void printJavaClsObject(View view) {
       str.append( pITInfo.toString()+"\n"+"\n");
        textView1.setText(str);
        mPrintObjectBtn.setEnabled(false);
        mFillGetUpdatedBtn.setEnabled(true);
    }

    private void fillAndGetStructInC(View view)  {
        //ITDepartmentInfo pITInfo=new ITDepartmentInfo();
        myWorker.fillAndGetStructInNative(pITInfo);
        mFillGetUpdatedBtn.setEnabled(false);
        mResetBtn.setEnabled(true);
    }

    @Override
    public void printStruct(ITDepartmentInfo pValue) {
        str.append( pValue.toString1());
        textView1.setText(str);
        }

}
