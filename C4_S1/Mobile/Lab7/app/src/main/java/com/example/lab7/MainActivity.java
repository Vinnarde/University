package com.example.lab7;

import androidx.appcompat.app.AppCompatActivity;

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

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(new DrawView(this));
    }


}

class DrawView extends View {
    Paint p = new Paint();

    static Game game = new Game();

    public DrawView(Context context) {
        super(context);
    }

    @Override
    protected void onDraw(Canvas canvas) {
        canvas.drawColor(Color.BLACK);
        DisplayMetrics displayMetrics = getResources().getDisplayMetrics();

        final int width = displayMetrics.widthPixels;
        final int height = displayMetrics.heightPixels;

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
    }

    public void drawCrest(Canvas canvas, int x, int y) {
        Bitmap bitmap = BitmapFactory.decodeResource(getResources(), R.drawable.crest);
        canvas.drawBitmap(bitmap, x, y, p);
    }

    public void drawCircle(Canvas canvas, int x, int y) {
        Bitmap bitmap = BitmapFactory.decodeResource(getResources(), R.drawable.circle);
        canvas.drawBitmap(bitmap, x, y, p);
    }

    public boolean onTouchEvent(MotionEvent event) {
        float x = event.getX();
        float y = event.getY();
        DisplayMetrics displayMetrics = getResources().getDisplayMetrics();
        final int w = displayMetrics.widthPixels;
        final int h = displayMetrics.heightPixels;

        int i = 0, j = 0;
        if (x >= 0 && x <= w / 3.0f) i = 0;
        if (x >= w / 3.0f + 10.0f && x <= 2.0f * w / 3.0f + 10) i = 1;
        if (x >= 2.0f * w / 3.0f + 20) i = 2;

        if (y >= 0 && y <= w / 3.0f) i = 0;
        if (y >= w / 3.0f + 10.0f && y <= 2.0f * w / 3.0f + 10) i = 1;
        if (y >= 2.0f * w / 3.0f + 20) i = 2;

        if (game.get(i, j) == 0) {
            game.set(i, j);
            game.changePLayer();
            invalidate();
        }
        return true;
    }

}