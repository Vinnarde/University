package com.labs;

import java.util.Scanner;

public class Chapter1 {

    public static void task1() {
        System.out.println("This is task #1 from Chapter 1!");
        System.out.println("Write a program that reads an integer and" +
                " prints it in binary, octal and hexadecimal.\n" +
                "Print the reciprocal as a hexadecimal floating-point number.");

        System.out.print("Enter integer number: ");
        var input = new Scanner(System.in);
        var value = input.nextInt();
        System.out.printf("Binary: %s\n", Integer.toBinaryString(value));
        System.out.printf("Octal: %o\n", value);
        System.out.printf("Hexadecimal: %x\n", value);

        var reciprocal = 1.0 / value;
        System.out.printf("Hexadecimal floating point: %a\n", reciprocal);
    }

    public static void task2() {
        System.out.println("This is task #2 from Chapter 1!");
        System.out.print("Enter integer number: ");
        var input = new Scanner(System.in);
        var angle = input.nextInt();

        System.out.printf("Mod %% 360 is %d\n", angle % 360);
        System.out.printf("Math.floorMod(angle, 360) is %d\n", Math.floorMod(angle, 360));
    }

    public static void task3() {
        System.out.println("This is task #3 from Chapter 1!");
        System.out.print("Enter three integers: ");
        var input = new Scanner(System.in);
        var a = input.nextInt();
        var b = input.nextInt();
        var c = input.nextInt();

        System.out.printf("Largest using ?: %d\n", (a >= b) ? ((a >= c) ? a : c) : ((b >= c) ? b : c));
        System.out.printf("Largest using Math.max: %d\n", Math.max(a, Math.max(b, c)));

    }

}
