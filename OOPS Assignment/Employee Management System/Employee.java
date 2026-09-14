import java.io.Serializable;

public abstract class Employee implements Serializable {

    private int id;
    private String name;
    private String address;
    private int age;
    private String gender;
    private double basicSalary;

    public Employee(int id, String name, String address,
                    int age, String gender, double basicSalary) {

        this.id = id;
        this.name = name;
        this.address = address;
        this.age = age;
        this.gender = gender;
        this.basicSalary = basicSalary;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public double getBasicSalary() {
        return basicSalary;
    }

    public abstract double calculateSalary();

    public void display() {
        System.out.println("ID           : " + id);
        System.out.println("Name         : " + name);
        System.out.println("Address      : " + address);
        System.out.println("Age          : " + age);
        System.out.println("Gender       : " + gender);
        System.out.println("Basic Salary : " + basicSalary);
    }
}