package com.example.testvibration;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Context;
import android.os.Bundle;
import android.os.VibrationEffect;
import android.os.Vibrator;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    // buttons for all the types of the vibration effects
    Button bNormalVibration, bClickVibration, bDoubleClickVibration, bTickVibration, bHeavyClickVibration;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // get the VIBRATOR_SERVICE system service
        final Vibrator vibrator = (Vibrator) getSystemService(Context.VIBRATOR_SERVICE);

        // register all of the buttons with their IDs
        bNormalVibration = findViewById(R.id.normalVibrationButton);
        bClickVibration = findViewById(R.id.clickVibrationButton);
        bDoubleClickVibration = findViewById(R.id.doubleClickVibrationButton);
        bTickVibration = findViewById(R.id.tickVibrationButton);
        bHeavyClickVibration = findViewById(R.id.heavyClickVibrationButton);

        // handle normal vibration button
        bNormalVibration.setOnClickListener(v -> {
            final VibrationEffect vibrationEffect1;

            // this is the only type of the vibration which requires system version Oreo (API 26)

            // this effect creates the vibration of default amplitude for 1000ms(1 sec)
            vibrationEffect1 = VibrationEffect.createOneShot(1000, VibrationEffect.DEFAULT_AMPLITUDE);

            // it is safe to cancel other vibrations currently taking place
            vibrator.cancel();
            vibrator.vibrate(vibrationEffect1);
        });

        // handle click vibration button
        bClickVibration.setOnClickListener(v -> {

            // this type of vibration requires API 29
            final VibrationEffect vibrationEffect2;

            // create vibrator effect with the constant EFFECT_CLICK
            vibrationEffect2 = VibrationEffect.createPredefined(VibrationEffect.EFFECT_CLICK);

            // it is safe to cancel other vibrations currently taking place
            vibrator.cancel();

            vibrator.vibrate(vibrationEffect2);
        });

        // handle double click vibration button
        bDoubleClickVibration.setOnClickListener(v -> {

            final VibrationEffect vibrationEffect3;

            // this type of vibration requires API 29

            // create vibrator effect with the constant EFFECT_DOUBLE_CLICK
            vibrationEffect3 = VibrationEffect.createPredefined(VibrationEffect.EFFECT_DOUBLE_CLICK);

            // it is safe to cancel other vibrations currently taking place
            vibrator.cancel();

            vibrator.vibrate(vibrationEffect3);
        });

        // handle tick effect vibration button
        bTickVibration.setOnClickListener(v -> {
            final VibrationEffect vibrationEffect4;

            // this type of vibration requires API 29

            // create vibrator effect with the constant EFFECT_TICK
            vibrationEffect4 = VibrationEffect.createPredefined(VibrationEffect.EFFECT_TICK);

            // it is safe to cancel other vibrations currently taking place
            vibrator.cancel();

            vibrator.vibrate(vibrationEffect4);
        });

        // handle heavy click vibration button
        bHeavyClickVibration.setOnClickListener(v -> {
            final VibrationEffect vibrationEffect5;

            // this type of vibration requires API 29

            // create vibrator effect with the constant EFFECT_HEAVY_CLICK
            vibrationEffect5 = VibrationEffect.createPredefined(VibrationEffect.EFFECT_HEAVY_CLICK);

            // it is safe to cancel other vibrations currently taking place
            vibrator.cancel();

            vibrator.vibrate(vibrationEffect5);
        });
    }
}