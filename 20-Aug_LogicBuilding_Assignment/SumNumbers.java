import java.util.Scanner;

public class SumNumbers{

	static int sumOfTwoNumbers(int a, int b){
		a = a + b;
		return a;
	}

	public static void main(String args[]){

	Scanner sc = new Scanner(System.in);

	System.out.print("Enter First Number: ");
	int x = sc.nextInt();
	System.out.print("Enter First Number: ");
	int y = sc.nextInt();

	System.out.println("---------------------");
	System.out.println("Sum Of Two Numbers: " + sumOfTwoNumbers(x,y));
	System.out.println("---------------------");

	}
}
