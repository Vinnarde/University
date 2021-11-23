package com.labs;

import java.util.Objects;

public class Chapter4 {
    class Point {
        protected final double x, y;

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
        private final String label;

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

        public String getLabel() {
            return label;
        }
    }
}
