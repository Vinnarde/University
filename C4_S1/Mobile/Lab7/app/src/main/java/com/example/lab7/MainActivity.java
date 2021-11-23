package com.example.lab7;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.SharedPreferences;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.media.AudioAttributes;
import android.media.MediaPlayer;
import android.media.SoundPool;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.view.Menu;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    private static final String PREFS = "Preferences";

    public static int click, gameTheme;

    public static boolean musicState;
    public static boolean soundState;

    public static SoundPool soundPool;
    public static MediaPlayer mediaPlayer;

    SharedPreferences settings;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(new DrawView(this));
        settings = getSharedPreferences(PREFS, MODE_PRIVATE);

        AudioAttributes audioAttributes =
                new AudioAttributes.Builder()
                        .setUsage(AudioAttributes.USAGE_ASSISTANCE_SONIFICATION)
                        .setContentType(AudioAttributes.CONTENT_TYPE_SONIFICATION)
                        .build();
        soundPool = new SoundPool
                .Builder()
                .setMaxStreams(1)
                .setAudioAttributes(audioAttributes)
                .build();

        mediaPlayer = MediaPlayer.create(this, R.raw.gametheme);

        click = soundPool.load(this, R.raw.click, 1);
    }

    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.mymenu, menu);

        musicState = settings.getBoolean("music", true);
        soundState = settings.getBoolean("sounds", true);

        MenuItem item = menu.findItem(R.id.musicTurn);
        item.setChecked(musicState);

        item = menu.findItem(R.id.soundsTurn);
        item.setChecked(soundState);

        if (musicState)
            mediaPlayer.start();
        return true;
    }

    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();

        SharedPreferences.Editor edit = settings.edit();


        switch (id) {
            case R.id.musicTurn:
                item.setChecked(!item.isChecked());
                edit.putBoolean("music", item.isChecked());
                musicState = item.isChecked();

                if (musicState) {
                    if (!mediaPlayer.isPlaying())
                        mediaPlayer.start();
                } else {
                    soundPool.stop(gameTheme);
                    mediaPlayer.pause();
                }

                break;
            case R.id.soundsTurn:
                item.setChecked(!item.isChecked());
                edit.putBoolean("sounds", item.isChecked());
                soundState = item.isChecked();
                break;
        }

        edit.apply();

        return true;
    }
}


class DrawView extends View {
    Paint p = new Paint();

    static Game game = new Game();

    static int width;
    static int height;

    public DrawView(Context context) {
        super(context);
    }

    @Override
    protected void onDraw(Canvas canvas) {
        canvas.drawColor(Color.BLACK);
        DisplayMetrics displayMetrics = getResources().getDisplayMetrics();

        width = displayMetrics.widthPixels;
        height = displayMetrics.heightPixels;

        p.setColor(Color.BLUE);
        p.setStrokeWidth(10);

        canvas.drawLine(0.0f, width / 3.0f, width, width / 3.0f, p);
        canvas.drawLine(0.0f, width * 2.0f / 3.0f, width, width * 2.0f / 3.0f, p);
        canvas.drawLine(width / 3.0f, 50.0f, width / 3.0f, width * 1.0f, p);
        canvas.drawLine(width * 2.0f / 3.0f, 50, width * 2.0f / 3.0f, width * 1.0f, p);

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {

                switch (game.get(i, j)) {
                    case 1:
                        drawCrest(canvas, 50 + i * width / 3, 50 + j * width / 3);
                        break;
                    case 2:
                        drawCircle(canvas, 50 + i * width / 3, 50 + j * width / 3);
                }
            }
        }

        String s = "";
        int state = game.check();
        if (state == 0 && game.getPlayer() == 1)
            s = "Ход первого игрока";
        else if (state == 0 && game.getPlayer() == 2)
            s = "Ход второго игрока";
        else if (state != 9) {
            if (state != 0 && game.getPlayer() == 2)
                s = "Победа первого игрока";
            else if (state != 0 && game.getPlayer() == 1)
                s = "Победа второго игрока";
        } else
            s = "Ничья";

        p.setColor(Color.WHITE);

        if (state != 0) {
            switch (state) {
                case 1:
                    canvas.drawLine(width / 6, 50, width / 6, width - 50, p);
                    break;
                case 2:
                    canvas.drawLine(3 * width / 6, 50, 3 * width / 6, width - 50, p);
                    break;
                case 3:
                    canvas.drawLine(5 * width / 6, 50, 5 * width / 6, width - 50, p);
                    break;
                case 4:
                    canvas.drawLine(50, width / 6, width - 50, width / 6, p);
                    break;
                case 5:
                    canvas.drawLine(50, 3 * width / 6, width - 50, 3 * width / 6, p);
                    break;
                case 6:
                    canvas.drawLine(50, 5 * width / 6, width - 50, 5 * width / 6, p);
                    break;
                case 7:
                    canvas.drawLine(50, 50, width - 50, width - 50, p);
                    break;
                case 8:
                    canvas.drawLine(width - 50, 50, 50, width - 50, p);
                    break;
            }
        }

        p.setColor(Color.GREEN);
        p.setTextSize(64);
        canvas.drawText(s, 10, width + 50, p);
        canvas.drawText("State: " + state, 10, width + 150, p);
    }

    public void drawCrest(Canvas canvas, int x, int y) {
        Bitmap bitmap = BitmapFactory.decodeResource(getResources(), R.drawable.crest);
        bitmap = Bitmap.createScaledBitmap(bitmap, width / 3 - 100, width / 3 - 100, true);
        canvas.drawBitmap(bitmap, x, y, p);
    }

    public void drawCircle(Canvas canvas, int x, int y) {
        Bitmap bitmap = BitmapFactory.decodeResource(getResources(), R.drawable.circle);
        bitmap = Bitmap.createScaledBitmap(bitmap, width / 3 - 100, width / 3 - 100, true);
        canvas.drawBitmap(bitmap, x, y, p);
    }

    public boolean onTouchEvent(MotionEvent event) {

        if (game.getRun()) {

            float x = event.getX();
            float y = event.getY();
            DisplayMetrics displayMetrics = getResources().getDisplayMetrics();
            final int w = displayMetrics.widthPixels;
            final int h = displayMetrics.heightPixels;

            int i = -1, j = -1;
            if (x >= 0 && x <= w / 3.0f) i = 0;
            if (x >= w / 3.0f + 10.0f && x <= 2.0f * w / 3.0f + 10) i = 1;
            if (x >= 2.0f * w / 3.0f + 20 && x <= width) i = 2;

            if (y >= 0 && y <= w / 3.0f) j = 0;
            if (y >= w / 3.0f + 10.0f && y <= 2.0f * w / 3.0f + 10) j = 1;
            if (y >= 2.0f * w / 3.0f + 20 && y <= width) j = 2;

            if (i != -1 && j != -1) {
                if (game.get(i, j) == 0) {
                    game.set(i, j);
                    game.changePLayer();

                    if (MainActivity.soundState)
                        MainActivity.soundPool.play(MainActivity.click, 1, 1, 1, 0, 1);

                    invalidate();

                }
            }
        }
        return true;
    }
}