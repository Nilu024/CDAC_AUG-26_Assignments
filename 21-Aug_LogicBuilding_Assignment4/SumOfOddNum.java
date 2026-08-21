import java.util.Scanner;

public class SumOfOddNum{

	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);

		System.out.print("Enter a number: ");
		int num = sc.nextInt();
		int result = 0;

		for (int i = 1; i <= num; i++){
			if(i%2 != 0){
				result += i;
			}
		}
		System.out.print("The sum of odd numbers from 1 to " + num + " is " + result);

	}

}