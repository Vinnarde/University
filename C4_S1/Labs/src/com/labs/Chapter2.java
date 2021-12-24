package com.labs;

import java.time.DayOfWeek;
import java.time.LocalDate;
import java.util.LinkedHashMap;
import java.util.Map;

public class Chapter2 {
    public static void task1() {
        // getting today date
        var today = LocalDate.now();

        // Print calendar header of month & year
        System.out.println(today.getMonth().toString() + " " + today.getYear());

        var date = LocalDate.of(today.getYear(), today.getMonth(), 1);
        var order = buildDayAbbrev();

        // print the abbreviations for days of the week starting from Sunday.
        for (var abbrev : order.values()) {
            System.out.printf("%s\t", abbrev);
        }
        System.out.println();

        // Adjust printing position to accommodate Sunday start
        var pos = date.getDayOfWeek().getValue() == 7 ? 0 : date.getDayOfWeek().getValue();
        for (var i = 0; i < pos; i++) {
            System.out.print(" \t");
        }

        while (date.getMonthValue() == today.getMonthValue()) {
            var format = pos++ % 7 == 6 ? "%d\n" : "%d\t";
            System.out.printf(format, date.getDayOfMonth());
            date = date.plusDays(1);
        }
    }

    private static LinkedHashMap<DayOfWeek, String> buildDayAbbrev() {
        var result = new LinkedHashMap<DayOfWeek, String>(7);
        result.put(DayOfWeek.SUNDAY, "Sun");
        result.put(DayOfWeek.MONDAY, "Mon");
        result.put(DayOfWeek.TUESDAY, "Tue");
        result.put(DayOfWeek.WEDNESDAY, "Wed");
        result.put(DayOfWeek.THURSDAY, "Thu");
        result.put(DayOfWeek.FRIDAY, "Fri");
        result.put(DayOfWeek.SATURDAY, "Sat");
        return result;
    }

}
