import java.util.Scanner;
import java.util.Arrays;

public class ArrayContains {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        Integer arr[] = new Integer[5];

        System.out.print("Enter 5 integers: ");

        for (int i = 0; i < arr.length; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.print("Enter the number to search: ");
        int search = sc.nextInt();

        if (Arrays.asList(arr).contains(search)) {
            System.out.println("Found");
        } else {
            System.out.println("Not Found");
        }
    }
}