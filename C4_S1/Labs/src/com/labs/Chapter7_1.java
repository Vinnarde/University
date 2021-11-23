package com.labs;

import java.util.*;

public class Chapter7_1 {
    public static List<Integer> sieveOfEratosthenesHashSet(int n) {
        if (n < 2) {
            throw new IllegalArgumentException("Value of n must be greater than 2");
        }

        var numbers = new HashSet<Integer>(n);
        for (int i = 2; i <= n; ++i) {
            numbers.add(i);
        }

        for (int i = 2; i <= Math.sqrt(n); ++i) {
            if (numbers.contains(i)) {
                for (int j = i * i; j <= n; j += i) {
                    numbers.remove(j);
                }
            }
        }

        return new ArrayList<>(numbers);
    }

    public static List<Integer> sieveOfEratosthenesBitSet(int n) {
        if (n < 2) {
            throw new IllegalArgumentException("Value of n must be greater than 2.");
        }

        var numbers = new BitSet(n);

        for (int i = 2; i <= n; ++i) {
            numbers.set(i);
        }
        for (int i = 2; i <= Math.sqrt(n); ++i) {
            if (numbers.get(i)) {
                for (int j = i * i; j <= n; j += i) {
                    numbers.clear(j);
                }
            }
        }
        var result = new ArrayList<Integer>(numbers.cardinality());
        var i = numbers.nextSetBit(0);
        while (i + 1 > 0) {
            result.add(i);
            i = numbers.nextSetBit(i + 1);
        }
        return result;
    }

    public static void driveCode() {
        System.out.println("Enter n: ");
        var input = new Scanner(System.in);
        var n = input.nextInt();
        var result = Chapter7_1.sieveOfEratosthenesHashSet(n);

        System.out.println("Hash set variant:");
        result.stream().forEach(System.out::println);

        result = Chapter7_1.sieveOfEratosthenesBitSet(n);
        System.out.println("Bit set variant:");
        result.stream().forEach(System.out::println);
    }
}
