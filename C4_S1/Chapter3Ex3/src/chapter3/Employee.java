package chapter3;

public class Employee implements Measurable{

    double salary;
    String name;

    public Employee(String name, double salary) {
        this.name = name;
        this.salary = salary;
    }

    @Override
    public double getMeasure() {
        return this.salary;
    }

    public String getName(){
        return name;
    }
}
