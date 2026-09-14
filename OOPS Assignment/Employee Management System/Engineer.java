public class Engineer extends Employee {

    private double overtime;

    public Engineer(int id, String name, String address,
                    int age, String gender, double basicSalary,
                    double overtime) {

        super(id, name, address, age, gender, basicSalary);
        this.overtime = overtime;
    }

    @Override
    public double calculateSalary() {
        return getBasicSalary() + overtime;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Overtime     : " + overtime);
        System.out.println("Total Salary : " + calculateSalary());
    }
}