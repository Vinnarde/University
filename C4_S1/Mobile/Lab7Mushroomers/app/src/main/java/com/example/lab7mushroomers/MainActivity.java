package com.example.lab7mushroomers;

import static java.lang.Thread.sleep;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.app.ActionBar;
import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.os.Bundle;
import android.util.DisplayMetrics;
import android.view.MotionEvent;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;

import java.util.Random;


public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(new DrawView(this));
    }
}

class DrawView extends View {
    Paint p = new Paint();

    static int width;
    static int height;

    static Game game = new Game();

    Bitmap bitmapKochki;
    Bitmap bitmapRosha;
    Bitmap bitmapPusha;
    Bitmap bitmapBackground;
    Bitmap bitmapCapcan;
    Bitmap bitmapDubovik;
    Bitmap bitmapOpyata;
    Bitmap bitmapShoe;
    Bitmap resetButton;

    private void loadBitmaps() {
        bitmapBackground = BitmapFactory.decodeResource(getResources(), R.drawable.loc_dubrava);
        bitmapBackground = Bitmap.createScaledBitmap(bitmapBackground, width, height, true);

        final float step = (height - 100.0f - height / 3.0f) / 4.0f;

        bitmapKochki = BitmapFactory.decodeResource(getResources(), R.drawable.cap_kochki_down);
        bitmapKochki = Bitmap.createScaledBitmap(bitmapKochki, width / 12, (int) step, true);

        bitmapRosha = BitmapFactory.decodeResource(getResources(), R.drawable.cap_rosha_down);
        bitmapRosha = Bitmap.createScaledBitmap(bitmapRosha, width / 12, (int) step, true);

        bitmapPusha = BitmapFactory.decodeResource(getResources(), R.drawable.cap_pusha_down);
        bitmapPusha = Bitmap.createScaledBitmap(bitmapPusha, width / 12, (int) step, true);

        bitmapCapcan = BitmapFactory.decodeResource(getResources(), R.drawable.capcan);
        bitmapCapcan = Bitmap.createScaledBitmap(bitmapCapcan, width / 12, (int) step, true);

        bitmapDubovik = BitmapFactory.decodeResource(getResources(), R.drawable.mushroom_forest_dubovik);
        bitmapDubovik = Bitmap.createScaledBitmap(bitmapDubovik, width / 12, (int) step, true);

        bitmapOpyata = BitmapFactory.decodeResource(getResources(), R.drawable.mushroom_kitchen_opyata);
        bitmapOpyata = Bitmap.createScaledBitmap(bitmapOpyata, width / 12, (int) step, true);

        bitmapShoe = BitmapFactory.decodeResource(getResources(), R.drawable.forest_shoe);
        bitmapShoe = Bitmap.createScaledBitmap(bitmapShoe, width / 12, (int) step, true);

        resetButton = BitmapFactory.decodeResource(getResources(), R.drawable.reset);
        resetButton = Bitmap.createScaledBitmap(resetButton, width / 6, (int) step, true);
    }

    public DrawView(Context context) {
        super(context);
        DisplayMetrics displayMetrics = getResources().getDisplayMetrics();

        width = displayMetrics.widthPixels;
        height = displayMetrics.heightPixels;

        loadBitmaps();
    }

    @Override
    protected void onDraw(Canvas canvas) {
//        Bitmap background = BitmapFactory.decodeResource(getResources(), R.drawable.loc_dubrava);
//        background = Bitmap.createScaledBitmap(background, width, height, true);
        canvas.drawBitmap(bitmapBackground, 0, 0, p);

        p.setColor(Color.WHITE);
        p.setStrokeWidth(5.0f);

//        canvas.drawLine(width / 6, height / 3, 5 * width / 6, height / 3, p);
//        canvas.drawLine(width / 6, height - 100, 5 * width / 6, height - 100, p);

        if (!game.isRun()) {
            p.setColor(Color.GRAY);
            canvas.drawRect(width / 6.0f, height / 3.0f, width * 5.0f / 6.0f, height - 100.0f, p);
            p.setColor(Color.WHITE);
            canvas.drawText("Mushrooms: " + game.getScore(), width / 6.0f + 10.0f, height / 3.0f + 90, p);
            drawBitmap(canvas, 5 * width / 12, height * 2 / 3 + 100, resetButton);
        } else {


            float step = (height - 100 - height / 3.0f) / 4.0f;

            // debug grid
            for (int i = 0; i < 9; ++i) {
                canvas.drawLine((2 + i) * width / 12.0f, height / 3.0f, (2 + i) * width / 12.0f, height - 100, p);
            }

            for (int i = 0; i < 5; ++i) {
                canvas.drawLine(width / 6.0f, height / 3.0f + step * i,
                        5 * width / 6.0f, height / 3.0f + step * i, p);
            }
            // debug grid end

            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 8; ++j) {
                    if (game.getChecked(i, j) != 0) {
                        switch (game.getChecked(i, j)) {
                            case 1:
                                drawBitmap(canvas, (2 + j) * width / 12, height / 3 + (int) (i * step), bitmapKochki);
                                break;
                            case 2:
                                drawBitmap(canvas, (2 + j) * width / 12, height / 3 + (int) (i * step), bitmapPusha);
                                break;
                            case 3:
                                drawBitmap(canvas, (2 + j) * width / 12, height / 3 + (int) (i * step), bitmapRosha);
                                break;
                        }
                    } else {
                        switch (game.get(i, j)) {
                            case 1:
                                drawBitmap(canvas, (2 + j) * width / 12, height / 3 + (int) (i * step), bitmapDubovik);
                                break;
                            case 2:
                                drawBitmap(canvas, (2 + j) * width / 12, height / 3 + (int) (i * step), bitmapOpyata);
                                break;
                            case 3:
                                drawBitmap(canvas, (2 + j) * width / 12, height / 3 + (int) (i * step), bitmapShoe);
                                break;
                            case 4:
                                drawBitmap(canvas, (2 + j) * width / 12, height / 3 + (int) (i * step), bitmapCapcan);
                                break;

                        }
                    }
                }
            }

            p.setTextSize(80);
            p.setColor(Color.RED);

            canvas.drawText("Attempts: " + game.getAttempts(), 50, 80, p);
            canvas.drawText("Mushrooms: " + game.getScore(), 50, 150, p);
        }
//        if (!game.isRun()) {
//            p.setColor(Color.GRAY);
//            canvas.drawRect(width / 6.0f, height / 3.0f, width * 5.0f / 6.0f, height - 100.0f, p);
//            p.setColor(Color.WHITE);
//            canvas.drawText("Mushrooms: " + game.getScore(), width / 6.0f + 10.0f, height / 3.0f + 90, p);
//            drawBitmap(canvas, 5 * width / 12, height * 2 / 3 + 100, resetButton);
//        }

    }

    @SuppressLint("ClickableViewAccessibility")
    @Override
    public boolean onTouchEvent(MotionEvent event) {
        float x = event.getX();
        float y = event.getY();

        if (game.isRun()) {
            int posX = -1, posY = -1;
            final float step = (height - height / 3.0f - 100.0f) / 4.0f;

            for (int i = 0; i < 4; ++i) {
                if (y > height / 3.0f + i * step && y < height / 3.0f + (i + 1) * step) {
                    posX = i;
                    break;
                }
            }

            for (int j = 0; j < 8; ++j) {
                if (x > (2 + j) * width / 12.0f && x < (3 + j) * width / 12.0f) {
                    posY = j;
                    break;
                }
            }

            if (posY != -1 && posX != -1) {
                if (game.getChecked(posX, posY) != 0) {
                    game.setChecked(posX, posY);
                    switch (game.get(posX, posY)) {
                        case 0:
                            game.setAttempts(-1);
                            break;
                        case 1:
                            game.setAttempts(-1);
                            game.setScore(+1);
                            break;
                        case 2:
                            game.setAttempts(-1);
                            game.setScore(+3);
                            break;
                        case 3:
                            game.setAttempts(+3);
                            break;
                        case 4:
                            game.setAttempts(-3);
                            break;
                        case 5:
                            game.setAttempts(-1);
                            game.setScore(+10);
                            break;
                    }
                }
                invalidate();
            }
        } else {
            if (x >= 5.0f * width / 12.0f && x <= 7.0f * width / 12.0f && y > (height * 2.0f / 3.0f + 100.0f) && y < height - 100.0f) {
                game.reset();
                invalidate();
            }
        }

        return true;
    }

    public void drawKochki(Canvas canvas, int x, int y) {

        canvas.drawBitmap(bitmapKochki, x, y, p);
    }

    public void drawPusha(Canvas canvas, int x, int y) {

        canvas.drawBitmap(bitmapPusha, x, y, p);
    }

    public void drawRosha(Canvas canvas, int x, int y) {
        canvas.drawBitmap(bitmapRosha, x, y, p);
    }

    public void drawBitmap(Canvas canvas, int x, int y, Bitmap bitmap) {
        canvas.drawBitmap(bitmap, x, y, p);
    }
}