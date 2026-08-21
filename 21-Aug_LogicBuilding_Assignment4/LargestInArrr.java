import java.util.Scanner;

public class LargestInArrr{

	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);

		int arr[] = new int[5];

		System.out.print("Enter 5 number: ");

		for (int i = 0; i < arr.length; i++){
			arr[i] = sc.nextInt();
		}

		int result = arr[0];
		for(int i = 0; i < arr.length; i++){
			if(result < arr[i]){ result = arr[i];}
		}
		System.out.print("Largest number is: " + result);

	}

}