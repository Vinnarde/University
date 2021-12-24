package com.example.lab8widget;

import android.app.PendingIntent;
import android.appwidget.AppWidgetManager;
import android.appwidget.AppWidgetProvider;
import android.content.Context;
import android.content.Intent;
import android.widget.RemoteViews;
import android.widget.TextView;
import android.widget.Toast;

import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;

/**
 * Implementation of App Widget functionality.
 */
public class NewYearWidget extends AppWidgetProvider {

    SimpleDateFormat mSimpleDateFormat = new SimpleDateFormat("DD:HH:mm:ss");
    TextView mTextViewCountDown;
    TextView mTextViewReminder;
    
    static String[] reminders = {"Не забудьте поставить ёлку!", "Не забудьте купить подарки!", "Пора подумать о новогоднем меню!"};
    static int curId = 0;

    

    static String ConvertSecToDay(long n) {
        String result = "";

        long day = n / (24 * 3600);
        n %= (24 * 3600);

        long hour = n / 3600;
        n %= 3600;

        long minutes = n / 60;
        n %= 60;

        long seconds = n;

        result += day + "д " + hour + "ч " + minutes + "м " + seconds + "с";
        return result;
    }

    static void updateAppWidget(Context context, AppWidgetManager appWidgetManager,
                                int appWidgetId) {

        LocalDateTime time = LocalDateTime.now();
        int year = time.getYear();
        ++year;

        LocalDateTime newYearTime = LocalDateTime.of(year, 1, 1, 0, 0, 0);

        long seconds = ChronoUnit.SECONDS.between(time, newYearTime);
        // Construct the RemoteViews object
        RemoteViews views = new RemoteViews(context.getPackageName(), R.layout.new_year_widget);

        views.setTextViewText(R.id.textViewText, "До нового года:");
        views.setTextViewText(R.id.textViewTimer, ConvertSecToDay(seconds));
        views.setTextViewText(R.id.textViewReminders, reminders[curId]);
        curId = (curId + 1) % 3;

        //Create an Intent with the AppWidgetManager.ACTION_APPWIDGET_UPDATE action//
        Intent intentUpdate = new Intent(context, NewYearWidget.class);
        intentUpdate.setAction(AppWidgetManager.ACTION_APPWIDGET_UPDATE);

//Update the current widget instance only, by creating an array that contains the widget’s unique ID//
        int[] idArray = new int[]{appWidgetId};
        intentUpdate.putExtra(AppWidgetManager.EXTRA_APPWIDGET_IDS, idArray);

//Wrap the intent as a PendingIntent, using PendingIntent.getBroadcast()//
        PendingIntent pendingUpdate = PendingIntent.getBroadcast(
                context, appWidgetId, intentUpdate,
                PendingIntent.FLAG_UPDATE_CURRENT);

//Send the pending intent in response to the user tapping the ‘Update’ TextView//

        views.setOnClickPendingIntent(R.id.button, pendingUpdate);

        // Instruct the widget manager to update the widget
        appWidgetManager.updateAppWidget(appWidgetId, views);
    }

    @Override
    public void onUpdate(Context context, AppWidgetManager appWidgetManager, int[] appWidgetIds) {
        // There may be multiple widgets active, so update all of them
        for (int appWidgetId : appWidgetIds) {
            updateAppWidget(context, appWidgetManager, appWidgetId);
            Toast.makeText(context, "Widget has been updated! ", Toast.LENGTH_SHORT).show();
        }
    }

    @Override
    public void onEnabled(Context context) {
        // Enter relevant functionality for when the first widget is created
    }

    @Override
    public void onDisabled(Context context) {
        // Enter relevant functionality for when the last widget is disabled
    }
}