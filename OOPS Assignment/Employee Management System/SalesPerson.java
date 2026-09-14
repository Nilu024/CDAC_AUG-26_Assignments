public class SalesPerson extends Employee {

    private double commission;

    public SalesPerson(int id, String name, String address,
                       int age, String gender, double basicSalary,
                       double commission) {

        super(id, name, address, age, gender, basicSalary);
        this.commission = commission;
    }

    @Override
    public double calculateSalary() {
        return getBasicSalary() + commission;
    }

    @Override
    public void display() {
        super.display();
        System.out.println("Commission   : " + commission);
        System.out.println("Total Salary : " + calculateSalary());
    }
}