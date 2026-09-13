package RectangleAssignment;

// Parent class
class Rectangle {

    private double length;
    private double breadth;

    // Parameterized constructor
    public Rectangle(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    // Method to calculate and print area
    public void printArea() {
        double area = length * breadth;
        System.out.println("Area: " + area);
    }

    // Method to calculate and print perimeter
    public void printPerimeter() {
        double perimeter = 2 * (length + breadth);
        System.out.println("Perimeter: " + perimeter);
    }
}


// Child class
class Square extends Rectangle {

    // Constructor
    public Square(double side) {
        super(side, side);
    }
}


// Main class
public class RectangleDemo {

    public static void main(String[] args) {

        // Rectangle object
        Rectangle rectangle = new Rectangle(10, 5);

        System.out.println("----- Rectangle -----");
        rectangle.printArea();
        rectangle.printPerimeter();

        // Square object
        Square square = new Square(5);

        System.out.println("\n----- Square -----");
        square.printArea();
        square.printPerimeter();
    }
}