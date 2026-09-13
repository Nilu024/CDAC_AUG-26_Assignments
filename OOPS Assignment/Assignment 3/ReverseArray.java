package SortingArray;

public class ReverseArray {
	
	public int[] reverseArray(int[] arr) {
		int temp[] = new int[arr.length];
		for(int i = 0; i < arr.length; i++) {
			temp[i] = arr[arr.length - i - 1];
		}
		
		return temp;
	}

}
