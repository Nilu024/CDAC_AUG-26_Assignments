import java.util.Scanner;

public class SortArray{

	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);

		int arr[] = new int[5];

		System.out.print("Enter 5 number: ");

		for (int i = 0; i < arr.length; i++){
			arr[i] = sc.nextInt();
		}

		  // Sorting
       		 for (int i = 0; i < arr.length - 1; i++) {

       		     for (int j = i + 1; j < arr.length; j++) {

      		          if (arr[i] > arr[j]) {

        	            int temp = arr[i];
         	           arr[i] = arr[j];
                	    arr[j] = temp;
                           }
            		 }
       		     }

		System.out.print("Sorted Array: ");

		for (int i : arr){
			System.out.print(i + " ");
		}
	}

}