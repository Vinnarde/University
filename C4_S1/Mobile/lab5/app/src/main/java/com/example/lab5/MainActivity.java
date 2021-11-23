package com.example.lab5;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Dialog;
import android.content.res.Resources;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.CheckBox;
import android.widget.ImageView;
import android.widget.Spinner;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {
    static String[] countries = {"Russia", "United Kingdom", "USA", "Japan", "China"};
    static String[] descriptions = {"The United States of America (U.S.A. or USA), commonly known as the United States (U.S. or US) or America, is a country primarily located in North America. It consists of 50 states, a federal district, five major unincorporated territories, 326 Indian reservations, and some minor possessions. At 3.8 million square miles (9.8 million square kilometers), it is the world's third- or fourth-largest country by total area. The United States shares significant land borders with Canada to the north and Mexico to the south as well as limited maritime borders with the Bahamas, Cuba, and Russia. With a population of more than 331 million people, it is the third most populous country in the world. The national capital is Washington, D.C., and the most populous city is New York City.",
            "The United Kingdom of Great Britain and Northern Ireland, commonly known as the United Kingdom (UK) or Britain, is a sovereign country in north-western Europe, off the north-western coast of the European mainland. The United Kingdom includes the island of Great Britain, the north-eastern part of the island of Ireland, and many smaller islands within the British Isles. Northern Ireland shares a land border with the Republic of Ireland. Otherwise, the United Kingdom is surrounded by the Atlantic Ocean, with the North Sea to the east, the English Channel to the south and the Celtic Sea to the south-west, giving it the 12th-longest coastline in the world. The Irish Sea separates Great Britain and Ireland. The total area of the United Kingdom is 242,500 square kilometres (93,628 sq mi), with an estimated population in 2020 of 68 million.",
            "Japan is an island country in East Asia, located in the northwest Pacific Ocean. It is bordered on the west by the Sea of Japan, and extends from the Sea of Okhotsk in the north toward the East China Sea and Taiwan in the south. Part of the Ring of Fire, Japan spans an archipelago of 6852 islands covering 377,975 square kilometers (145,937 sq mi); the five main islands are Hokkaido, Honshu, Shikoku, Kyushu, and Okinawa. Tokyo is Japan's capital and largest city; other major cities include Yokohama, Osaka, Nagoya, Sapporo, Fukuoka, Kobe, and Kyoto. Japan is the eleventh-most populous country in the world, as well as one of the most densely populated and urbanized. About three-fourths of the country's terrain is mountainous, concentrating its population of 125.36 million on narrow coastal plains. Japan is divided into 47 administrative prefectures and eight traditional regions. The Greater Tokyo Area is the most populous metropolitan area in the world, with more than 37.4 million residents.",
            "China, officially the People's Republic of China, is a country in East Asia. It is the world's most populous country, with a population of more than 1.4 billion. China spans five geographical time zones and borders 14 different countries, the second most of any country in the world after Russia. Covering an area of approximately 9.6 million square kilometres (3.7 million mi2), it is the world's third or fourth largest country. The country is administratively divided into 23 provinces, five autonomous regions, four direct-controlled municipalities (Beijing – capital city, Chongqing, Shanghai – largest city and Tianjin), and two special administrative regions (Hong Kong and Macau).",
            "Russia, or the Russian Federation, is a transcontinental country spanning Eastern Europe and Northern Asia. It is the largest country in the world by area, covering over 17 million square kilometres (6.6×106 sq mi), and encompassing more than one-eighth of Earth's inhabited land area. Russia extends across eleven time zones, and has the most borders of any country in the world, with sixteen sovereign nations. It has a population of 146.2 million; and is the most populous country in Europe, and the ninth-most populous country in the world. Moscow, the capital, is the largest city in Europe, while Saint Petersburg is the nation's second-largest city and cultural centre. Russians are the largest Slavic and European nation; they speak Russian, the most spoken Slavic language, and the most spoken native language in Europe."};

    static int currentTheme = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {



        super.onCreate(savedInstanceState);

        switch(currentTheme)
        {
            case 1:
                MainActivity.this.setTheme(R.style.theme1);
                break;
            case 2:
                MainActivity.this.setTheme(R.style.theme2);
                break;
            default:
                MainActivity.this.setTheme(R.style.theme1);
        }
        setContentView(R.layout.activity_main);



        TextView selection = findViewById(R.id.textView);
        Spinner spinner = findViewById(R.id.spinner);

        ArrayAdapter<String> adapter = new ArrayAdapter<>(this, android.R.layout.simple_spinner_item, countries);

        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);

        spinner.setAdapter(adapter);


        AdapterView.OnItemSelectedListener itemSelectedListener = new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                String item = (String) parent.getItemAtPosition(position);
                selection.setText(item);

                ImageView imageView = findViewById(R.id.imageView);
                TextView textView = findViewById(R.id.textView);
                switch (position) {
                    case 1:
                        imageView.setImageResource(R.drawable.uk);
                        textView.setText(descriptions[1]);
                        break;
                    case 2:
                        imageView.setImageResource(R.drawable.usa);
                        textView.setText(descriptions[0]);
                        break;
                    case 3:
                        imageView.setImageResource(R.drawable.japan);
                        textView.setText(descriptions[2]);

                        break;
                    case 4:
                        imageView.setImageResource(R.drawable.china);
                        textView.setText(descriptions[3]);

                        break;
                    default:
                        imageView.setImageResource(R.drawable.russia);
                        textView.setText(descriptions[4]);

                        break;

                }
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {

            }
        };
        spinner.setOnItemSelectedListener(itemSelectedListener);
    }

    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.mymenu, menu);
        return true;
    }

    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();

        switch (id) {
            case R.id.s1:
//                MainActivity.this.setTheme(R.style.theme1);
                currentTheme = 1;
                MainActivity.this.recreate();
                return true;
            case R.id.s2:
//                MainActivity.this.setTheme(R.style.theme2);
                currentTheme = 2;
                MainActivity.this.recreate();
                return true;
            case R.id.vis:
                TextView selection = findViewById(R.id.textView);

                item.setChecked(!item.isChecked());

                if (selection.getVisibility() == View.VISIBLE)
                    selection.setVisibility(View.INVISIBLE);
                else
                    selection.setVisibility(View.VISIBLE);
//                CheckBox checkBox = findViewById(R.id.vis);
//
//                if (checkBox.isChecked())
//                    selection.setVisibility(View.VISIBLE);
//                else
//                    selection.setVisibility(View.INVISIBLE);

                Dialog dialog = new Dialog(MainActivity.this);
                dialog.setTitle("View changed!\n");
                dialog.setContentView(R.layout.dialog);
                dialog.show();

                return true;
        }

        return super.onOptionsItemSelected(item);
    }
}

