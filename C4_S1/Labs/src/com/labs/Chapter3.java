package com.labs;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Comparator;
import java.util.OptionalDouble;

public class Chapter3 {
    interface Measurable {
        double getMeasure();

        static double average(Measurable[] measures) {
            double sum = 0.0;
            for (Measurable measurable : measures) {
                sum += measurable.getMeasure();
            }
            return sum / measures.length;
        }

        static Measurable largest(Measurable[] measures) {
            Measurable largest = measures[0];
            for (Measurable measurable : measures) {
                if (measurable.getMeasure() > largest.getMeasure()) {
                    largest = measurable;
                }
            }
            return largest;
        }
    }

    public static class Employee implements Measurable {
        private final double salary;
        private final String name;

        public Employee(String name, double salary) {
            this.name = name;
            this.salary = salary;
        }

        @Override
        public double getMeasure() {
            return this.salary;
        }

        public String getName() {
            return name;
        }


        public static String getLargest(Employee[] employees) {
            Measurable largest = Measurable.largest(employees);
            Employee largestEmployee = (Employee) largest;

            return largestEmployee.getName();
        }
    }

    public static void task1() {
        Employee[] employees = new Employee[8];
        employees[0] = new Employee("John", 2500);
        employees[1] = new Employee("Peter", 2200);
        employees[2] = new Employee("Jack", 2800);
        employees[3] = new Employee("Anthony", 4500);
        employees[4] = new Employee("Ann", 2600);
        employees[5] = new Employee("Catrin", 2500);
        employees[6] = new Employee("Steven", 2700);
        employees[7] = new Employee("Vanessa", 3000);

        // 22800.0/8 = 2850

        System.out.printf("Average salary: %.2f\n", Measurable.average(employees));
        System.out.printf("Employee with largest salary: %s\n", Employee.getLargest(employees));
    }

    public static void task2() {
        var anonymous = IntSequence.of(1, 2, 3, 4, 5, 10);

        while (anonymous.hasNext())
            System.out.printf(anonymous.next() + " ");
    }


    public interface IntSequence {

        boolean hasNext();

        int next();

        static IntSequence of(int... values) {
            return new IntSequence() {
                int index = 0;

                @Override
                public int next() {
                    return hasNext() ? values[index++] : 0;
                }

                @Override
                public boolean hasNext() {
                    return index < values.length;
                }
            };
        }
    }

}
