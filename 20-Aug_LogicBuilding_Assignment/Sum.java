import java.util.Scanner;

public class Sum{

	static int calculateSum(int a){
		int sum = 0;
		for(int i = 0; i<= a; i++){
			sum += i;
		}
		return sum;
	}

	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);
	
		System.out.println("Calculate Sum");
		System.out.println("--------------------------------");

		System.out.println("Enter a Number: ");
		int a = sc.nextInt();
		
		System.out.println("The sum of numbers from 1 to " + a + " is: " + calculateSum(a));

	}
}