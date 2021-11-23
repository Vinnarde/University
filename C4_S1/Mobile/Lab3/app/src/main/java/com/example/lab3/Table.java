package com.example.lab3;

import java.io.Serializable;

public class Table implements Serializable {
    private int tableSize, legSize, betterPackage;
    private Color tableColor, legColor;

    public Color getTableColor() {
        return tableColor;
    }

    public void setTableColor(Color tableColor) {
        this.tableColor = tableColor;
    }

    public Color getLegColor() {
        return legColor;
    }

    public void setLegColor(Color legColor) {
        this.legColor = legColor;
    }

    public Table(int tableSize, int legSize, int betterPackage, Color tableColor, Color legColor) {
        this.tableSize = tableSize;
        this.legSize = legSize;
        this.betterPackage = betterPackage;
        this.tableColor = tableColor;
        this.legColor = legColor;
    }


    public int getTableSize() {
        return tableSize;
    }

    public void setTableSize(int tableSize) {
        this.tableSize = tableSize;
    }

    public int getLegSize() {
        return legSize;
    }

    public void setLegSize(int legSize) {
        this.legSize = legSize;
    }

    public int getBetterPackage() {
        return betterPackage;
    }

    public void setBetterPackage(int betterPackage) {
        this.betterPackage = betterPackage;
    }
}
