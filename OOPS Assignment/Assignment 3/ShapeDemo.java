package ShapeAssignment;

// Parent class
class Shape {

    public void printShape() {
        System.out.println("This is shape");
    }
}


// Child of Shape
class Rectangle extends Shape {

    public void printRectangle() {
        System.out.println("This is rectangular shape");
    }
}


// Child of Shape
class Circle extends Shape {

    public void printCircle() {
        System.out.println("This is circular shape");
    }
}


// Child of Rectangle
class Square extends Rectangle {

    public void printSquare() {
        System.out.println("Square is a rectangle");
    }
}


// Main class
public class ShapeDemo {

    public static void main(String[] args) {

        // Square object
        Square square = new Square();

        // Calling Shape class method
        square.printShape();

        // Calling Rectangle class method
        square.printRectangle();

        // Calling Square class method
        square.printSquare();
    }
}