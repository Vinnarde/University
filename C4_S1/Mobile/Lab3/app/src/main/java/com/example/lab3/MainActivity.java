package com.example.lab3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.CheckBox;
import android.widget.RadioButton;
import android.widget.RadioGroup;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void functionForButton(View view) {
        Table t = new Table(0, 0, 0, Color.NONE, Color.NONE);
        try {
            CheckBox betterPackage = findViewById(R.id.checkBoxBetterPackage);
            if (betterPackage.isChecked())
                t.setBetterPackage(1);

            RadioGroup radioGroup = (RadioGroup) findViewById(R.id.tableColor);
            if (radioGroup.getCheckedRadioButtonId() == -1) {
            }
            // table color
            RadioButton rb = findViewById(R.id.radioButtonColorBlack);
            if (rb.isChecked())
                t.setTableColor(Color.BLACK);
            rb = findViewById(R.id.radioButtonColorWhite);
            if (rb.isChecked())
                t.setTableColor(Color.WHITE);
            rb = findViewById(R.id.radioButtonColorWhiteOak);
            if (rb.isChecked())
                t.setTableColor(Color.WHITEOAK);


            //  table size
            rb = findViewById(R.id.radioButtonSize10060);
            if (rb.isChecked())
                t.setTableSize(1);
            rb = findViewById(R.id.radioButtonSize12060);
            if (rb.isChecked())
                t.setTableSize(2);
            rb = findViewById(R.id.radioButtonSize14075);
            if (rb.isChecked())
                t.setTableSize(3);

            // leg color
            rb = findViewById(R.id.radioButtonLegColorBlack);
            if (rb.isChecked())
                t.setLegColor(Color.BLACK);
            rb = findViewById(R.id.radioButtonLegColorWhite);
            if (rb.isChecked())
                t.setLegColor(Color.WHITE);
            rb = findViewById(R.id.radioButtonLegColorWhiteOak);
            if (rb.isChecked())
                t.setLegColor(Color.WHITEOAK);

            // leg size
            rb = findViewById(R.id.radioButtonLegSize70);
            if (rb.isChecked())
                t.setLegSize(1);
            rb = findViewById(R.id.radioButtonLegSizeAjustable);
            if (rb.isChecked())
                t.setLegSize(2);


            Intent intent = new Intent(this, MainActivity2.class);
            intent.putExtra(Table.class.getSimpleName(), t);
            startActivity(intent);


        } catch (Exception e) {

        }

    }
}