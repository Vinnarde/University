package chapter3;

public class DriveCode {

    public static void main(String[] args) {
        Employee[] employees = new Employee[8];
        employees[0] = new Employee("John", 2500);
        employees[1] = new Employee("Peter", 2200);
        employees[2] = new Employee("Jack", 2800);
        employees[3] = new Employee("Anthony", 4500);
        employees[4] = new Employee("Ann", 2600);
        employees[5] = new Employee("Catrin", 2500);
        employees[6] = new Employee("Steven", 2700);
        employees[7] = new Employee("Vanessa", 3000);

        System.out.printf("The average salary of employees: %.2f\n", average(employees));
        System.out.printf("The employee with highest salary: %s\n", ((Employee)largest(employees)).getName());

    }

    public static double average(Measurable[] objects) {
        double average = 0.0;
        for (Measurable measurable : objects) {
            average += measurable.getMeasure();
        }
        return average / objects.length;
    }

    public static Measurable largest(Measurable[] objects) {
        Measurable largest = objects[0];

        for (int i = 1; i < objects.length; ++i) {
            if (objects[i].getMeasure() > largest.getMeasure()) {
                largest = objects[i];
            }
        }
        return largest;
    }
}
