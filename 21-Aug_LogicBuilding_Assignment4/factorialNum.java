import java.util.Scanner;

public class factorialNum{

	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);

		System.out.print("Enter a number: ");
		int num = sc.nextInt();
		int fact = 1;

		for (int i = num; i >= 1; i--){	
			fact *= i;
		}
		System.out.print("Factorial of " + num + " is " + fact);

	}

}