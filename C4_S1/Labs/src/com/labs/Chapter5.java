package com.labs;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Locale;
import java.util.Scanner;

public class Chapter5 {
    public static ArrayList<Double> readValues(String filename) throws FileNotFoundException {
        if (filename == null || filename.isEmpty()) {
            throw new IllegalArgumentException("invalid filename");
        }

        filename = "inputs/" + filename;

        var result = new ArrayList<Double>();
        var input = new Scanner(new File(filename));

        input.useLocale(Locale.ENGLISH);

        while(input.hasNext()) {
            if (input.hasNextDouble()){
                result.add(input.nextDouble());
            }
            else
                throw new IllegalArgumentException("Invalid data: " + input.next());
        }

        return result;
    }

    public static double sumOfValues(String filename) throws FileNotFoundException {
        var data = Chapter5.readValues(filename);
        var result = 0.0;
        for (var d : data)
            result += d;

        return result;
    }

    public static void task3() {
        System.out.println("Enter filename with double numbers: ");
        var input = new Scanner(System.in);
        var filename = input.next();
        try {
            System.out.println(Chapter5.sumOfValues(filename));
        } catch (FileNotFoundException e) {
            System.err.println(String.format("File \"%s\" could not be found.\n", filename) + e.getMessage());
        }
        catch (IllegalArgumentException e) {
            System.err.println(e.getMessage());
        }
    }
}
