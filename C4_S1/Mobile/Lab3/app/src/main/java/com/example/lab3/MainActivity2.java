package com.example.lab3;

import androidx.appcompat.app.AppCompatActivity;

import android.content.ContentValues;
import android.content.Intent;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import java.text.SimpleDateFormat;
import java.util.Date;

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
        String s = "Вы заказали: \n- ";
        String strPrice = "Стомость: \n- ";
        double totalPrice = 0.0;
        double tablePrice = 0.0;
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
                tablePrice += 500.0;
                break;
            case 2:
                s += "120x60 см ";
                tablePrice += 700.0;
                break;
            case 3:
                s += "140x75 см ";
                tablePrice += 1000.0;
                break;
        }
        s += "\tx1\n- ";

        totalPrice += tablePrice;
        strPrice += tablePrice + " руб.\n- ";

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

        double legPrice = 0.0;
        switch (t.getLegSize()) {
            case 1:
                s += "70 см ";
                legPrice = 150.0 * 4.0;
                break;
            case 2:
                s += "регулирующаяся ";
                legPrice = 250.0 * 4.0;
                break;
        }
        s += "\tx4\n";

        totalPrice += legPrice;
        strPrice += legPrice + " руб.\n";

        if (t.getBetterPackage() == 1) {
            s += "- Усиленная упаковка для транспортировки \tx1\n";
            totalPrice += 100.0;
            strPrice += "- " + 100.0 + " руб.\n";
        }

        strPrice += "Общая стоимость: " + totalPrice + " руб.\n";

        String resultString = s + '\n' + strPrice;

        TextView text = findViewById(R.id.textViewOutput);
        text.setText(resultString);

        SQLiteDatabase db = getBaseContext().openOrCreateDatabase("app.db", MODE_PRIVATE, null);
//        db.execSQL("drop table orders");
        db.execSQL("CREATE TABLE IF NOT EXISTS orders (zakaz TEXT, price REAL, date TEXT)");


        String formattedString = s.replace("Вы заказали: \n", "");

        ContentValues cv = new ContentValues();
        cv.put("zakaz", formattedString);
        cv.put("price", totalPrice);
        SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
        Date date = new Date();
        cv.put("date", formatter.format(date));
        db.insert("orders", null, cv);

    }

    public void showDatabase(View view)
    {
        Intent intent = new Intent(MainActivity2.this, MainActivity3.class);
        MainActivity2.this.startActivity(intent);
    }
}