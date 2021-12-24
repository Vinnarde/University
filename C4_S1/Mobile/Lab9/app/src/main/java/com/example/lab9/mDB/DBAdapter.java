package com.example.lab9.mDB;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;

import com.example.lab9.Task;

import java.util.ArrayList;

public class DBAdapter {
    Context c;
    SQLiteDatabase db;
    DBHelper helper;

    public DBAdapter(Context c) {
        this.c = c;
        helper = new DBHelper(c);
    }

    public boolean addTask(Task task) {
        try {
            db = helper.getWritableDatabase();

            ContentValues cv = new ContentValues();

            cv.put(Constants.name, task.getName());
            cv.put(Constants.categoryId, task.getName());
            cv.put(Constants.subCategoryId, task.getName());
            cv.put(Constants.description, task.getDescription());
            cv.put(Constants.startDate, task.getStartTime().toString());
            cv.put(Constants.endDate, task.getEndTime().toString());
            cv.put(Constants.status, task.getStatus());

            long result = db.insert(Constants.tbTask, Constants.rowId, cv);
            return result > 0;

        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            helper.close();
        }

        return false;
    }

    public ArrayList<Task> retrieveTasks(String category, String subCategory) {
        ArrayList<Task> tasks = new ArrayList<Task>();

        try {
            db = helper.getWritableDatabase();
            Cursor query = db.rawQuery("SELECT * FROM " + Constants.tbTask +
                    " WHERE " +
                    Constants.categoryId + " = " + "(SELECT id FROM Category WHERE name = " + category + ") AND" +
                    Constants.subCategoryId + " = " + "(SELECT id FROM SubCategory WHERE name = " + subCategory + ")", null);

        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            helper.close();
        }

        return tasks;
    }
}
