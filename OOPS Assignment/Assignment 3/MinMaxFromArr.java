package SortingArray;

public class MinMaxFromArr {
	
	public int[] MinMaxValues(int[] arr) {
		int temp[] = {arr[0], arr[0]};
		
		for(int i = 0; i < arr.length; i++) {
			if(temp[0] > arr[i]) {
				temp[0] = arr[i];
			}
			if(temp[1] < arr[i]) {
				temp[1] = arr[i];
			}
		}
		
		return temp;
	}

}
