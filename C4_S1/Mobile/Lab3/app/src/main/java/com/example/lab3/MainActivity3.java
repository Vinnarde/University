package com.example.lab3;

import androidx.appcompat.app.AppCompatActivity;

import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity3 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main3);

        results();
    }
    private void results()
    {
        SQLiteDatabase db = getBaseContext().openOrCreateDatabase("app.db", MODE_PRIVATE, null);
        db.execSQL("CREATE TABLE IF NOT EXISTS orders (zakaz TEXT, price REAL, date TEXT)");
        Cursor query = db.rawQuery("SELECT * FROM orders;", null);
        TextView output = findViewById(R.id.dbSelect);
        output.setText("");
        while (query.moveToNext()) {

            String order = query.getString(0);
            double price = query.getDouble(1);
            String date = query.getString(2);

            output.append("Заказ:\n" + order + "Стоимость: " + price + " руб.\nДата: " + (date.equals("null") ? "-" : date) + "\n\n");
        }
    }

}