package com.evaluate;

import java.util.Scanner;

public class Dates {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        Validates data = new Validates();

        boolean exit = false;

        while (!exit) {

            System.out.println("\n==================================");
            System.out.println("             DATE MENU");
            System.out.println("==================================");
            System.out.println("1. Set Date");
            System.out.println("2. Add Days");
            System.out.println("3. Add Months");
            System.out.println("4. Add Years");
            System.out.println("5. Display");
            System.out.println("6. Exit");
            System.out.println("==================================");
            System.out.print("Enter your choice: ");

            int choice = sc.nextInt();

            switch (choice) {

                case 1:
                    data.setYear();
                    data.setMonth();
                    data.setDay();
                    break;

                case 2:
                    data.addDays();
                    break;

                case 3:
                    data.addMonths();
                    break;

                case 4:
                    data.addYears();
                    break;

                case 5:
                    data.display();
                    break;

                case 6:
                    exit = true;
                    System.out.println("Thank You..!");
                    break;

                default:
                    System.out.println("Invalid selection..!");
            }
        }

        sc.close();
    }
}