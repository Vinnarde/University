package com.example.lab7mushroomers;

import java.util.Random;

public class Game {

    // 0 = nothing = 25%
    // 1 = dubovik = 30%
    // 2 = opyata  = 20%
    // 3 = shoe    = 10%
    // 4 = capcan  = 10%
    // 5 = 10mushr = 5%


    int[][] map = new int[4][8];
    int[][] capsMap = new int[4][8];

    public int getScore() {
        return score;
    }

    public void setScore(int score) {
        this.score += score;
    }

    public int getAttempts() {
        return attempts;
    }

    public void setAttempts(int attempts) {
        this.attempts += attempts;
    }

    public boolean isRun() {
        return run;
    }

    public void setRun(boolean run) {
        this.run = run;
    }

    private int score = 0;
    private int attempts = 10;
    private boolean run = true;


    Game() {
        reset();
    }




    public void reset() {
        score = 0;
        attempts = 10;
        generateMap();
        generateCaps();
        run = true;
    }

    public void set(int x, int y) {
        map[x][y] = -1;
    }

    public int get(int x, int y) {
        return map[x][y];
    }

    public void setChecked(int x, int y) {
        capsMap[x][y] = 0;
    }

    public int getChecked(int x, int y) {
        return capsMap[x][y];
    }

    public void generateCaps() {
        Random random = new Random();

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 8; ++j) {
                capsMap[i][j] = random.nextInt(3) + 1;
            }
        }
    }

    public void generateMap() {

        // 0 = nothing = 25%
        // 1 = dubovik = 25%
        // 2 = opyata  = 20%
        // 3 = shoe    = 10%
        // 4 = capcan  = 10%
        // 5 = 10mushr = 10%

        Random random = new Random();

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 8; ++j) {

                int value = random.nextInt(100);

                if (value < 25)
                    map[i][j] = 0;
                else if (value < 50)
                    map[i][j] = 1;
                else if (value < 70)
                    map[i][j] = 2;
                else if (value < 80)
                    map[i][j] = 3;
                else if (value < 90)
                    map[i][j] = 4;
                else
                    map[i][j] = 5;
            }
        }
    }

}
