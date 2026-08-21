import java.util.Scanner;

public class ArrayString{

	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);

		String arr[] = new String[5];

		for (int i = 0; i < 5; i++){
		System.out.print("Enter " + (i+1) + " name: ");
			arr[i] = sc.nextLine();
		}
		System.out.print("-----------------")
		for(String i : arr){
			System.out.print(i + " ");
		}
	}

}