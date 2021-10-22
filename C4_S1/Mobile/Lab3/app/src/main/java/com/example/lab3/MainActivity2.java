package com.example.lab3;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

public class MainActivity2 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        Bundle arguments = getIntent().getExtras();
        Table t = null;
        if (arguments != null)
            t = (Table) arguments.getSerializable(Table.class.getSimpleName());

        printTable(t);
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        TextView text = findViewById(R.id.textViewOutput);
        text.setText("");
    }



    private void printTable(Table t) {
        String s = "Вы заказали: \n";
        switch (t.getTableColor()) {
            case BLACK:
                s += "Черная ";
                break;
            case WHITE:
                s += "Белая ";
                break;
            case WHITEOAK:
                s += "Белый дуб ";
                break;
        }
        s += "столещница ";
        switch (t.getTableSize()) {
            case 1:
                s += "100x60 см ";
                break;
            case 2:
                s += "120x60 см ";
                break;
            case 3:
                s += "140x75 см ";
                break;
        }
        s += "\tx1\n";

        switch (t.getLegColor()) {
            case BLACK:
                s += "Черная ";
                break;
            case WHITE:
                s += "Белая ";
                break;
            case WHITEOAK:
                s += "Белый дуб ";
                break;
        }
        s += "ножка ";

        switch (t.getLegSize()) {
            case 1:
                s += "70 см ";
                break;
            case 2:
                s += "регулирующаяся ";
                break;
        }
        s += "\tx4\n";

        if (t.getBetterPackage() == 1)
            s += "Усиленная упаковка для транспортировки \tx1\n";

        TextView text = findViewById(R.id.textViewOutput);
        text.setText(s);

    }
}