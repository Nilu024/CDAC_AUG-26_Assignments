import java.util.Scanner;

public class ArrayNumAvg{

	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);

		int arr[] = new int[5];

		int result = 0;

		System.out.print("Enter 5 number: ");

		for (int i = 0; i < 5; i++){
			arr[i] = sc.nextInt();
		}

		for(int i : arr){
			result += i;
		}

		result = result / arr.length;

		System.out.println("Result : " + result);
	}

}