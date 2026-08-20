import java.util.Scanner;

class SwitchMenu {

    // Variables to demonstrate default values of primitive data types
    static byte byteValue;
    static short shortValue;
    static int intValue;
    static long longValue;
    static float floatValue;
    static double doubleValue;
    static char charValue;
    static boolean booleanValue;

    // 1. Grade Evaluation System
    static void GradeEvaluationSystem(Scanner sc) {

        System.out.println("===== GRADE EVALUATION SYSTEM =====");

        System.out.print("Enter marks in Mathematics: ");
        int maths = sc.nextInt();

        System.out.print("Enter marks in Science: ");
        int science = sc.nextInt();

        System.out.print("Enter marks in History: ");
        int history = sc.nextInt();

        if (maths < 0 || maths > 100 ||
            science < 0 || science > 100 ||
            history < 0 || history > 100) {

            System.out.println("Invalid marks! Marks must be between 0 and 100.");
            return;
        }

        int total = maths + science + history;
        double percentage = total / 3.0;

        char grade;

        if (percentage >= 90) {
            grade = 'A';
        } 
        else if (percentage >= 80) {
            grade = 'B';
        } 
        else if (percentage >= 70) {
            grade = 'C';
        } 
        else if (percentage >= 60) {
            grade = 'D';
        } 
        else if (percentage >= 50) {
            grade = 'E';
        } 
        else {
            grade = 'F';
        }

        System.out.println("\n----- RESULT -----");
        System.out.println("Mathematics : " + maths);
        System.out.println("Science     : " + science);
        System.out.println("History     : " + history);
        System.out.println("Total Marks : " + total + " / 300");
        System.out.println("Percentage  : " + percentage + "%");
        System.out.println("Grade       : " + grade);

        if (grade == 'F') {
            System.out.println("Result      : FAIL");
        } else {
            System.out.println("Result      : PASS");
        }
    }


    // 2. Leap Year Check
    static void LeapYearCheck(Scanner sc) {

        System.out.println("===== LEAP YEAR CHECK =====");

        System.out.print("Enter year: ");
        int year = sc.nextInt();

        if ((year % 4 == 0 && year % 100 != 0) ||
            (year % 400 == 0)) {

            System.out.println(year + " is a Leap Year.");
        } 
        else {
            System.out.println(year + " is NOT a Leap Year.");
        }
    }


    // 3. Day of Week
    static void DayOfWeek(Scanner sc) {

        System.out.println("===== DAY OF THE WEEK =====");

        System.out.print("Enter a number (1-7): ");
        int day = sc.nextInt();

        switch (day) {

            case 1:
                System.out.println("Day: Monday");
                break;

            case 2:
                System.out.println("Day: Tuesday");
                break;

            case 3:
                System.out.println("Day: Wednesday");
                break;

            case 4:
                System.out.println("Day: Thursday");
                break;

            case 5:
                System.out.println("Day: Friday");
                break;

            case 6:
                System.out.println("Day: Saturday");
                break;

            case 7:
                System.out.println("Day: Sunday");
                break;

            default:
                System.out.println("Invalid input! Please enter a number between 1 and 7.");
        }
    }


    // 4. Default Values of Variables
    static void DefaultValuesOfVariables() {

        System.out.println("===== DEFAULT VALUES OF PRIMITIVE DATA TYPES =====");

        System.out.println("byte    : " + byteValue);
        System.out.println("short   : " + shortValue);
        System.out.println("int     : " + intValue);
        System.out.println("long    : " + longValue);
        System.out.println("float   : " + floatValue);
        System.out.println("double  : " + doubleValue);

        System.out.println("char    : [" + charValue + "]");

        System.out.println("boolean : " + booleanValue);
    }


    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        int choice;

        do {

            System.out.println("\n======================================");
            System.out.println("       JAVA SERVICE MENU");
            System.out.println("======================================");

            System.out.println("1. Grade Evaluation System");
            System.out.println("2. Leap Year Check");
            System.out.println("3. Day of the Week");
            System.out.println("4. Default Values of Variables");
            System.out.println("5. Exit");

            System.out.print("\nEnter Your Choice: ");
            choice = sc.nextInt();

            System.out.println();

            switch (choice) {

                case 1:
                    GradeEvaluationSystem(sc);
                    break;

                case 2:
                    LeapYearCheck(sc);
                    break;

                case 3:
                    DayOfWeek(sc);
                    break;

                case 4:
                    DefaultValuesOfVariables();
                    break;

                case 5:
                    System.out.println("Thanks For Visiting Our Services..!");
                    break;

                default:
                    System.out.println("Invalid Choice! Please select 1-5.");
            }

        } while (choice != 5);

        sc.close();
    }
}
