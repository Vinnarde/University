package com.example.lab2;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.view.View;
import android.text.*;
import android.widget.EditText;
import android.widget.TextView;

import java.math.BigInteger;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    @SuppressLint("SetTextI18n")
    public void ConvertToBinary(View view) {
        EditText varInput = findViewById(R.id.varInput);
        TextView varOutput = findViewById(R.id.varOutput);
        try {
            int number = Integer.parseInt(varInput.getText().toString());
            varOutput.setText(Integer.toBinaryString(number));
        } catch (Exception e) {
            varOutput.setText("Something went wrong!");
        }
    }
}