package com.labs;

import java.util.ArrayList;

public class Chapter7_2 {
    public static ArrayList<String> toUpperCaseIterator(ArrayList<String> strings) {
        for (var iterator = strings.listIterator(); iterator.hasNext(); ) {
            String next = iterator.next();
            String upper = next.toUpperCase();
            iterator.set(upper);
        }
        return strings;
    }

    public static ArrayList<String> toUpperCaseLoop(ArrayList<String> strings) {
        for (int i = 0; i < strings.size(); i++) {
            var next = strings.get(i);
            var upper = next.toUpperCase();
            strings.set(i, upper);
        }
        return strings;
    }

    public static ArrayList<String> toUpperCaseReplaceAll(ArrayList<String> strings) {
        strings.replaceAll(s -> s.toUpperCase());
        return strings;
    }

    public static void driveCode() {
        String test = "abcdefghijklmnopqrstuvwxyz";
        System.out.println("Source text: " + test);

//        System.out.println("Iterator: " + toUpperCaseIterator());

    }

}
