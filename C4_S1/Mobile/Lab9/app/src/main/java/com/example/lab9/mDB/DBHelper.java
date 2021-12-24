package com.example.lab9.mDB;

import android.content.Context;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class DBHelper extends SQLiteOpenHelper {
    public DBHelper(Context context) {
        super(context, Constants.dbName, null, 1);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        try {
            db.execSQL(Constants.createTableTask);
            db.execSQL(Constants.createTableCategory);
            db.execSQL(Constants.createTableSubCategory);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int i, int i1) {
        try {
            db.execSQL(Constants.dropTableTask);
            db.execSQL(Constants.dropTableCategory);
            db.execSQL(Constants.dropTableSubCategory);

            db.execSQL(Constants.createTableTask);
            db.execSQL(Constants.createTableCategory);
            db.execSQL(Constants.createTableSubCategory);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
