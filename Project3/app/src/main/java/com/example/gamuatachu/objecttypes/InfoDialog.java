package com.example.gamuatachu.objecttypes;

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
        str.append("1. Enter the language Type"+"\n");
        str.append("2. Enter the Difficulty level"+"\n");
        str.append("3. SET LANGUAGE->create language object in C++"+"\n");
        str.append("4. GET LANGUAGE->get Language object from C++"+"\n");
        str.append("5. RESET to clear Memory and UI"+"\n");
        str.append("6. INFO for this information"+"\n");
        str.append("7. RESET and INFO in menu"+"\n");
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
