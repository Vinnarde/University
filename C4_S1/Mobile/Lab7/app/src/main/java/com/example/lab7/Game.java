package com.example.lab7;

public class Game {
    int[][] a = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    int player = 1;

    public void set(int x, int y) {
        a[x][y] = player;
    }

    public int get(int x, int y) {
        return a[x][y];
    }


    public void changePLayer() {
        if (player == 1)
            player = 2;
        else
            player = 1;
    }

    public int getPlayer() {
        return player;
    }

    public int check() {
        int state = 0;

        if (a[0][0] != 0 && a[0][0] == a[0][1] && a[0][1] == a[0][2])
            state = 1;
        else if (a[1][0] != 0 && a[1][0] == a[1][1] && a[1][1] == a[1][2])
            state = 2;
        else if (a[2][0] != 0 && a[2][0] == a[2][1] && a[2][1] == a[2][2])
            state = 3;

        else if (a[0][0] != 0 && a[0][0] == a[1][0] && a[1][0] == a[2][0])
            state = 4;
        else if (a[0][1] != 0 && a[0][1] == a[1][1] && a[1][1] == a[2][1])
            state = 5;
        else if (a[0][2] != 0 && a[0][2] == a[1][2] && a[1][2] == a[2][2])
            state = 6;

        else if (a[0][0] != 0 && a[0][0] == a[1][1] && a[1][1] == a[2][2])
            state = 7;
        else if (a[0][2] != 0 && a[0][2] == a[1][1] && a[1][1] == a[2][0])
            state = 8;

        int result = 1;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result *= a[i][j];
            }
        }

        if (result != 0)
            state = 9; // draw

        return state;
    }
}