package com.example.lab9.mDB;

public class Constants {

    /*
    COLUMNS
     */

    static final String rowId = "id";
    static final String name = "name";
    static final String categoryName = "category";
    static final String categoryId = "categoryId";
    static final String subCategoryName = "subCategory";
    static final String subCategoryId = "subCategoryId";
    static final String description = "description";
    static final String startDate = "startDate";
    static final String endDate = "endDate";
    static final String status = "status";

    /*
    DB PROPERTIES
     */

    static final String dbName = "app.db";
    static final String tbTask = "Task";
    static final String tbCategory = "Category";
    static final String tbSubCategory = "SubCategory";

    /*
    TABLE CREATION STATEMENTS
     */

    static final String createTableTask = "CREATE TABLE IF NOT EXIST " + tbTask +
            "(id INTEGER PRIMARY KEY AUTOINCREMENT," +
            "name TEXT NOT NULL," +
            "categoryId INTEGER NOT NULL," +
            "subCategoryId INTEGER NOT NULL," +
            "description TEXT NOT NULL," +
            "startDate TEXT NOT NULL," +
            "endDate TEXT," +
            "status TEXT)";

    static final String createTableCategory = "CREATE TABLE IF NOT EXIST " + tbCategory +
            "(id INTEGER PRIMARY KEY AUTOINCREMENT," +
            "name TEXT NOT NULL)";

    static final String createTableSubCategory = "CREATE TABLE IF NOT EXIST " + tbCategory +
            "(id INTEGER PRIMARY KEY AUTOINCREMENT," +
            "name TEXT NOT NULL)";


    static final String dropTableTask = "DROP TABLE IF EXIST " + tbTask;

    static final String dropTableCategory = "DROP TABLE IF EXIST " + tbCategory;

    static final String dropTableSubCategory = "DROP TABLE IF EXIST " + tbSubCategory;

}
