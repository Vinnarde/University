package com.example.lab3;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.CheckBox;
import android.widget.RadioButton;
import android.widget.RadioGroup;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

class MyException extends Exception {
    // default constructor
    MyException() {
    }

    // parameterized constructor
    MyException(String str) {
        super(str);
    }
}



public class MainActivity extends AppCompatActivity {

    private void messageBox(String message)
    {
        AlertDialog.Builder messageBox = new AlertDialog.Builder(this);
        messageBox.setMessage(message);
        messageBox.setCancelable(false);
        messageBox.setNeutralButton("OK", null);
        messageBox.show();
    }

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
                throw new MyException("Выберите цвет столещницы!");
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


            radioGroup = (RadioGroup) findViewById(R.id.tableSize);
            if (radioGroup.getCheckedRadioButtonId() == -1) {
                throw new MyException("Выберите размер столещницы!");
            }

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

            radioGroup = (RadioGroup) findViewById(R.id.legColor);
            if (radioGroup.getCheckedRadioButtonId() == -1) {
                throw new MyException("Выберите цвет ножек!");
            }
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

            radioGroup = (RadioGroup) findViewById(R.id.legSize);
            if (radioGroup.getCheckedRadioButtonId() == -1) {
                throw new MyException("Выберите размер ножек!");
            }
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


        } catch (MyException e) {
            messageBox(e.getMessage());
        }

    }
}