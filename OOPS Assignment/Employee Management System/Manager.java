public class Manager extends Employee {

    private double hra;

    public Manager(int id, String name, String address,
                   int age, String gender, double basicSalary,
                   double hra) {

        super(id, name, address, age, gender, basicSalary);
        this.hra = hra;
    }

    @Override
    public double calculateSalary() {
        return getBasicSalary() + hra;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("HRA          : " + hra);
        System.out.println("Total Salary : " + calculateSalary());
    }
}