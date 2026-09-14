import java.io.*;
import java.util.*;

public class EmployeeManagement {

    static ArrayList<Employee> employees = new ArrayList<>();

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {

        int choice;

        do {
            System.out.println("\n===== Employee Management System =====");
            System.out.println("1. Add");
            System.out.println("2. Display");
            System.out.println("3. Delete");
            System.out.println("4. Sort");
            System.out.println("5. Save");
            System.out.println("6. Load");
            System.out.println("7. Exit");

            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch (choice) {

                case 1:
                    add();
                    break;

                case 2:
                    display();
                    break;

                case 3:
                    delete();
                    break;

                case 4:
                    sort();
                    break;

                case 5:
                    save();
                    break;

                case 6:
                    load();
                    break;

                case 7:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }

        } while (choice != 7);
    }

    // ADD
    static void add() {

        System.out.println("\n1. Manager");
        System.out.println("2. Engineer");
        System.out.println("3. Sales Person");
        System.out.println("4. Exit");

        System.out.print("Enter choice: ");
        int choice = sc.nextInt();

        if (choice == 4)
            return;

        System.out.print("Enter ID: ");
        int id = sc.nextInt();

        sc.nextLine();

        System.out.print("Enter Name: ");
        String name = sc.nextLine();

        System.out.print("Enter Address: ");
        String address = sc.nextLine();

        System.out.print("Enter Age: ");
        int age = sc.nextInt();

        sc.nextLine();

        System.out.print("Enter Gender: ");
        String gender = sc.nextLine();

        System.out.print("Enter Basic Salary: ");
        double basicSalary = sc.nextDouble();

        switch (choice) {

            case 1:

                System.out.print("Enter HRA: ");
                double hra = sc.nextDouble();

                employees.add(
                    new Manager(id, name, address, age,
                                gender, basicSalary, hra)
                );

                break;

            case 2:

                System.out.print("Enter Overtime: ");
                double overtime = sc.nextDouble();

                employees.add(
                    new Engineer(id, name, address, age,
                                 gender, basicSalary, overtime)
                );

                break;

            case 3:

                System.out.print("Enter Commission: ");
                double commission = sc.nextDouble();

                employees.add(
                    new SalesPerson(id, name, address, age,
                                    gender, basicSalary, commission)
                );

                break;

            default:
                System.out.println("Invalid choice!");
                return;
        }

        System.out.println("Employee added successfully.");
    }

    // DISPLAY
    static void display() {

        if (employees.isEmpty()) {
            System.out.println("No employees available.");
            return;
        }

        for (Employee e : employees) {

            System.out.println("\n--------------------------");

            e.display();

            System.out.println("--------------------------");
        }
    }

    // DELETE
    static void delete() {

        System.out.print("Enter employee ID to delete: ");
        int id = sc.nextInt();

        boolean found = false;

        Iterator<Employee> iterator = employees.iterator();

        while (iterator.hasNext()) {

            Employee e = iterator.next();

            if (e.getId() == id) {

                iterator.remove();

                found = true;

                System.out.println("Employee deleted.");
                break;
            }
        }

        if (!found) {
            System.out.println("Employee not found.");
        }
    }

    // SORT
    static void sort() {

        System.out.println("\na. By Name Ascending");
        System.out.println("b. By Name Descending");
        System.out.println("c. By Designation");
        System.out.println("d. Exit");

        System.out.print("Enter choice: ");
        char choice = sc.next().charAt(0);

        switch (choice) {

            case 'a':

                employees.sort(
                    Comparator.comparing(Employee::getName)
                );

                System.out.println("Sorted by name ascending.");
                break;

            case 'b':

                employees.sort(
                    Comparator.comparing(Employee::getName)
                              .reversed()
                );

                System.out.println("Sorted by name descending.");
                break;

            case 'c':

                System.out.println("By Designation not implemented.");
                break;

            case 'd':
                return;

            default:
                System.out.println("Invalid choice!");
        }
    }

    // SAVE
    static void save() {

        try {

            ObjectOutputStream out =
                new ObjectOutputStream(
                    new FileOutputStream("employees.dat")
                );

            out.writeObject(employees);

            out.close();

            System.out.println("Data saved successfully.");

        } catch (IOException e) {

            System.out.println("Error while saving data.");
        }
    }

    // LOAD
    @SuppressWarnings("unchecked")
    static void load() {

        try {

            ObjectInputStream in =
                new ObjectInputStream(
                    new FileInputStream("employees.dat")
                );

            employees =
                (ArrayList<Employee>) in.readObject();

            in.close();

            System.out.println("Data loaded successfully.");

        } catch (IOException | ClassNotFoundException e) {

            System.out.println("Error while loading data.");
        }
    }
}