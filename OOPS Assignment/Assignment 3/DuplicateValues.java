package SortingArray;

public class DuplicateValues {
	
	public int[] duplicateValues (int[] arr) {
		int temp[] = new int[arr.length];
		int k = 0;
		for(int i = 0; i < arr.length; i++) {
			for(int j = (i+1); j < arr.length; j++) {
				if(arr[i] == arr[j]) {
					temp[k] = arr[i];
					k++;
					break;
				}
			}
		}
		
		
		return temp;
	}

}
