package SortingArray;

public class CopyArray {
	
	public int[] copyArray(int[] arr) {
		int temp[] = new int[arr.length];
		for(int i = 0; i < arr.length; i++) {
			temp[i] = arr[i];
		}
		return temp;
	}

}
