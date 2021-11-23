package com.example.lab_6_morze;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.media.AudioFormat;
import android.media.AudioManager;
import android.media.AudioTrack;
import android.os.Build;
import android.os.Bundle;
import android.os.VibrationEffect;
import android.view.View;
import android.widget.TextView;
import android.os.Vibrator;

import com.google.android.material.textfield.TextInputEditText;

import java.util.HashMap;
import java.util.Locale;


class MyException extends Exception {
    // default constructor
    MyException() {
    }

    // parameterized constructor
    MyException(String str) {
        super(str);
    }
}

public class MainActivity extends AppCompatActivity {

    HashMap<Character, String> alphabet = new HashMap<>();

    public void test(int durationMs) {
        final double duration = durationMs / 1000.0; // seconds
        final int sampleRate = 44100;
        final int numSamples = (int) (duration * sampleRate);
        final double[] sample = new double[numSamples];
        final double freqOfTone = 500; // hz

        final byte[] generatedSnd = new byte[2 * numSamples];

        // fill out the array
        for (int i = 0; i < numSamples; ++i) {
            sample[i] = Math.sin(2 * Math.PI * i / (sampleRate / freqOfTone));
        }

        // convert to 16 bit pcm sound array
        // assumes the sample buffer is normalised.
        int idx = 0;
        for (final double dVal : sample) {
            // scale to maximum amplitude
            final short val = (short) ((dVal * 32767));
            // in 16 bit wav PCM, first byte is the low order byte
            generatedSnd[idx++] = (byte) (val & 0x00ff);
            generatedSnd[idx++] = (byte) ((val & 0xff00) >>> 8);

        }

        final AudioTrack audioTrack = new AudioTrack(AudioManager.STREAM_MUSIC,
                sampleRate, AudioFormat.CHANNEL_OUT_MONO,
                AudioFormat.ENCODING_PCM_16BIT, generatedSnd.length,
                AudioTrack.MODE_STREAM);
        audioTrack.write(generatedSnd, 0, generatedSnd.length);
        audioTrack.play();
    }

    private void initializeAlphabet() {
        alphabet.put('A', ".-");
        alphabet.put('B', "-...");
        alphabet.put('C', "-.-.");
        alphabet.put('D', "-..");
        alphabet.put('E', ".");
        alphabet.put('F', "..-.");
        alphabet.put('G', "--.");
        alphabet.put('H', "....");
        alphabet.put('I', "..");
        alphabet.put('J', ".---");
        alphabet.put('K', "-.-");
        alphabet.put('L', ".-..");
        alphabet.put('M', "--");
        alphabet.put('N', "-.");
        alphabet.put('O', "---");
        alphabet.put('P', ".--.");
        alphabet.put('Q', "--.-");
        alphabet.put('R', ".-.");
        alphabet.put('S', "...");
        alphabet.put('T', "-");
        alphabet.put('U', "..-");
        alphabet.put('V', "...-");
        alphabet.put('W', ".--");
        alphabet.put('X', "-..-");
        alphabet.put('Y', "-.--");
        alphabet.put('Z', "--..");

        alphabet.put('0', "-----");
        alphabet.put('1', ".----");
        alphabet.put('2', "..---");
        alphabet.put('3', "...--");
        alphabet.put('4', "....-");
        alphabet.put('5', ".....");
        alphabet.put('6', "-....");
        alphabet.put('7', "--...");
        alphabet.put('8', "---..");
        alphabet.put('9', "----.");

        alphabet.put('.', ".-.-.-");
        alphabet.put(',', "--..--");
        alphabet.put('?', "..--..");
        alphabet.put('\'', ".----.");
        alphabet.put('!', "-.-.--");
        alphabet.put('/', "-..-.");
        alphabet.put('(', "-.--.");
        alphabet.put(')', "-.--.-");
        alphabet.put('&', ".-...");
        alphabet.put(':', "---...");
        alphabet.put(';', "-.-.-.");
        alphabet.put('=', "-...-");
        alphabet.put('+', ".-.-.");
        alphabet.put('-', "-....-");
        alphabet.put('_', "..--.-");
        alphabet.put('"', ".-..-.");
        alphabet.put('$', "...-..-");
        alphabet.put('@', ".--.-.");
    }

    private void messageBox(String message) {
        AlertDialog.Builder messageBox = new AlertDialog.Builder(this);
        messageBox.setMessage(message);
        messageBox.setCancelable(false);
        messageBox.setNeutralButton("OK", null);
        messageBox.show();
    }

    public void convertToMorseCode(View view) {

        try {

            TextInputEditText text = findViewById(R.id.inputText);
            TextView outputPlace = findViewById(R.id.textView);

            String sourceText = text.getText().toString();
            sourceText = sourceText.toUpperCase();

            StringBuilder output = new StringBuilder();

            for (Character ch : sourceText.toCharArray()) {

                if (alphabet.containsKey(ch))
                    output.append(alphabet.get(ch)).append(" ");
                else if (Character.isWhitespace(ch))
                    output.append("/");
                else
                    throw new MyException("Unknown symbol '" + ch + "'!");
            }

            outputPlace.setText(output.toString());

        } catch (Exception e) {
            messageBox(e.getMessage());
        }

    }

    public static void wait(int ms) {
        try {
            Thread.sleep(ms);
        } catch (InterruptedException ex) {
            Thread.currentThread().interrupt();
        }
    }

    public void playMorseCode(View view) {


        final int wordsPerMinute = 12;
        final int duration = 1200 / wordsPerMinute; // 12 wpm( for 50 dot)
        int[] durations = {
                duration,       // dot
                duration * 3,   // dash
                duration,       // between dot/dash
                duration * 3,   // between letters
                duration * 7    // between words
        };

        Vibrator v = (Vibrator) getSystemService(Context.VIBRATOR_SERVICE);
//        v.vibrate(VibrationEffect.createOneShot(500, VibrationEffect.DEFAULT_AMPLITUDE));
        if (!v.hasVibrator()) {
            messageBox("Couldn't load vibrator!");
        }

        TextView textView = findViewById(R.id.textView);
        String textToPlay = textView.getText().toString();

        for (
                Character ch : textToPlay.toCharArray()) {
            switch (ch) {
                case '.':
//                        v.vibrate(durations[0]);
                    test(durations[0]);
                    wait(durations[0]);
                    break;
                case '-':
//                        v.vibrate(durations[1]);
                    test(durations[1]);
                    wait(durations[1]);
                    break;
                case ' ':
                    wait(durations[3]);
                    break;
                case '/':
                    wait(durations[4]);
                    break;
            }

            wait(durations[2]);
        }

    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initializeAlphabet();
    }
}