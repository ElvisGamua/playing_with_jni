package com.example.gamuatachu.primitivetypesapp;

import android.app.Dialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.support.v7.app.AppCompatDialogFragment;
import android.support.v7.app.AlertDialog;

public class InfoDialog extends AppCompatDialogFragment {
    private StringBuilder str
            = new StringBuilder();
    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState) {

        str.append("1. Enter value"+"\n");
        str.append("2. Select the Type"+"\n");
        str.append("3. SEND to send to C++"+"\n");
        str.append("4. GET to get from C++"+"\n");
        str.append("5. RESET to clear Memory and UI"+"\n");
        str.append("6. RESET and INFO in menu"+"\n");
        AlertDialog.Builder builder = new AlertDialog.Builder(getActivity());
        builder.setTitle("How to use this App")
                .setMessage(str)
                .setPositiveButton("ok", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {

                    }
                });

        return builder.create();
    }
}

