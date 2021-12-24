package com.example.lab9;

import android.annotation.SuppressLint;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;

import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.google.android.material.snackbar.Snackbar;
import com.google.android.material.tabs.TabLayout;

import androidx.viewpager.widget.ViewPager;
import androidx.appcompat.app.AppCompatActivity;

import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Spinner;

import com.example.lab9.ui.main.SectionsPagerAdapter;
import com.example.lab9.databinding.ActivityMainBinding;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Locale;

public class MainActivity extends AppCompatActivity {

    private ActivityMainBinding binding;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        SectionsPagerAdapter sectionsPagerAdapter = new SectionsPagerAdapter(this, getSupportFragmentManager());
        ViewPager viewPager = binding.viewPager;
        viewPager.setAdapter(sectionsPagerAdapter);
        TabLayout tabs = binding.tabs;
        tabs.setupWithViewPager(viewPager);



        try {
            generateContent();
            loadCategory();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void generateContent() throws ParseException {
        SQLiteDatabase db = getBaseContext().openOrCreateDatabase("app.db", MODE_PRIVATE, null);
        db.execSQL("CREATE TABLE IF NOT EXISTS tasks(name TEXT, category TEXT, subCategory TEXT," +
                " description TEXT, dateStart TEXT, dateEnd TEXT, status TEXT,UNIQUE(name))");
        db.execSQL("INSERT OR IGNORE INTO tasks VALUES" +
                "('Task1','category 1','subCategory 1','description1','2021-12-10 20:05:00', '','In Progress'), " +
                "('Task2','category 1','subCategory 2','description1','2021-12-10 20:05:00', '','Open'), " +
                "('Task3','category 2','subCategory 3','description1','2021-12-10 20:05:00', '','Open'), " +
                "('Task4','category 2','subCategory 4','description1','2021-12-10 20:05:00', '','Open')");

//        SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss", Locale.ENGLISH);
//
//        @SuppressLint("Recycle") Cursor query = db.rawQuery("Select * from tasks;", null);
//        while (query.moveToNext()) {
//            String name = query.getString(0);
//            String category = query.getString(1);
//            String subCategory = query.getString(2);
//            String description = query.getString(3);
//            Date startDate = formatter.parse(query.getString(4));
//            Date endDate = formatter.parse(query.getString(5));
//            String status = query.getString(6);

//        }
    }


}