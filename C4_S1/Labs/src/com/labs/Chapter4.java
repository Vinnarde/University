package com.labs;

import java.util.Objects;

public class Chapter4 {
    static public void task() {
        Point a = new Point(1, 2);
        Point b = new Point(1, 2);
        System.out.println(a);
        System.out.println(a.equals(b));
        System.out.printf("Point a hashCode: %d\n", a.hashCode());

        LabeledPoint c = new LabeledPoint(1, 2, "c");
        LabeledPoint d = new LabeledPoint(1, 2, "c1");
        System.out.println(c);
        System.out.printf("LabeledPoint d hashCode: %d\n", d.hashCode());
        d.showXAndY();
        System.out.println(c.equals(d));

        System.out.println(a.equals(c));

        a.x = 5;
    }
}

class Point {
    protected double x, y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Point point = (Point) o;
        return Double.compare(point.x, x) == 0 && Double.compare(point.y, y) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }

    @Override
    public String toString() {
        return "Point{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }
}

class LabeledPoint extends Point {
    private String label;

    public LabeledPoint(double x, double y, String label) {
        super(x, y);
        this.label = label;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        if (!super.equals(o)) return false;
        LabeledPoint that = (LabeledPoint) o;
        return Objects.equals(label, that.label);
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), label);
    }

    @Override
    public String toString() {
        return "LabeledPoint{" +
                "x=" + this.getX() +
                ", y=" + this.getY() +
                ", label='" + label + '\'' +
                '}';
    }

    //test if I can get access to x and y
    public void showXAndY() {
        System.out.println("x=" + x + ",y=" + y);
    }

    public String getLabel() {
        return label;
    }
}



