package com.Lambda;

import java.util.Arrays;
import java.util.function.Function;

public class IntegerLarg {

	public static void main(String[] args) {
		
		int[] numbers = {45, 12, 78, 23, 67, 91, 34};
		
		Function<int[], Integer> largest = arr -> {
			int max = arr[0];
			
			for (int i : arr) {
				if(i > max)
					max = i;
			}
			
			return max;
		};
		
		System.out.println("Largest number: " + largest.apply(numbers));
	}

}
