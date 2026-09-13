import java.util.Scanner;

// Parent class
class Member {

    // Data members
    private String name;
    private int age;
    private String phoneNumber;
    private String address;
    private double salary;

    // Getters and Setters

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    // Method to print salary
    public void printSalary() {
        System.out.println("Salary: " + salary);
    }
}


// Child class
class PrimeMembers extends Member {

    private int joiningYear;
    private double joiningFees;
    private boolean isActive;

    // Getters and Setters

    public int getJoiningYear() {
        return joiningYear;
    }

    public void setJoiningYear(int joiningYear) {
        this.joiningYear = joiningYear;
    }

    public double getJoiningFees() {
        return joiningFees;
    }

    public void setJoiningFees(double joiningFees) {
        this.joiningFees = joiningFees;
    }

    public boolean isActive() {
        return isActive;
    }

    public void setActive(boolean active) {
        isActive = active;
    }

    // Display all details
    public void display() {

        // Parent class fields
        System.out.println("Name: " + getName());
        System.out.println("Age: " + getAge());
        System.out.println("Phone Number: " + getPhoneNumber());
        System.out.println("Address: " + getAddress());
        System.out.println("Salary: " + getSalary());

        // Child class fields
        System.out.println("Joining Year: " + getJoiningYear());
        System.out.println("Joining Fees: " + getJoiningFees());
        System.out.println("Is Active: " + isActive());
    }
}


// Main class
public class MemberDemo {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // Create object of PrimeMembers
        PrimeMembers member = new PrimeMembers();

        // Input
        System.out.print("Enter Name: ");
        member.setName(sc.nextLine());

        System.out.print("Enter Age: ");
        member.setAge(sc.nextInt());

        sc.nextLine(); // consume newline

        System.out.print("Enter Phone Number: ");
        member.setPhoneNumber(sc.nextLine());

        System.out.print("Enter Address: ");
        member.setAddress(sc.nextLine());

        System.out.print("Enter Salary: ");
        member.setSalary(sc.nextDouble());

        System.out.print("Enter Joining Year: ");
        member.setJoiningYear(sc.nextInt());

        System.out.print("Enter Joining Fees: ");
        member.setJoiningFees(sc.nextDouble());

        System.out.print("Is Active (true/false): ");
        member.setActive(sc.nextBoolean());

        // Display
        System.out.println("\n----- Member Details -----");

        member.display();

        System.out.println("\n----- Salary -----");
        member.printSalary();

        sc.close();
    }
}