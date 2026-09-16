package StringLiterals;

public class UpperCaseString {

    public static void main(String[] args) {

        String str = "The Quick BroWn FoX!";

        System.out.println("Original String: " + str);

        String upper = str.toUpperCase();

        System.out.println("String in uppercase: " + upper);
    }
}
