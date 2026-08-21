import java.util.Scanner;

public class PositiveNegativeCount{

	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);

		int arr[] = new int[5];

		int positiveNum = 0;

		int negativeNum = 0;

		System.out.print("Enter 5 number: ");

		for (int i = 0; i < 5; i++){
			arr[i] = sc.nextInt();
		}

		for(int i : arr){
			if(i > 0){
				positiveNum++;
			} else{
				negativeNum++;
			}
		}

		System.out.println("Positive Numbers : " + positiveNum + "\nNegative Numbers : " + negativeNum);
	}

}