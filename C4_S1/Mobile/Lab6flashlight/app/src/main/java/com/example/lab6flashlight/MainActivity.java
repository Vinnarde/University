package com.example.lab6flashlight;

import androidx.appcompat.app.AppCompatActivity;


import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.pm.PackageManager;
import android.hardware.camera2.CameraAccessException;
import android.hardware.camera2.CameraManager;
import android.media.MediaPlayer;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.Toast;


public class MainActivity extends AppCompatActivity {

    private CameraManager objCameraManager;
    private String mCameraId;
    private Button buttonOnOff;
    private Boolean isTorchOn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        buttonOnOff = (Button) findViewById(R.id.button);
        isTorchOn = false;
        boolean isFlashAvailable = getApplicationContext().getPackageManager().hasSystemFeature(PackageManager.FEATURE_CAMERA_FLASH);

        if (!isFlashAvailable) {
            Toast.makeText(MainActivity.this, "Flashlight is not available!", Toast.LENGTH_LONG).show();
        }

        objCameraManager = (CameraManager) getSystemService(Context.CAMERA_SERVICE);
        try {
            mCameraId = objCameraManager.getCameraIdList()[0];
        } catch (CameraAccessException e) {
            e.printStackTrace();
        }

        buttonOnOff.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    if (isTorchOn) {
                        turnOffLight();
                        isTorchOn = false;
                    } else {
                        turnOnLight();
                        isTorchOn = true;
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }

    /**
     * Method for turning light ON
     */
    public void turnOnLight() {

        try {
            View view = this.getWindow().getDecorView();
            view.setBackgroundColor(0xfff0f0f0);
            Toast.makeText(MainActivity.this, "Flashlight is turned on!", Toast.LENGTH_SHORT).show();
            objCameraManager.setTorchMode(mCameraId, true);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * Method for turning light OFF
     */
    public void turnOffLight() {

        try {
            View view = this.getWindow().getDecorView();
            view.setBackgroundColor(0xff404040);
            Toast.makeText(MainActivity.this, "Flashlight is turned off!", Toast.LENGTH_SHORT).show();
            objCameraManager.setTorchMode(mCameraId, false);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    protected void onStop() {
        super.onStop();
        if (isTorchOn) {
            turnOffLight();
        }
    }

    @Override
    protected void onPause() {
        super.onPause();
        if (isTorchOn) {
            turnOffLight();
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
        if (isTorchOn) {
            turnOnLight();
        }
    }
}