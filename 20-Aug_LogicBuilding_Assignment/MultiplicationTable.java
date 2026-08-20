import java.util.Scanner;

public class MultiplicationTable{

	static int printMultiplicationTable(int a){
		for(int i = 1; i <= 10; i++){
			System.out.println(a + " * " + i + " = " + (a*i) + " ");	
		}
		return a;
	}

	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);

		System.out.println("Multiplication Table");
		System.out.println("===================");

		System.out.println();
		System.out.print("Enter Any Number: ");
		int num = sc.nextInt();

		printMultiplicationTable(num);

		

	}

}