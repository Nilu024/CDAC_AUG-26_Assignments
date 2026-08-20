import java.util.Scanner;

public class askForPositiveNumber{

	public static void main(String args[]){
	
		Scanner sc = new Scanner(System.in);
		int a;

		do{
				System.out.print("Enter a positive number: ");
				a = sc.nextInt();
		}while(a < 1);

		System.out.println("======");	
		System.out.println("You Entered The Positive Number: " + a);
		System.out.println("======");

		sc.close();

	}
}