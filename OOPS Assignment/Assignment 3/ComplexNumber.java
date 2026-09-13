package ComplexNumber;

import java.util.Scanner;

class ComplexNumberDemo {

    private int number1;
    private int number2;

    // Getter for number1
    public int getNumber1() {
        return number1;
    }

    // Setter for number1
    public void setNumber1(int number1) {
        this.number1 = number1;
    }

    // Getter for number2
    public int getNumber2() {
        return number2;
    }

    // Setter for number2
    public void setNumber2(int number2) {
        this.number2 = number2;
    }

    // Multiply number1 and number2
    public int computeComplexNumber() {
        return number1 * number2;
    }
}

public class ComplexNumber {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        // Array of 5 ComplexNumber objects
        ComplexNumberDemo[] arr = new ComplexNumberDemo[5];

        // Take input for 5 objects
        for (int i = 0; i < 5; i++) {

            // Create object
            arr[i] = new ComplexNumberDemo();

            System.out.print("Enter number1 for object " + (i + 1) + ": ");
            int n1 = sc.nextInt();

            System.out.print("Enter number2 for object " + (i + 1) + ": ");
            int n2 = sc.nextInt();

            // Set values using setters
            arr[i].setNumber1(n1);
            arr[i].setNumber2(n2);
        }

        // Display result for each object
        System.out.println("\nResults:");

        for (int i = 0; i < 5; i++) {

            int result = arr[i].computeComplexNumber();

            System.out.println(
                "Object " + (i + 1) + " : " + result
            );
        }

        sc.close();
    }
}